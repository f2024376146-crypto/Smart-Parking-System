#include <iostream>
#include "LinkedList.h"
#include "ParkingSlot.h"

int main() {

    LinkedList<ParkingSlot> system;


    system.add(ParkingSlot(101, 1));
    system.add(ParkingSlot(102, 1));

    std::cout << "Smart Parking System Initialized!" << std::endl;
    

    if (system.head != nullptr) {
        std::cout << "Latest Slot added: " << system.head->data.slotID << std::endl;
    }

    return 0;
}