#include "kernel.h"

// Handles user input and processes; manipulates queues by using enqueue + dequeue.
int kernel::run() {

    ifstream myFile("processes.txt");
    if(!myFile.is_open()) {
        cout << "Input file was not opened." << endl;
        return 1;
    }

    // TODO: Reading from file.
    // Write code here.

    myFile.close();

    // Hard-coded test input:
    pcb a(1,4,"Write"),
        b(2,2,"ReadLine"),
        c(3,1,"ReadFile");

    cout << "~~~~ Begin test results ~~~~\n" << endl;

    // My process queue properly enqueues and dequeues:
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

    cout << "~~~~ End of test results ~~~~" << endl;

    return 0;
}
