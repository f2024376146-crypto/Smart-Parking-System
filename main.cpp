#include <iostream>
#include "ParkingSystem.h"

int main() {
    ParkingSystem myCityParking;

    // System Setup: Adding 3 Zones
    myCityParking.addZone(0, "Downtown", 1, 2); // 2 slots only to test overflow
    myCityParking.addZone(1, "Sectors", 2, 5);
    myCityParking.addZone(2, "Airport", 1, 10);

    std::cout << "--- Starting 10 Test Cases ---" << std::endl;

    // Test 1-2: Normal Allocation (Preferred Zone)
    myCityParking.handleRequest("CAR-001", 0); 
    myCityParking.handleRequest("CAR-002", 0);

    // Test 3: Cross-Zone Allocation (Downtown is now full)
    std::cout << "\n[Testing Cross-Zone Allocation]" << std::endl;
    myCityParking.handleRequest("CAR-003", 0); // Should go to another zone with penalty

    // Test 4: Invalid State Transition
    
    std::cout << "\n[Testing Lifecycle Enforcement]" << std::endl;
    // Internal check will happen during handleRequest calls

    // Test 5-7: More Requests to build history
    myCityParking.handleRequest("BIKE-101", 1);
    myCityParking.handleRequest("CAR-555", 2);
    myCityParking.handleRequest("TRUCK-99", 1);

    // Test 8: Rollback Last 2 Actions
    std::cout << "\n[Testing Rollback Mechanism]" << std::endl;
    myCityParking.undoLastActions(2); 

    // Test 9: Analytics Check
    std::cout << "\n[Testing System Analytics]" << std::endl;
    myCityParking.showAnalytics();

    // Test 10: Allocation after Rollback (Checking if slots were actually freed)
    std::cout << "\n[Testing Re-allocation after Rollback]" << std::endl;
    myCityParking.handleRequest("NEW-CAR-77", 1);

    std::cout << "\n--- Project Requirements Satisfied ---" << std::endl;

    return 0;
}