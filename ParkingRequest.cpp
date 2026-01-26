#include "ParkingRequest.h"

ParkingRequest::ParkingRequest()
{
    state = REQUESTED;
}

ParkingRequest::ParkingRequest(int rid, int vid, int zid, int time)
{
    requestId = rid;
    vehicleId = vid;
    zoneId = zid;
    requestTime = time;
    state = REQUESTED;
}

bool ParkingRequest::transition(RequestState newState)
{
    if (
        (state == REQUESTED && (newState == ALLOCATED || newState == CANCELLED)) ||
        (state == ALLOCATED && (newState == OCCUPIED || newState == CANCELLED)) ||
        (state == OCCUPIED && newState == RELEASED)
       )
    {
        state = newState;
        return true;
    }
    return false;
}

RequestState ParkingRequest::getState() const
{
    return state;
}

int ParkingRequest::getZoneId() const
{
    return zoneId;
}
