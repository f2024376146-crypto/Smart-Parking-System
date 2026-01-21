#ifndef PARKINGAREA_H
#define PARKINGAREA_H

#include "ParkingSlot.h"
#include <vector>

class ParkingArea {
public:
    int areaID;
    std::vector<ParkingSlot> slots;
    
    ParkingArea(int id, int numSlots);
    bool hasEmptySlot();
};

#endif

