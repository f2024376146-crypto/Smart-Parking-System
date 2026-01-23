#include "Zone.h"
#include <iostream>

using namespace std;

Zone::Zone(int id) : zoneId(id), head(nullptr), adjacentZones(nullptr), adjCount(0) {}


Zone::~Zone() {
    /
    AreaNode* current = head;
    while (current != nullptr) {
        AreaNode* nextNode = current->next;
        
        delete current; 
        current = nextNode;
    }

    
    if (adjacentZones != nullptr) {
        delete[] adjacentZones;
        adjacentZones = nullptr;
    }
}

void Zone::addParkingArea(ParkingArea* area) {
    AreaNode* newNode = new AreaNode;
    newNode->area = area;
    newNode->next = head;
    head = newNode;
}

void Zone::setAdjacentZones(int* zones, int count) {
    adjCount = count;
    adjacentZones = new int[count];
    for (int i = 0; i < count; i++) {
        adjacentZones[i] = zones[i];
    }
}


ParkingSlot* Zone::findSlotInZone() {
    AreaNode* current = head;
    while (current != nullptr) {
        ParkingSlot* slot = current->area->getFirstFreeSlot();
        if (slot != nullptr) {
            return slot;
        }
        current = current->next;
    }
    return nullptr; 
}