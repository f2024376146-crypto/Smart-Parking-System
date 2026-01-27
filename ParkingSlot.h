#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H
class ParkingSlot {
public:
    int slotID, zoneID;
    bool isAvailable;
    ParkingSlot(int sID = -1, int zID = -1);
};
#endif