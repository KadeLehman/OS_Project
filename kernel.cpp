/// Sources:
/* https://www.tutorialspoint.com/How-to-read-and-parse-CSV-files-in-Cplusplus
 *   parseCSVLine()
 */

#include "kernel.h"

// Handles user input and processes; manipulates queues by using enqueue + dequeue.
int kernel::run() {

    ifstream myFile("processes.txt");
    if(!myFile.is_open()) {
        cout << "Could not open input file." << endl;
        exit(EXIT_FAILURE);
    }
    string line,id,priority,name;

    // TODO: while getline, parse line using parseCSVLine
    while (getline(myFile,line)) {

    }

    myFile.close();
    hardCodeTest();
    return 0;
}

vector<string> kernel::parseCSVLine(string line){
    // stringstream
}

void kernel::hardCodeTest() {

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
}