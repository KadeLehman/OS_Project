#ifndef OS_PROJECT_KERNEL_H
#define OS_PROJECT_KERNEL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "pqueue.h"
#include "pcb.h"
using namespace std;

class kernel {
private:
    pqueue ready, waiting;
public:
    kernel()=default;
    int run();
    void parseString();
    static string readFileIntoString(const string& path);
};


#endif //OS_PROJECT_KERNEL_H

// In modern operating systems, there are separate waiting queues that wait for memory, for i/o, etc.
// However, I only need one waiting queue for this project.