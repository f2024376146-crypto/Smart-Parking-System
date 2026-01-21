#include <iostream>
#include <string>
#include "Zone.h"

int main() {
    Zone myZone(1, "Main-Campus");
    int choice, id, hours;
    std::string plate, type;

    while (true) {
        std::cout << "\n--- SMART PARKING SYSTEM MENU ---" << std::endl;
        std::cout << "1. Add Slot\n2. Search Slot\n3. Remove Slot\n4. View Status\n5. Park (Check-In)\n6. Unpark (Check-Out)\n7. Exit" << std::endl;
        std::cout << "Enter Choice (1-7): ";
        
        // Input Validation to prevent infinite loops
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        if (choice == 1) {
            std::cout << "Enter Slot ID: "; std::cin >> id;
            myZone.addSlot(id);
        } else if (choice == 2) {
            std::cout << "Enter Slot ID to Search: "; std::cin >> id;
            myZone.findSlot(id);
        } else if (choice == 3) {
            std::cout << "Enter Slot ID to Remove: "; std::cin >> id;
            myZone.removeSlot(id);
        } else if (choice == 4) {
            myZone.displayZoneStatus();
        } else if (choice == 5) {
            std::cout << "Enter Slot ID: "; std::cin >> id;
            std::cout << "Enter Plate Number: "; std::cin >> plate;
            std::cout << "Enter Type (Car/Bike): "; std::cin >> type;
            // Calls the new validation logic in Zone.h
            myZone.parkVehicle(id, plate, type);
        } else if (choice == 6) {
            std::cout << "Enter Slot ID: "; std::cin >> id;
            std::cout << "Enter Hours Parked: "; std::cin >> hours;
            // Calls the new billing logic in Zone.h
            myZone.unparkVehicle(id, hours);
        } else if (choice == 7) {
            std::cout << "Exiting... Goodbye!" << std::endl;
            break;
        }
    }
    return 0;
}