#ifndef PARKING_REQUEST_H
#define PARKING_REQUEST_H

enum RequestState
{
    REQUESTED,
    ALLOCATED,
    OCCUPIED,
    RELEASED,
    CANCELLED
};

class ParkingRequest
{
private:
    int requestId;
    int vehicleId;
    int zoneId;
    int requestTime;
    RequestState state;

public:
    ParkingRequest();
    ParkingRequest(int rid, int vid, int zid, int time);

    bool transition(RequestState newState);
    RequestState getState() const;

    int getRequestId() const;
    int getZoneId() const;
};

#endif
