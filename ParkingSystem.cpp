#include "ParkingSystem.h"
#include <iostream>
using namespace std;

ParkingSystem::ParkingSystem(Zone* z, int count)
{
    zones = z;
    zoneCount = count;
    front = rear = nullptr;
    totalRequests = 0;
    failedRequests = 0;
}

void ParkingSystem::enqueue(ParkingRequest* req)
{
    RequestNode* node = new RequestNode{req, nullptr};
    if (!rear)
        front = rear = node;
    else
    {
        rear->next = node;
        rear = node;
    }
}

void ParkingSystem::processNext()
{
    if (!front) return;

    ParkingRequest* req = front->req;
    RequestNode* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;

    ParkingSlot* slot = allocator.allocate(zones, zoneCount, req->getZoneId());
    if (slot)
    {
        rollbackMgr.push(slot, req, req->getState());
        slot->occupy();
        req->transition(ALLOCATED);
    }
    else
    {
        failedRequests++;
    }
    totalRequests++;
}

void ParkingSystem::processRequest(ParkingRequest& request)
{
    enqueue(&request);
    processNext();
}

void ParkingSystem::rollbackLast(int k)
{
    rollbackMgr.rollback(k);
}

void ParkingSystem::printAnalytics() const
{
    cout << "\n--- ANALYTICS ---\n";
    cout << "Total Requests: " << totalRequests << endl;
    cout << "Failed Requests: " << failedRequests << endl;
}
