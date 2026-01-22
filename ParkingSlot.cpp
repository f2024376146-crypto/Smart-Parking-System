#include "ParkingSlot.h"

ParkingSlot::ParkingSlot()
{
    slotId = -1;
    zoneId = -1;
    isAvailable = true;
}

ParkingSlot::ParkingSlot(int slotId, int zoneId)
{
    this->slotId = slotId;
    this->zoneId = zoneId;
    isAvailable = true;
}

int ParkingSlot::getSlotId() const
{
    return slotId;
}

int ParkingSlot::getZoneId() const
{
    return zoneId;
}

bool ParkingSlot::available() const
{
    return isAvailable;
}

void ParkingSlot::occupy()
{
    isAvailable = false;
}

void ParkingSlot::release()
{
    isAvailable = true;
}
