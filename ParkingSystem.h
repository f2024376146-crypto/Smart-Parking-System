#ifndef PARKING_SYSTEM_H
#define PARKING_SYSTEM_H

#include "Zone.h"
#include "AllocationEngine.h"
#include "RollbackManager.h"
#include "ParkingRequest.h"

struct RequestNode {
    ParkingRequest* req;
    RequestNode* next;
};

class ParkingSystem
{
private:
    Zone* zones;
    int zoneCount;
    AllocationEngine allocator;
    RollbackManager rollbackMgr;

    RequestNode* front;
    RequestNode* rear;

    int totalRequests;
    int failedRequests;

public:
    ParkingSystem(Zone* zones, int count);

    void enqueue(ParkingRequest* req);
    void processNext();
    void processRequest(ParkingRequest& request);
    void rollbackLast(int k);

    void printAnalytics() const;
};

#endif
