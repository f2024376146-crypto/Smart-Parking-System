#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H
#include "Vehicle.h"


enum SlotState { REQUESTED, ALLOCATED, OCCUPIED, RELEASED, CANCELLED };

struct ParkingSlot {
    int slotID;
    int zoneID;
    SlotState state;
    Vehicle parkedVehicle;
    ParkingSlot* next; 

    ParkingSlot(int id, int zID);
};
#endif