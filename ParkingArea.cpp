#include "ParkingArea.h"

ParkingArea::ParkingArea(int zoneId, int c) : count(c)
{
    slots = new ParkingSlot[count];
    for (int i = 0; i < count; i++)
    {
        slots[i] = ParkingSlot(i + 1, zoneId);
    }
}

ParkingArea::~ParkingArea()
{
    delete[] slots;
}

ParkingSlot* ParkingArea::getFirstFreeSlot()
{
    for (int i = 0; i < count; i++)
    {
        if (slots[i].available())
            return &slots[i];
    }
    return nullptr;
}

int ParkingArea::getFreeSlotCount() const
{
    int freeCount = 0;
    for (int i = 0; i < count; i++)
        if (slots[i].available())
            freeCount++;
    return freeCount;
}

int ParkingArea::getTotalSlots() const
{
    return count;
}
