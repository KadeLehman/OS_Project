#ifndef OS_PROJECT_PQUEUE_H
#define OS_PROJECT_PQUEUE_H
#include <iostream>
#include <list>
#include <limits>
#include "pcb.h"
using namespace std;

// Process Queue
class pqueue {
private:
    list<pcb> q;
    list<pcb>::iterator it;
    unsigned clock;
public:
    pqueue();
    void resetClock();
    void enqueue(const pcb&, int pos = -1);
    void dequeue(int pos = -1);
    int position(int pid);
    void print();
    void clear();
    double sjf();
};


#endif //OS_PROJECT_PQUEUE_H
