#include "ParkingRequest.h"
ParkingRequest::ParkingRequest() : vehicleID(-1), allocatedSlotID(-1), totalFee(0.0), state(REQUESTED) {}
bool ParkingRequest::transitionTo(RequestState newState) {
    if (state == REQUESTED && newState == ALLOCATED) { state = newState; return true; }
    if (state == ALLOCATED && newState == RELEASED) { state = newState; return true; }
    return false;
}
void ParkingRequest::calculateFee(bool isCrossZone) {
    if(vType == BIKE) totalFee = 10.0; 
    else if(vType == CAR) totalFee = 20.0; 
    else totalFee = 50.0;
    if(isCrossZone) totalFee += 15.0; // Penalty logic
}