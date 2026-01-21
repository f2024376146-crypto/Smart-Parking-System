#include "ParkingArea.h"

ParkingArea::ParkingArea(int id) : areaID(id), slotsHead(nullptr), next(nullptr) {}

void ParkingArea::addSlot(int sID, int zID) {
    ParkingSlot* newSlot = new ParkingSlot(sID, zID);
    newSlot->next = slotsHead;
    slotsHead = newSlot;
}

ParkingSlot* ParkingArea::findAvailableSlot() {
    ParkingSlot* temp = slotsHead;
    while (temp) {
        
        if (temp->state == RELEASED || temp->state == CANCELLED) return temp;
        temp = temp->next;
    }
    return nullptr;
}