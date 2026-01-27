#ifndef PARKINGAREA_H
#define PARKINGAREA_H
#include "ParkingSlot.h"
class ParkingArea {
public:
    ParkingSlot* slots[5]; // Each area manages 5 slots
    ParkingArea(int startID, int zID);
    ~ParkingArea();
    ParkingSlot* findAvailableSlot();
};
#endif