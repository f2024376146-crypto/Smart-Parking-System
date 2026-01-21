#ifndef PARKINGREQUEST_H
#define PARKINGREQUEST_H

#include <string>
#include "ParkingSlot.h"

struct ParkingRequest {
    std::string vehicleID;
    int requestedZone;
    double requestTime; 
    
    SlotStatus currentStatus;

    ParkingRequest(std::string vID = "", int rZone = -1, double rTime = 0.0);
};

#endif