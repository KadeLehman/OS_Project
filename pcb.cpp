#include "pcb.h"
#include <ctime>

pcb::pcb() {
    priority = rand() % 4 + 1;
}

void pcb::print() {
    cout << priority << endl;
}
