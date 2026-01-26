#ifndef PARKINGAREA_H
#define PARKINGAREA_H

#include "ParkingSlot.h"

class ParkingArea {
private:
    ParkingSlot* slots;
    int count;

public:
    ParkingArea(int zoneId, int c);
    ~ParkingArea();

    ParkingArea(const ParkingArea&) = delete;
    ParkingArea& operator=(const ParkingArea&) = delete;

    ParkingSlot* getFirstFreeSlot();
    int getFreeSlotCount() const;
    int getTotalSlots() const;
};

#endif
