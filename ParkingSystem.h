#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H
#include "Zone.h"
#include "ParkingRequest.h"
#include "RollbackManager.h"

class ParkingSystem {
    Zone* zones[3];
    ParkingRequest requests[20];
    int requestCount;
    RollbackManager rb;
public:
    ParkingSystem();
    ~ParkingSystem();
    void allocate(int vID, int zID);
    void release(int rIdx);
    void rollback(int k);
    void showAnalytics();
    void runAutomatedTests(); 
};
#endif