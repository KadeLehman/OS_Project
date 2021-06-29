/// Sources:
/* https://www.tutorialspoint.com/How-to-read-and-parse-CSV-files-in-Cplusplus
 *   parseCSVLine()
 *
 */

#include "kernel.h"

// Handles user input and processes; manipulates queues by using enqueue + dequeue.
int kernel::run() {

    ifstream myFile("processes.txt");
    if(!myFile.is_open()) {
        cout << "Input file was not opened." << endl;
        exit(EXIT_FAILURE);
    }

    string id,priority,name;

    // TODO: Reading from file.
    // 1. setup first
    // 2. while getline isn't null, parse line using parseCSVLine

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

string kernel::readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - "
             << path << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}