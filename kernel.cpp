#include "kernel.h"

int kernel::run() {
    // Handling user input and processes.
    // Manipulating queues by using enqueue + dequeue.

    pcb a,b,c;

    // My pqueue works completely now :)
    ready.enqueue(a);
    ready.print();
    ready.enqueue(b);
    ready.print();
    ready.enqueue(c,1);
    ready.print();
    ready.enqueue(a,0);
    ready.print();

    ready.dequeue(2);
    ready.print();
    ready.dequeue(0);
    ready.print();

    return 0;
}
