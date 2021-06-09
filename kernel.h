#ifndef OS_PROJECT_KERNEL_H
#define OS_PROJECT_KERNEL_H
#include <iostream>
#include "pqueue.h"
#include "pcb.h"

class kernel {
private:
    pqueue ready, waiting;
public:
    kernel()=default;
    int run();
};


#endif //OS_PROJECT_KERNEL_H
