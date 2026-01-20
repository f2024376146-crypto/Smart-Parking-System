#ifndef ZONE_H
#define ZONE_H

#include <string>
#include <iostream>
#include "LinkedList.h"
#include "ParkingSlot.h"

class Zone {
public:
    int zoneID;
    std::string zoneName;
    LinkedList<ParkingSlot> slots;

    // Default Constructo
    Zone() : zoneID(0), zoneName("") {}

    // Parameterized Constructor
    Zone(int id, std::string name) : zoneID(id), zoneName(name) {}

    // Function to add a slot to this specific zone
    void addSlot(int id) {
        slots.add(ParkingSlot(id, zoneID));
    }
    void displayZoneStatus() {
    std::cout << "\n--- Zone: " << zoneName << " Status ---" << std::endl;
    Node<ParkingSlot>* temp = slots.head;
    while (temp != nullptr) {
        std::cout << "Slot ID: " << temp->data.slotID << " | Status: ";
        if (temp->data.status == EMPTY) std::cout << "Available";
        else std::cout << "Occupied";
        std::cout << std::endl;
        temp = temp->next;
    }
}

    
};

#endif