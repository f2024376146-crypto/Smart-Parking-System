#ifndef ZONE_H
#define ZONE_H

#include "ParkingArea.h"
#include <vector>
#include <string>

class Zone {
public:
    int zoneID;
    std::string zoneName;
    std::vector<ParkingArea> areas; 

    Zone(int id, std::string name, int numAreas, int slotsPerArea);
};

#endif