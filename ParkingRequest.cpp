#include "ParkingRequest.h"

ParkingRequest::ParkingRequest(std::string vID, int rZone, double rTime) 
    : vehicleID(vID), requestedZone(rZone), requestTime(rTime), currentStatus(REQUESTED) {}
