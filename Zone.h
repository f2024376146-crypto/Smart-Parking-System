#ifndef ZONE_H
#define ZONE_H

#include "ParkingArea.h"

struct AreaNode {
    ParkingArea* area;
    AreaNode* next;
};

class Zone {
private:
    int zoneId;
    AreaNode* head;

public:
    Zone(int id);
    ~Zone();

    Zone(const Zone&) = delete;
    Zone& operator=(const Zone&) = delete;

    void addParkingArea(ParkingArea* area);
    ParkingSlot* findSlotInZone();

    int getZoneId() const { return zoneId; }
};

#endif
