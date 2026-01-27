#ifndef ROLLBACKMANAGER_H
#define ROLLBACKMANAGER_H
#include "Enums.h"
struct RollbackAction { int reqIdx, sID, zID; RequestState pState; };
class RollbackManager {
    RollbackAction history[100];
    int top;
public:
    RollbackManager();
    void record(int r, int s, int z, RequestState st);
    bool isEmpty();
    RollbackAction pop();
};
#endif