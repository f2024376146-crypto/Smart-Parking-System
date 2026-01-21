#include <iostream>
#include "Zone.h"

int main() {
    Zone myZone(1, "Main-Campus-Parking");
    int choice, id;

    while (true) {
        std::cout << "\n--- SMART PARKING MENU ---";
        std::cout << "\n1. Add Slot\n2. Search Slot\n3. Remove Slot\n4. View All Slots\n5. Exit";
        std::cout << "\nEnter Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Enter New Slot ID: "; std::cin >> id;
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
            std::cout << "Exiting\n";
            break;
        } else {
            std::cout << "Invalid Option!\n";
        }
    }
    return 0;
}