#include "pcb.h"

pcb::pcb(string name, int id, int priority) {
    this->name = name;
    this->id = id;
    this->priority = priority;
}

void pcb::print() const {
    cout << "id: " << this->id
         << ", priority: " << this->priority
         << ", name: " << this->name << endl;
}
