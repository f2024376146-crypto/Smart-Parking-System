#include <iostream>
#include "ParkingSystem.h"
#include "Vehicle.h"
#include "ParkingRequest.h"

using namespace std;

int main()
{
    cout << "===== SMART PARKING SYSTEM TESTING =====\n\n";

    // ----------------- SYSTEM SETUP -----------------
    Zone zones[2] = { Zone(1), Zone(2) };

    zones[0].addParkingArea(ParkingArea(1, 2)); // Zone 1: 2 slots
    zones[1].addParkingArea(ParkingArea(2, 1)); // Zone 2: 1 slot

    ParkingSystem system(zones, 2);

    // ----------------- TEST CASE 1 -----------------
    cout << "Test 1: Same-zone allocation\n";
    ParkingRequest r1(1, 101, 1, 10);
    system.processRequest(r1);
    cout << "Expected: Allocated in Zone 1\n\n";

    // ----------------- TEST CASE 2 -----------------
    cout << "Test 2: Another same-zone allocation\n";
    ParkingRequest r2(2, 102, 1, 12);
    system.processRequest(r2);
    cout << "Expected: Allocated in Zone 1 (last slot)\n\n";

    // ----------------- TEST CASE 3 -----------------
    cout << "Test 3: Zone full -> Cross-zone allocation\n";
    ParkingRequest r3(3, 103, 1, 14);
    system.processRequest(r3);
    cout << "Expected: Allocated in Zone 2 (cross-zone)\n\n";

    // ----------------- TEST CASE 4 -----------------
    cout << "Test 4: No slots available\n";
    ParkingRequest r4(4, 104, 1, 16);
    system.processRequest(r4);
    cout << "Expected: Allocation fails\n\n";

    // ----------------- TEST CASE 5 -----------------
    cout << "Test 5: Invalid state transition\n";
    bool result = r1.transition(RELEASED);
    cout << "Expected: Rejected (0), Actual: " << result << "\n\n";

    // ----------------- TEST CASE 6 -----------------
    cout << "Test 6: Cancel from ALLOCATED state\n";
    ParkingRequest r5(5, 105, 2, 18);
    system.processRequest(r5);
    system.cancelRequest(r5);
    cout << "Expected: Request cancelled & slot restored\n\n";

    // ----------------- TEST CASE 7 -----------------
    cout << "Test 7: Rollback last allocation\n";
    ParkingRequest r6(6, 106, 2, 20);
    system.processRequest(r6);
    system.rollbackLast(1);
    cout << "Expected: Slot released & state reverted\n\n";

    // ----------------- TEST CASE 8 -----------------
    cout << "Test 8: Multiple allocations\n";
    ParkingRequest r7(7, 107, 1, 22);
    ParkingRequest r8(8, 108, 1, 24);
    system.processRequest(r7);
    system.processRequest(r8);
    cout << "Expected: Both allocated if slots exist\n\n";

    // ----------------- TEST CASE 9 -----------------
    cout << "Test 9: Rollback multiple allocations\n";
    system.rollbackLast(2);
    cout << "Expected: Both allocations undone\n\n";

    // ----------------- TEST CASE 10 -----------------
    cout << "Test 10: System stability after rollback\n";
    ParkingRequest r9(9, 109, 1, 26);
    system.processRequest(r9);
    cout << "Expected: System still functional\n\n";

    cout << "===== ALL TEST CASES EXECUTED =====\n";
    return 0;
}
