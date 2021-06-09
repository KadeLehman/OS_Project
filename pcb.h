#ifndef OS_PROJECT_PCB_H
#define OS_PROJECT_PCB_H
#include <iostream>
using namespace std;

// Process Control Block
class pcb {
private:
    int id;
    int priority;
public:
    pcb(int id, int priority);
    void print() const;
};


#endif //OS_PROJECT_PCB_H
