#ifndef ZONE_H
#define ZONE_H

#include "ParkingArea.h"

// Linked List Node for Parking Areas
struct AreaNode {
    ParkingArea* area;
    AreaNode* next;
};

class Zone {
private:
    int zoneId;
    AreaNode* head;         
    int* adjacentZones;     
    int adjCount;

public:
    Zone(int id);
    ~Zone();

    
    Zone(const Zone& other) = delete;
    Zone& operator=(const Zone& other) = delete;

    void addParkingArea(ParkingArea* area);
    void setAdjacentZones(int* zones, int count);
    
    ParkingSlot* findSlotInZone();
    
    int getZoneId() const { return zoneId; }
    int getAdjCount() const { return adjCount; }
    int* getAdjacentZones() const { return adjacentZones; }
};

#endif