#include <iostream>
#include "AllocationEngine.h"
#include "RollbackManager.h"

int main() {
    AllocationEngine engine;
    RollbackManager rollback;

    Zone* z1 = new Zone(1);
    z1->addArea(101);
    z1->areasHead->addSlot(501, 1);
    engine.addZone(z1);

    std::cout << "--- Smart Parking System Running ---\n";
    ParkingSlot* s = engine.allocateSlot(1, "CAR-123");
    if(s) rollback.pushAction(s);
    
    std::cout << "Test: Undoing last allocation...\n";
    rollback.undoLastAction();

    return 0;
}