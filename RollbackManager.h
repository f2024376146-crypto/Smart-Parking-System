#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H

#include "ParkingSlot.h"
#include "ParkingRequest.h"


struct RollNode {
    ParkingSlot* slot;
    ParkingRequest* req;
    RequestState prevState; 
    RollNode* next;
};

class RollbackManager {
private:
    RollNode* top; 

public:
    RollbackManager();
    ~RollbackManager(); 

    
    RollbackManager(const RollbackManager& other) = delete;
    RollbackManager& operator=(const RollbackManager& other) = delete;

    void push(ParkingSlot* s, ParkingRequest* r, RequestState p);
    void rollback(int k);
    bool isEmpty() const { return top == nullptr; }
};

#endif