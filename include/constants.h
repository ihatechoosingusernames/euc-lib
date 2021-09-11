#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <array>
#include <vector>
namespace euc {

enum class EucType : size_t {
  kGotway = 0,
  kKingsong,
  kInmotion,
  kNinebotZ,
  kNinebot,
  kLastType // IMPORTANT, this marks the last type of EUC, and the size of the EUC arrays
};

const static char* kServiceUuids[] = {"0000ffe0-0000-1000-8000-00805f9b34fb", "0000ffe0-0000-1000-8000-00805f9b34fb", "0000ffe0-0000-1000-8000-00805f9b34fb", "6e400001-b5a3-f393-e0a9-e50e24dcca9e", "0000ffe0-0000-1000-8000-00805f9b34fb"};
const static char* kReadCharacteristicUuids[] = {"0000ffe1-0000-1000-8000-00805f9b34fb", "0000ffe1-0000-1000-8000-00805f9b34fb", "0000ffe4-0000-1000-8000-00805f9b34fb", "6e400003-b5a3-f393-e0a9-e50e24dcca9e", "0000ffe1-0000-1000-8000-00805f9b34fb"};
const static char* kBrandName[] = {"GOTWAY", "KINGSONG", "INMOTION", "NINEBOTZ", "NINEBOT"};

// Using vectors for these so they can be referenced by kServiceList, and provide their own size. std::arrays would all have to be the same length.
const static std::vector<const char*> kGotwayServices = {"00001800-0000-1000-8000-00805f9b34fb", "00001801-0000-1000-8000-00805f9b34fb", "0000180a-0000-1000-8000-00805f9b34fb", "0000ffe0-0000-1000-8000-00805f9b34fb"};
const static std::vector<const char*> kKingSongServices = {"00001800-0000-1000-8000-00805f9b34fb", "00001801-0000-1000-8000-00805f9b34fb", "0000180a-0000-1000-8000-00805f9b34fb", "0000fff0-0000-1000-8000-00805f9b34fb", "0000ffe0-0000-1000-8000-00805f9b34fb"};
const static std::vector<const char*> kInmotionServices = {"0000180a-0000-1000-8000-00805f9b34fb", "0000180f-0000-1000-8000-00805f9b34fb", "0000ffe0-0000-1000-8000-00805f9b34fb", "0000ffe5-0000-1000-8000-00805f9b34fb", "0000fff0-0000-1000-8000-00805f9b34fb", "0000ffd0-0000-1000-8000-00805f9b34fb", "0000ffc0-0000-1000-8000-00805f9b34fb", "0000ffb0-0000-1000-8000-00805f9b34fb", "0000ffa0-0000-1000-8000-00805f9b34fb", "0000ff90-0000-1000-8000-00805f9b34fb", "0000fc60-0000-1000-8000-00805f9b34fb", "0000fe00-0000-1000-8000-00805f9b34fb"};
const static std::vector<const char*> kNinebotZServices = {"00001800-0000-1000-8000-00805f9b34fb", "00001801-0000-1000-8000-00805f9b34fb", "6e400001-b5a3-f393-e0a9-e50e24dcca9e", "0000fee7-0000-1000-8000-00805f9b34fb"};
const static std::vector<const char*> kNinebotServices = {"00001800-0000-1000-8000-00805f9b34fb", "00001801-0000-1000-8000-00805f9b34fb", "0000ffe0-0000-1000-8000-00805f9b34fb"};

const static std::array<std::vector<const char*>, 5> kServiceList = {kGotwayServices, kKingSongServices, kInmotionServices, kNinebotZServices, kNinebotServices};

}

#endif  // CONSTANTS_H_