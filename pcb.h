#ifndef OS_PROJECT_PCB_H
#define OS_PROJECT_PCB_H
#include <iostream>
#include <list>
#include <string>
#include <utility>
using namespace std;

// Process Control Block
class pcb {
private:
    int id;
    int priority;
    string name;
    // int programCounter;
    // list<string> openFiles;
public:
    pcb(int id, int priority, string name);
    void print() const;
};


#endif //OS_PROJECT_PCB_H
