#include "Zone.h"
Zone::Zone(int id) : zoneId(id), head(nullptr) {}
Zone::~Zone() {
    AreaNode* current = head;
    while(current) {
        AreaNode* next = current->next;
        delete current->area;
        delete current;
        current = next;
    }
}
void Zone::addParkingArea(ParkingArea* area) {
    head = new AreaNode{area, head};
}
ParkingSlot* Zone::findSlotInZone() {
    AreaNode* curr = head;
    while(curr) {
        ParkingSlot* s = curr->area->findAvailableSlot();
        if(s) return s;
        curr = curr->next;
    }
    return nullptr;
}