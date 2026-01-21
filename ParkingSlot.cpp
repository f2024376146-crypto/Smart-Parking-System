#include "ParkingSlot.h"

ParkingSlot::ParkingSlot(int id, int zID) 
    : slotID(id), zoneID(zID), state(RELEASED), next(nullptr) {}