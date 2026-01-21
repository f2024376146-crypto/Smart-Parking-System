#include "AllocationEngine.h"
#include <iostream>

AllocationEngine::AllocationEngine() : zonesHead(nullptr) {}

void AllocationEngine::addZone(Zone* z) {
    z->next = zonesHead;
    zonesHead = z;
}

ParkingSlot* AllocationEngine::allocateSlot(int prefID, std::string vID) {
    Zone* temp = zonesHead;
    while (temp) {
        if (temp->zoneID == prefID) {
            ParkingSlot* slot = temp->getFreeSlotInZone();
            if (slot) {
                slot->state = ALLOCATED;
                slot->parkedVehicle = Vehicle(vID, prefID);
                return slot;
            }
        }
        temp = temp->next;
    }
    // Cross-zone logic if preferred is full
    temp = zonesHead;
    while (temp) {
        ParkingSlot* slot = temp->getFreeSlotInZone();
        if (slot) {
            slot->state = ALLOCATED;
            slot->parkedVehicle = Vehicle(vID, prefID);
            std::cout << "Cross-zone allocation used.\n";
            return slot;
        }
        temp = temp->next;
    }
    return nullptr;
}