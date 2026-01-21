#ifndef ALLOCATIONENGINE_H
#define ALLOCATIONENGINE_H

#include "Zone.h"
#include "ParkingRequest.h"

class AllocationEngine {
public:
    
    ParkingSlot* allocateSlot(ParkingRequest& request, std::vector<Zone>& allZones);
};

#endif