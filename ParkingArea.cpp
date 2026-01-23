#include "ParkingArea.h"
#include <iostream>

using namespace std;


ParkingArea::ParkingArea(int zoneId, int c) : count(c) {
    slots = new ParkingSlot[count];
    for (int i = 0; i < count; i++) {
        slots[i] = ParkingSlot(i + 1, zoneId)t ho rahi hain
    }
}


ParkingArea::~ParkingArea() {
    if (slots != nullptr) {
        delete[] slots;
        slots = nullptr;
    }
}


ParkingSlot* ParkingArea::getFirstFreeSlot() {
    for (int i = 0; i < count; i++) {
        if (slots[i].isFree()) {
            return &slots[i];
        }
    }
    return nullptr; 
}


int ParkingArea::getFreeSlotCount() const {
    int freeCount = 0;
    for (int i = 0; i < count; i++) {
        if (slots[i].isFree()) {
            freeCount++;
        }
    }
    return freeCount;
}


int ParkingArea::getTotalSlots() const {
    return count;
}