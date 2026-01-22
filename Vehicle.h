#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
private:
    int vehicleId;
    int preferredZone;

public:
    Vehicle();
    Vehicle(int id, int zone);

    int getVehicleId() const;
    int getPreferredZone() const;
};

#endif
