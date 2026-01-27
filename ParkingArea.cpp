#include "ParkingArea.h"
ParkingArea::ParkingArea(int startID, int zID) {
    for(int i=0; i<5; i++) slots[i] = new ParkingSlot(startID + i, zID);
}
ParkingArea::~ParkingArea() {
    for(int i=0; i<5; i++) delete slots[i];
}
ParkingSlot* ParkingArea::findAvailableSlot() {
    for(int i=0; i<5; i++) if(slots[i]->isAvailable) return slots[i];
    return nullptr;
}