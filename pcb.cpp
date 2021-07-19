#include "pcb.h"

pcb::pcb(int process_id, int arrival_time, int burst_time, int priority) {
    this->process_id = process_id;
    this->arrival_time = arrival_time;
    this->burst_time = burst_time;
    this->priority = priority;
    this->arrived = false;
}

int pcb::getPid() const {
    return this->process_id;
}

int pcb::getArrivalTime() const {
    return this->arrival_time;
}

int pcb::getBurstTime() const {
    return this->burst_time;
}

int pcb::getPriority() const {
    return this->priority;
}

bool pcb::isArrived() const {
    return this->arrived;
}

void pcb::markArrived() {
    arrived = true;
}

void pcb::markNotArrived() {
    arrived = false;
}

void pcb::print() const {
    cout << "process_id: " << this->process_id
         << ", arrival_time: " << this->arrival_time
         << ", burst_time: " << this->burst_time
         << ", priority: " << this->priority << endl;
}
