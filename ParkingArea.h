#ifndef PARKINGAREA_H
#define PARKINGAREA_H
#include "ParkingSlot.h"

class ParkingArea {
public:
    int areaID;
    ParkingSlot* slotsHead; 
    ParkingArea* next;      

    ParkingArea(int id);
    void addSlot(int sID, int zID);
    ParkingSlot* findAvailableSlot(); 
};
#endif