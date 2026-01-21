#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

struct Vehicle {
    std::string vehicleID;
    int preferredZone;

    Vehicle(std::string id = "N/A", int pZone = -1);
};
#endif