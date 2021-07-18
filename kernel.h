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
    // In modern operating systems, there are separate waiting queues that wait for memory, for i/o, etc.
    // Schedulers typically dispatch processes in the ready queue to the running queue.
    // Because my project only requires calculations for fictional processes, I just need one queue.
    pqueue ready;
public:
    kernel()=default;
    int run();
    void parseFile();
    static string readFileIntoString(const string& path);
    void compareAlgorithms();
};


#endif //OS_PROJECT_KERNEL_H
