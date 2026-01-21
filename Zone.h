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

    // Constructor
    Zone(int id, std::string name) : zoneID(id), zoneName(name) {}

    // 1. Add a new parking slot to the zone
    void addSlot(int id) {
        slots.add(ParkingSlot(id, zoneID));
        std::cout << "Success: Slot " << id << " created in " << zoneName << "." << std::endl;
    }

    // 2. Search for a slot by its ID
    void findSlot(int id) {
        Node<ParkingSlot>* res = slots.search(id);
        if (res) {
            std::cout << "Result: Slot " << id << " found." << std::endl;
        } else {
            std::cout << "Result: Slot " << id << " does not exist." << std::endl;
        }
    }

    // 3. Remove a slot from the system
    void removeSlot(int id) {
        Node<ParkingSlot>* res = slots.search(id);
        if (res) {
            slots.remove(id);
            std::cout << "Action: Slot " << id << " has been removed." << std::endl;
        } else {
            std::cout << "Error: Cannot remove. Slot ID not found." << std::endl;
        }
    }

    // 4. Park a vehicle with Type Validation (Only Car/Bike)
    void parkVehicle(int sID, std::string plate, std::string type) {
        // Validation: Only allow Cars and Bikes
        if (type != "Car" && type != "car" && type != "Bike" && type != "bike") {
            std::cout << "RESTRICTION: Only Cars and Bikes are allowed in this parking!" << std::endl;
            return;
        }

        Node<ParkingSlot>* res = slots.search(sID);
        if (res && res->data.status == EMPTY) {
            res->data.vehicle.plateNumber = plate;
            res->data.vehicle.vehicleType = type;
            res->data.status = OCCUPIED;
            std::cout << "Success: " << type << " (" << plate << ") parked in slot " << sID << "." << std::endl;
        } else {
            std::cout << "Error: Slot " << sID << " is either occupied or does not exist." << std::endl;
        }
    }

    // 5. Display status of all slots in this zone
    void displayZoneStatus() {
        std::cout << "\n--- Current Status of " << zoneName << " ---" << std::endl;
        Node<ParkingSlot>* temp = slots.head;
        if (!temp) {
            std::cout << "No slots available." << std::endl;
            return;
        }
        while (temp) {
            std::cout << "Slot ID: " << temp->data.slotID 
                      << " | Status: " << (temp->data.status == EMPTY ? "[FREE]" : "[OCCUPIED]");
            if (temp->data.status == OCCUPIED) {
                std::cout << " | Vehicle: " << temp->data.vehicle.plateNumber 
                          << " (" << temp->data.vehicle.vehicleType << ")";
            }
            std::cout << std::endl;
            temp = temp->next;
        }
    }

    // 6. Unpark vehicle and generate billing receipt
    void unparkVehicle(int sID, int hours) {
        Node<ParkingSlot>* res = slots.search(sID);
        if (res && res->data.status == OCCUPIED) {
            // Billing Logic: Rs 50 for Car, Rs 20 for Bike
            int rate = (res->data.vehicle.vehicleType == "Car" || res->data.vehicle.vehicleType == "car") ? 50 : 20;
            int totalFee = hours * rate;

            std::cout << "\n================================" << std::endl;
            std::cout << "       PARKING RECEIPT" << std::endl;
            std::cout << "================================" << std::endl;
            std::cout << "Vehicle Plate: " << res->data.vehicle.plateNumber << std::endl;
            std::cout << "Vehicle Type : " << res->data.vehicle.vehicleType << std::endl;
            std::cout << "Duration     : " << hours << " hours" << std::endl;
            std::cout << "Rate Applied : Rs. " << rate << "/hr" << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "TOTAL FEE    : Rs. " << totalFee << std::endl;
            std::cout << "================================" << std::endl;
            
            // Reset the slot to empty
            res->data.status = EMPTY;
            res->data.vehicle.plateNumber = "N/A";
            res->data.vehicle.vehicleType = "None";
            std::cout << "Action: Slot " << sID << " is now vacant." << std::endl;
        } else {
            std::cout << "Error: Slot " << sID << " is not occupied." << std::endl;
        }
    }
};

#endif