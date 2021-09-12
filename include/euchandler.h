#ifndef EUCHANDLER_H_
#define EUCHANDLER_H_

#include "euc.h"

#include <pthread.h>

#include "blehandler.h"
#include "constants.h"

class EucHandler {
  public:
    EucHandler();
    ~EucHandler();

    void begin();
    void end();

    bool isConnected();
    
    double getSpeed();
    double getVoltage();
    double getCurrent();
    double getTemperature();
    double getBatteryPercent();
    double getDistance();
    double getTotalDistance();
    String getBrand();
  
  private:
    euc::BleHandler* ble_handler;
    euc::Euc* connected_euc = nullptr;

    pthread_t update_task;
    volatile bool is_running = false;

    void onProcessInput(uint8_t* data, size_t data_size);
    void onFoundWheel(euc::EucType type);

    static void* onUpdate(void* in); // Thread task for updating
};

#endif // EUCHANDLER_H_