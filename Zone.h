#ifndef ZONE_H
#define ZONE_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ParkingSlot.h"

class Zone {
public:
    int zoneID;
    std::string zoneName;
    LinkedList<ParkingSlot> slots;

    Zone(int id, std::string name) : zoneID(id), zoneName(name) {}

    void addSlot(int id) {
        slots.add(ParkingSlot(id, zoneID));
    }

    void removeSlot(int id) {
        slots.remove(id);
        std::cout << "Action: Slot " << id << " has been removed.\n";
    }

    void findSlot(int id) {
        Node<ParkingSlot>* res = slots.search(id);
        if (res) std::cout << "Result: Slot " << id << " is FOUND in " << zoneName << "\n";
        else std::cout << "Result: Slot " << id << " not found!\n";
    }

    void displayZoneStatus() {
        std::cout << "\n--- Parking Status: " << zoneName << " ---" << std::endl;
        Node<ParkingSlot>* temp = slots.head;
        if (!temp) std::cout << "No slots created yet." << std::endl;
        while (temp) {
            std::cout << "Slot ID: " << temp->data.slotID << " | Status: Available" << std::endl;
            temp = temp->next;
        }
    }
};
#endif