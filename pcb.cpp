#include "pcb.h"

pcb::pcb(int id, int priority, string name) {
    this->id = id;
    this->priority = priority;
    this->name = move(name);
}

void pcb::print() const {
    cout << "id: " << this->id
         << ", priority: " << this->priority
         << ", name: " << this->name << endl;
}
