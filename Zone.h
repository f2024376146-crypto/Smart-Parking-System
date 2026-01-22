#ifndef ZONE_H
#define ZONE_H

#include "ParkingArea.h"

struct AreaNode
{
    ParkingArea area;
    AreaNode* next;
};

class Zone
{
private:
    int zoneId;
    AreaNode* head;
    int* adjacentZones;
    int adjCount;

public:
    Zone();
    Zone(int id);

    void addParkingArea(ParkingArea area);
    ParkingSlot* findAvailableSlot();

    void setAdjacentZones(int* zones, int count);
    int getZoneId() const;
};

#endif
