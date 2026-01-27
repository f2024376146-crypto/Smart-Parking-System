#ifndef PARKINGREQUEST_H
#define PARKINGREQUEST_H
#include "Enums.h"
class ParkingRequest {
public:
    int vehicleID, allocatedSlotID;
    VehicleType vType;
    double totalFee;
    RequestState state;
    ParkingRequest();
    bool transitionTo(RequestState newState);
    void calculateFee(bool isCrossZone);
};
#endif