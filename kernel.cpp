/// Sources:
/* https://www.delftstack.com/howto/cpp/read-csv-file-in-cpp/
 *   readFileIntoString() - slightly modified (for file closure)
 *   parseString() - moderately modified (for recording data into new PCB's)
 */

#include "kernel.h"

// Handles file input and processes; manipulates queues by using enqueue + dequeue.
int kernel::run() {
    parseString();
    ready.print();
    hardCodedClear();
    hardCodeTest();
    return 0;
}

void kernel::parseString() {
    string id,priority,name;
    string filename("processes.csv");
    string file_contents;
    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    string record;

    while (getline(sstream, record)) {
        istringstream line(record);
        while (getline(line, record, delimiter)) {
            id = record;
            getline(line, record, delimiter);
            priority = record;
            getline(line, record, delimiter);
            name = record;
            pcb tmp(stoi(id), stoi(priority), name);
            ready.enqueue(tmp);
        }
    }
}

void kernel::hardCodedClear() {
    ready.dequeue();
    ready.dequeue();
    ready.dequeue();
}

string kernel::readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    string fileContents = ss.str();
    input_file.close();
    return fileContents;
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