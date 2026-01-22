#include "ParkingSystem.h"

ParkingSystem::ParkingSystem(Zone* z, int count)
{
    zones = z;
    zoneCount = count;
}

void ParkingSystem::processRequest(ParkingRequest& request)
{
    ParkingSlot* slot = allocator.allocate(zones, zoneCount, request.getZoneId());
    if (slot)
    {
        rollbackMgr.push(slot, &request, request.getState());
        slot->occupy();
        request.transition(ALLOCATED);
    }
}

void ParkingSystem::cancelRequest(ParkingRequest& request)
{
    request.transition(CANCELLED);
}

void ParkingSystem::rollbackLast(int k)
{
    rollbackMgr.rollback(k);
}
