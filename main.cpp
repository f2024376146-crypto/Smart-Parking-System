#include <iostream>
#include "Zone.h"

int main() {
    
    Zone myZone(1, "VIP-Parking");


    myZone.addSlot(101);
    myZone.addSlot(102);
    myZone.addSlot(103);

    myZone.displayZoneStatus();

    return 0;
}
