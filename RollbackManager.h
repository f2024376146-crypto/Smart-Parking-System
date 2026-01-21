#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H
#include "ParkingSlot.h"

struct HistoryNode {
    ParkingSlot* slotPtr;
    HistoryNode* next;
};

class RollbackManager {
private:
    HistoryNode* top;

public:
    RollbackManager();
    void pushAction(ParkingSlot* slot);
    void undoLastAction();
};
#endif