#ifndef ZONE_H
#define ZONE_H
#include "ParkingArea.h"

class Zone {
public:
    int zoneID;
    ParkingArea* areasHead; 
    Zone* next;             

    Zone(int id);
    void addArea(int aID);
    ParkingSlot* getFreeSlotInZone();
};
#endif