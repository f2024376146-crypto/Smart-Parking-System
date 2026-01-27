#include "AllocationEngine.h"
ParkingSlot* AllocationEngine::findSlot(Zone* zones[], int zID) {
    if (zID < 0 || zID > 2) return nullptr; // Invalid Zone protection
    return zones[zID]->findSlotInZone();
}