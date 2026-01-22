#ifndef ALLOCATION_ENGINE_H
#define ALLOCATION_ENGINE_H

#include "Zone.h"

class AllocationEngine
{
public:
    ParkingSlot* allocate(Zone* zones, int zoneCount, int preferredZone);
};

#endif
