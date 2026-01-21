#include "Zone.h"

Zone::Zone(int id) : zoneID(id), areasHead(nullptr), next(nullptr) {}

void Zone::addArea(int aID) {
    ParkingArea* newArea = new ParkingArea(aID);
    newArea->next = areasHead;
    areasHead = newArea;
}

ParkingSlot* Zone::getFreeSlotInZone() {
    ParkingArea* tempArea = areasHead;
    while (tempArea) {
        ParkingSlot* slot = tempArea->findAvailableSlot();
        if (slot) return slot; 
        tempArea = tempArea->next;
    }
    return nullptr;
}