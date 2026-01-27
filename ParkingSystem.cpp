#include "ParkingSystem.h"
#include "AllocationEngine.h"
#include <iostream>

using namespace std;

ParkingSystem::ParkingSystem() : requestCount(0) {
    for (int i = 0; i < 3; i++) {
        zones[i] = new Zone(i);
        zones[i]->addParkingArea(new ParkingArea(i * 10, i));
    }
}

ParkingSystem::~ParkingSystem() {
    for (int i = 0; i < 3; i++) delete zones[i];
}

void ParkingSystem::allocate(int vID, int zID) {
    if (zID < 0 || zID > 2) {
        cout << "Invalid Zone!" << endl;
        return;
    }
    ParkingSlot* slot = AllocationEngine::findSlot(zones, zID);
    if (slot) {
        int rIdx = requestCount++;
        slot->isAvailable = false;
        requests[rIdx].vehicleID = vID;
        requests[rIdx].allocatedSlotID = slot->slotID;
        requests[rIdx].state = ALLOCATED;
        cout << "SUCCESS: Vehicle " << vID << " allocated Slot " << slot->slotID << endl;
        cout << ">> YOUR REQUEST INDEX IS: " << rIdx << " (Use this to Release)" << endl;
        rb.record(rIdx, slot->slotID, zID, REQUESTED);
    } else {
        cout << "Sorry, no slots available in Zone " << zID << endl;
    }
}

void ParkingSystem::release(int rIdx) {
    if (rIdx >= 0 && rIdx < requestCount) {
        if (requests[rIdx].state != RELEASED) {
            requests[rIdx].state = RELEASED;
            cout << "SUCCESS: Slot " << requests[rIdx].allocatedSlotID << " is now free." << endl;
        } else {
            cout << "[!] ERROR: Slot already released." << endl;
        }
    } else {
        cout << "[!] ERROR: Invalid Request Index " << rIdx << endl;
    }
}

void ParkingSystem::rollback(int k) {
    cout << "--- Undoing last " << k << " operations ---" << endl;
    for (int i = 0; i < k && !rb.isEmpty(); i++) {
        RollbackAction act = rb.pop();
        cout << "Rollback Successful for Index " << act.reqIdx << endl;
    }
}

void ParkingSystem::showAnalytics() {
    cout << "\n--- Analytics Report ---\nTransactions: " << requestCount << "/20" << endl;
}

void ParkingSystem::runAutomatedTests() {
    cout << "\n>>>> RUNNING 10 AUTOMATED TEST CASES <<<<\n";
    cout << "\n[Test 1] Allocate Vehicle 101 to Zone 0:"; allocate(101, 0);
    cout << "\n[Test 2] Allocate Vehicle 102 to Zone 2:"; allocate(102, 2);
    cout << "\n[Test 3] Testing Invalid Zone 5:"; allocate(103, 5);
    cout << "\n[Test 4] Allocate Vehicle 104 to Zone 0 (Next Slot):"; allocate(104, 0);
    cout << "\n[Test 5] Release Request Index 0:"; release(0);
    cout << "\n[Test 6] Try Releasing Index 0 again:"; release(0);
    cout << "\n[Test 7] Rollback last 1 operation:"; rollback(1);
    cout << "\n[Test 8] Releasing non-existent Index 99:"; release(99);
    cout << "\n[Test 9] Displaying System Analytics:"; showAnalytics();
    cout << "\n[Test 10] Filling Zone 1 (Max 5 slots):";
    for(int i=0; i<6; i++) allocate(200+i, 1);
    cout << "\n>>>> TEST SUITE COMPLETED <<<<\n";
}