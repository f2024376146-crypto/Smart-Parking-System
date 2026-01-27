#include "ParkingSystem.h"
#include <iostream>
using namespace std;

int main() {
    ParkingSystem city;
    int choice, vID, zID;
    while (true) {
        cout << "\n1. Request Parking\n2. Release Slot\n3. Rollback Operations\n4. View Analytics\n5. Exit\n6. Run Automated Tests\nSelection: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(100, '\n'); continue; }
        if (choice == 5) break;
        switch (choice) {
            case 1: cout << "Vehicle ID & Zone (0-2): "; cin >> vID >> zID; city.allocate(vID, zID); break;
            case 2: cout << "Request Index: "; cin >> vID; city.release(vID); break;
            case 3: int k; cout << "Steps: "; cin >> k; city.rollback(k); break;
            case 4: city.showAnalytics(); break;
            case 6: city.runAutomatedTests(); break; // Yahan call hoga
            default: cout << "[!] INVALID SELECTION: Try 1-6." << endl;
        }
    }
    return 0;
}