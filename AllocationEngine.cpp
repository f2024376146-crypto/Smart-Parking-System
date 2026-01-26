#include "AllocationEngine.h"

ParkingSlot* AllocationEngine::allocate(Zone* zones, int zoneCount, int preferredZone)
{
    for (int i = 0; i < zoneCount; i++)
        if (zones[i].getZoneId() == preferredZone)
        {
            ParkingSlot* slot = zones[i].findSlotInZone();
            if (slot) return slot;
        }

    for (int i = 0; i < zoneCount; i++)
    {
        ParkingSlot* slot = zones[i].findSlotInZone();
        if (slot) return slot;
    }

    return nullptr;
}
