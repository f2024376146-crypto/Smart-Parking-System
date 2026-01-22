#ifndef ROLLBACK_MANAGER_H
#define ROLLBACK_MANAGER_H

#include "ParkingSlot.h"
#include "ParkingRequest.h"

struct RollbackNode
{
    ParkingSlot* slot;
    ParkingRequest* request;
    RequestState prevState;
    RollbackNode* next;
};

class RollbackManager
{
private:
    RollbackNode* top;

public:
    RollbackManager();
    void push(ParkingSlot* slot, ParkingRequest* req, RequestState prev);
    void rollback(int k);
};

#endif
