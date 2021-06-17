#ifndef OS_PROJECT_PQUEUE_H
#define OS_PROJECT_PQUEUE_H
#include <iostream>
#include <list>
#include "pcb.h"
using namespace std;

// Process Queue
class pqueue {
private:
    list<pcb> q;
    list<pcb>::iterator it;
public:
    pqueue()=default;
    void enqueue(const pcb&, int pos = -1);
    void dequeue(int pos = -1);
    void print();
};


#endif //OS_PROJECT_PQUEUE_H
