#ifndef OS_PROJECT_PCB_H
#define OS_PROJECT_PCB_H
#include <iostream>
#include <list>
#include <string>
using namespace std;

// Process Control Block
class pcb {
private:
    string name;
    int id;
    int priority;
    // int programCounter;
    // list<string> openFiles;
public:
    pcb(string name, int id, int priority);
    void print() const;
};


#endif //OS_PROJECT_PCB_H
