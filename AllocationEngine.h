#ifndef ALLOCATIONENGINE_H
#define ALLOCATIONENGINE_H
#include "Zone.h"
class AllocationEngine {
public:
    static ParkingSlot* findSlot(Zone* zones[], int zID);
};
#endif