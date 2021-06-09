#include "pcb.h"
#include <ctime>

pcb::pcb(int id, int priority) {
    this->id = id;
    this->priority = priority;
}

void pcb::print() const {
    cout << "id: " << this->id << ", priority: " << this->priority << endl;
}
