#include "pcb.h"

pcb::pcb(int process_id, int arrival_time, int burst_time, int priority) {
    this->process_id = process_id;
    this->arrival_time = arrival_time;
    this->burst_time = burst_time;
    this->priority = priority;
}

void pcb::print() const {
    cout << "process_id: " << this->process_id
         << ", arrival_time: " << this->arrival_time
         << ", burst_time: " << this->burst_time
         << ", priority: " << this->priority << endl;
}
