#ifndef OS_PROJECT_PCB_H
#define OS_PROJECT_PCB_H
#include <iostream>
using namespace std;

// Process Control Block
class pcb {
private:
    int priority;
public:
    pcb();
    void print();
};


#endif //OS_PROJECT_PCB_H
