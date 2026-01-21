#include "ParkingSlot.h"
#include <iostream>

// Requirement 4: Enforce strict lifecycle
bool ParkingSlot::updateStatus(SlotStatus nextStatus) {
    if (status == EMPTY && nextStatus == REQUESTED) { status = nextStatus; return true; }
    if (status == REQUESTED && nextStatus == ALLOCATED) { status = nextStatus; return true; }
    if (status == ALLOCATED && nextStatus == OCCUPIED) { status = nextStatus; return true; }
    if (status == OCCUPIED && nextStatus == RELEASED) { status = nextStatus; return true; }
    if ((status == REQUESTED || status == ALLOCATED) && nextStatus == CANCELLED) { status = nextStatus; return true; }
    
    std::cout << "Invalid State Transition!" << std::endl; //
    return false;
}