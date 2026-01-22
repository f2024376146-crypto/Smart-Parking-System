#ifndef PARKING_SYSTEM_H
#define PARKING_SYSTEM_H

#include "Zone.h"
#include "AllocationEngine.h"
#include "RollbackManager.h"

class ParkingSystem
{
private:
    Zone* zones;
    int zoneCount;
    AllocationEngine allocator;
    RollbackManager rollbackMgr;

public:
    ParkingSystem(Zone* zones, int count);
    void processRequest(ParkingRequest& request);
    void cancelRequest(ParkingRequest& request);
    void rollbackLast(int k);
};

#endif
