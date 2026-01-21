#include "ParkingSystem.h"
#include <iostream>

ParkingSystem::ParkingSystem() {
    
}

void ParkingSystem::processNewRequest(std::string vID, int preferredZone) {
    std::cout << "Processing request for Vehicle: " << vID << " in Zone: " << preferredZone << std::endl;
}