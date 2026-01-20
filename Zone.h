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

    // --- Aapki partner yahan se apna display function likhengi ---
};

#endif