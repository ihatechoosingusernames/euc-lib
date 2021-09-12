#include "euchandler.h"

#include <functional>

#include "logging.h"

EucHandler::EucHandler() {}

EucHandler::~EucHandler() {
  end();
}

void EucHandler::begin() {
  ble_handler = new BleHandler(std::bind(&EucHandler::onFoundWheel, this, std::placeholders::_1),
    std::bind(&EucHandler::onProcessInput, this, std::placeholders::_1, std::placeholders::_2));
  
  pthread_create(&update_task, NULL, EucHandler::onUpdate, (void*)this);
}

void EucHandler::end() {
  is_running = false;
  delete ble_handler;
  if (isConnected()) {
    delete connected_euc;
    connected_euc = nullptr;
  }
}

bool EucHandler::isConnected() {
  return (connected_euc != nullptr) && ble_handler->isConnected();
}

Euc EucHandler::getEuc() {
  if (isConnected())
    return *connected_euc;
  return new Euc();
}

void EucHandler::onProcessInput(uint8_t* data, size_t data_size) {
  if (isConnected()) {
    connected_euc->ProcessInput(data, data_size);  // Let the specific wheel implementation process the data
  }
}

// Creates the correct type of wheel object
void EucHandler::onFoundWheel(EucType type) {
  LOG_DEBUG_ARGS("Found %s EUC", kBrandName[(size_t)type]);

  switch (type) {
    case euc::EucType::kGotway:
      connected_euc = new euc::Gotway();
      break;
    case euc::EucType::kKingsong:
      connected_euc = new euc::Kingsong();
      break;
    default:
      LOG_DEBUG("Wheel not yet implemented, uh oh!");
  }
}

// This is the periodic update to handle connection and reconnection to lost devices
void* EucHandler::onUpdate(void* in) {
  if (!is_running) {
    vTaskDelete(NULL);  // Stop this thread from running when end() is called
    return NULL;
  }

  EucHandler* euc_handler = ((EucHandler*)in);
  euc_handler->ble_handler->Update();

  if (!euc_handler->ble_handler->isConnected() && !euc_handler->ble_handler->isConnecting())
    euc_handler->ble_handler->Scan();
  
  vTaskDelay(100 / portTICK_PERIOD_MS); // Wait for 100 ms
}
