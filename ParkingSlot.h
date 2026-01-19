#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

#include <string>

enum SlotStatus { EMPTY, OCCUPIED, RESERVED };

class ParkingSlot {
public:
    int slotID;
    int zoneID;
    SlotStatus status;

    ParkingSlot() : slotID(0), zoneID(0), status(EMPTY) {}
    ParkingSlot(int id, int zID) : slotID(id), zoneID(zID), status(EMPTY) {}
};

#endif
