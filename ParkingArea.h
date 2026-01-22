#ifndef PARKING_AREA_H
#define PARKING_AREA_H

#include "ParkingSlot.h"

class ParkingArea
{
private:
    ParkingSlot* slots;
    int slotCount;

public:
    ParkingArea();
    ParkingArea(int zoneId, int count);

    ParkingSlot* getFirstFreeSlot();
    int getTotalSlots() const;
    int getFreeSlotCount() const;
};

#endif
