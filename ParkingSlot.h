#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include <string>

// Detail of Vehicle
struct Vehicle {
    std::string plateNumber;
    std::string vehicleType; 
};

enum SlotStatus { EMPTY, OCCUPIED };

// details of Parking Slot
struct ParkingSlot {
    int slotID;
    int zoneID;
    SlotStatus status;
    Vehicle vehicle;  


    ParkingSlot(int id, int zID) : slotID(id), zoneID(zID), status(EMPTY) {
        vehicle.plateNumber = "N/A";
        vehicle.vehicleType = "None";
    }
};

#endif