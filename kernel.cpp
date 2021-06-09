#include "kernel.h"

// Handles user input and processes; manipulates queues by using enqueue + dequeue.
int kernel::run() {

    pcb a(1,4),
        b(2,2),
        c(3,1);

    // My process queue properly enqueues and dequeues.
    ready.enqueue(a);
    ready.print();
    ready.enqueue(b);
    ready.print();
    ready.enqueue(c,1);
    ready.print();

    ready.dequeue(2);
    ready.print();
    ready.dequeue(0);
    ready.print();

    return 0;
}
