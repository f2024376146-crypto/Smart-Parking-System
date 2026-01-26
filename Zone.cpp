#include "Zone.h"

Zone::Zone(int id) : zoneId(id), head(nullptr) {}

Zone::~Zone()
{
    AreaNode* current = head;
    while (current)
    {
        AreaNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void Zone::addParkingArea(ParkingArea* area)
{
    AreaNode* node = new AreaNode{area, head};
    head = node;
}

ParkingSlot* Zone::findSlotInZone()
{
    AreaNode* current = head;
    while (current)
    {
        ParkingSlot* slot = current->area->getFirstFreeSlot();
        if (slot)
            return slot;
        current = current->next;
    }
    return nullptr;
}
