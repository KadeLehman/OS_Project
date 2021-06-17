#include "kernel.h"

// Handles user input and processes; manipulates queues by using enqueue + dequeue.
int kernel::run() {

    // TODO: File or user input. I'll likely choose to make a file for file input.

    pcb a("Write",1,4),
        b("ReadLine",2,2),
        c("ReadFile",3,1);

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
