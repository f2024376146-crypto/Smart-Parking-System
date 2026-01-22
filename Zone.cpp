#include "Zone.h"

Zone::Zone()
{
    zoneId = -1;
    head = nullptr;
    adjacentZones = nullptr;
    adjCount = 0;
}

Zone::Zone(int id)
{
    zoneId = id;
    head = nullptr;
    adjacentZones = nullptr;
    adjCount = 0;
}

void Zone::addParkingArea(ParkingArea area)
{
    AreaNode* node = new AreaNode{area, head};
    head = node;
}

ParkingSlot* Zone::findAvailableSlot()
{
    AreaNode* temp = head;
    while (temp)
    {
        ParkingSlot* slot = temp->area.getFirstAvailableSlot();
        if (slot)
            return slot;
        temp = temp->next;
    }
    return nullptr;
}

void Zone::setAdjacentZones(int* zones, int count)
{
    adjacentZones = zones;
    adjCount = count;
}

int Zone::getZoneId() const
{
    return zoneId;
}
