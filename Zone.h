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

    // Default Constructor
    Zone() : zoneID(0), zoneName("") {}

    // Parameterized Constructor
    Zone(int id, std::string name) : zoneID(id), zoneName(name) {}

    // Function to add a slot to this specific zone
    void addSlot(int id) {
        slots.add(ParkingSlot(id, zoneID));
    }
    void displayZoneStatus() {
        std::cout << "\n--- Parking Zone: " << zoneName << " ---" << std::endl;
        Node<ParkingSlot>* temp = slots.head;
        if (temp == nullptr) {
            std::cout << "there is no slot in this zone." << std::endl;
            return;
        }
        while (temp != nullptr) {
            std::cout << "Slot ID: " << temp->data.slotID << " | Status: ";
            if (temp->data.status == 0) std::cout << "[ FREE ]";
            else std::cout << "[ OCCUPIED ]";
            std::cout << std::endl;
            temp = temp->next;
        }
    }


    
};

#endif