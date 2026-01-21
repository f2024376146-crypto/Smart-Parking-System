#include "AllocationEngine.h"
#include <iostream>

ParkingSlot* AllocationEngine::allocateSlot(ParkingRequest& request, std::vector<Zone>& allZones) {
    
    for (auto& area : allZones[request.requestedZone].areas) {
        for (auto& slot : area.slots) {
            if (slot.status == EMPTY) {
                slot.updateStatus(REQUESTED); // Lifecycle: REQUESTED
                slot.updateStatus(ALLOCATED); // Lifecycle: ALLOCATED
                std::cout << "Allocated in Preferred Zone. Base Cost applied." << std::endl;
                return &slot;
            }
        }
    }

    
    for (auto& zone : allZones) {
        for (auto& area : zone.areas) {
            for (auto& slot : area.slots) {
                if (slot.status == EMPTY) {
                    slot.updateStatus(REQUESTED);
                    slot.updateStatus(ALLOCATED);
                    std::cout << "Cross-Zone Allocation! Extra Penalty Applied." << std::endl; //
                    return &slot;
                }
            }
        }
    }
    return nullptr;
}