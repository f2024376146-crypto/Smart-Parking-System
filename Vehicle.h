#ifndef VEHICLE_H
#define VEHICLE_H
#include "Enums.h"
class Vehicle {
public:
    int vehicleID;
    VehicleType type;
    Vehicle(int id = -1, VehicleType t = CAR) : vehicleID(id), type(t) {}
};
#endif