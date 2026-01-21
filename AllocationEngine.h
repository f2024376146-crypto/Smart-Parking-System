#ifndef ALLOCATIONENGINE_H
#define ALLOCATIONENGINE_H
#include "Zone.h"

class AllocationEngine {
public:
    Zone* zonesHead;
    AllocationEngine();
    void addZone(Zone* z);
    ParkingSlot* allocateSlot(int prefID, std::string vID);
};
#endif