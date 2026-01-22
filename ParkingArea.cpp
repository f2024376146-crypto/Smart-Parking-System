#include "ParkingArea.h"

ParkingArea::ParkingArea()
{
    slots = nullptr;
    slotCount = 0;
}

ParkingArea::ParkingArea(int zoneId, int count)
{
    slotCount = count;
    slots = new ParkingSlot[count];

    for (int i = 0; i < count; i++)
        slots[i] = ParkingSlot(i, zoneId);
}

ParkingSlot* ParkingArea::getFirstFreeSlot()
{
    for (int i = 0; i < slotCount; i++)
        if (slots[i].isFree())
            return &slots[i];

    return nullptr;
}

int ParkingArea::getTotalSlots() const
{
    return slotCount;
}

int ParkingArea::getFreeSlotCount() const
{
    int free = 0;
    for (int i = 0; i < slotCount; i++)
        if (slots[i].isFree())
            free++;
    return free;
}
