#include "pqueue.h"

void pqueue::enqueue(pcb block, int pos) {
    if(pos < 0) {
        q.push_back(block);
        return;
    }
    it = q.begin();
    advance(it, pos);
    q.insert(it, block);
}

void pqueue::dequeue(int pos) {
    if(pos < 0) {
        q.pop_front();
        return;
    }
    it = q.begin();
    advance(it, pos);
    q.erase(it);
}

void pqueue::print() {
    for (pcb block : q) {
        block.print();
    }
    cout << endl;
}
