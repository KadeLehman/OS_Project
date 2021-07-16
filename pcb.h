#ifndef OS_PROJECT_PCB_H
#define OS_PROJECT_PCB_H
#include <iostream>
using namespace std;

// Process Control Block
class pcb {
private:
    int process_id;
    int arrival_time;
    int burst_time;
    int priority;
public:
    pcb(int,int,int,int);
    int getPid() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getPriority() const;
    void print() const;
};


#endif //OS_PROJECT_PCB_H
