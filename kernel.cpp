/// Sources:
/* https://www.delftstack.com/howto/cpp/read-csv-file-in-cpp/
 *   String parsing code (moderately modified)
 *   readFileIntoString() (slightly modified)
 */

#include "kernel.h"

// Handles user input and processes; manipulates queues by using enqueue + dequeue.
int kernel::run() {

    ifstream myFile("processes.txt");
    if(!myFile.is_open()) {
        cout << "Input file was not opened." << endl;
        return 1;
    }

    string id,priority,name;

    // TODO: Reading from file.
    //

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

string kernel::readFileIntoString(const string& fileName) {
    auto ss = ostringstream{};
    ifstream input_file(fileName);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - "
             << fileName << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}