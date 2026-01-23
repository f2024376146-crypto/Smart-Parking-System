#ifndef PARKINGAREA_H
#define PARKINGAREA_H

#include "ParkingSlot.h"

class ParkingArea {
private:
    ParkingSlot* slots;
    int count;
    int areaId; 
public:
    
    ParkingArea(int zoneId, int c);

    
    ~ParkingArea();

    
    ParkingArea(const ParkingArea& other) = delete;
    ParkingArea& operator=(const ParkingArea& other) = delete;

    
    ParkingSlot* getFirstFreeSlot();
    int getFreeSlotCount() const;
    int getTotalSlots() const;


    int getCount() const { return count; }
};

#endif