#include "pqueue.h"

void pqueue::enqueue(const pcb& block, int pos) {
    if (pos < 0) {
        q.push_back(block);
        return;
    }
    it = q.begin();
    advance(it, pos);
    q.insert(it, block);
}

void pqueue::dequeue(int pos) {
    if (pos < 0) {
        q.pop_front();
        return;
    }
    it = q.begin();
    advance(it, pos);
    q.erase(it);
}

int pqueue::position(int pid) {
    // Counter will track the position of the current pcb being checked for a matching process_id.
    int counter = 0;
    for (const pcb& block : q) {
        if (block.getPid() == pid) {
            return counter;
        }
        counter++;
    }
    cout << "Error in pqueue::position(int pid) -> requested pid does not match to any PCB in this process queue." << endl;
    exit(EXIT_FAILURE);
}

int pqueue::size() {
    return q.size();
}

void pqueue::print() {
    for (const pcb& block : q) {
        block.print();
    }
    cout << endl;
}

void pqueue::clear() {
    q.clear();
}

// Returns the average waiting time for the "shortest job first" scheduling algorithm.
int pqueue::sjf() {

    return 0;
}
