#include <iostream>
#include <string>
#include "Zone.h"

int main() {

    Zone myZone(1, "Main-Campus-Parking");
    int choice, id;

    while (true) {
        std::cout << "\n================================";
        std::cout << "\n   SMART PARKING SYSTEM (v2.0)";
        std::cout << "\n================================";
        std::cout << "\n1. Add New Parking Slot";
        std::cout << "\n2. Search Slot by ID";
        std::cout << "\n3. Remove Parking Slot";
        std::cout << "\n4. View All Slots (Status)";
        std::cout << "\n5. Park a Vehicle (Enter Details)";
        std::cout << "\n6. Exit";
        std::cout << "\n--------------------------------";
        std::cout << "\nEnter Your Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter Slot ID to Create: ";
            std::cin >> id;
            myZone.addSlot(id);
            std::cout << "Success: Slot " << id << " created.\n";
        } 
        else if (choice == 2) {
            std::cout << "Enter Slot ID to Search: ";
            std::cin >> id;
            myZone.findSlot(id);
        } 
        else if (choice == 3) {
            std::cout << "Enter Slot ID to Remove: ";
            std::cin >> id;
            myZone.removeSlot(id);
        } 
        else if (choice == 4) {
            myZone.displayZoneStatus();
        } 
        else if (choice == 5) {
            std::string plate, vType;
            std::cout << "Enter Slot ID to use: ";
            std::cin >> id;
            
            
            std::cout << "Enter Vehicle Plate Number (e.g. ABC-123): ";
            std::cin >> plate;
            std::cout << "Enter Vehicle Type (Car/Bike/Truck): ";
            std::cin >> vType;
            
            myZone.parkVehicle(id, plate, vType);
        } 
        else if (choice == 6) {
            std::cout << "Exiting System... Allah Hafiz!\n";
            break;
        } 
        else {
            std::cout << "Invalid Option! Please try again.\n";
        }
    }
    return 0;
}