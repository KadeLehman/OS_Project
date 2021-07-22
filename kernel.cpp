/// Sources:
/* https://www.delftstack.com/howto/cpp/read-csv-file-in-cpp/
 *   readFileIntoString() - slightly modified (for file closure)
 *   parseString() - moderately modified (for recording data into new PCB's)
 */

#include "kernel.h"

/// Handles file input and processes; manipulates ready queue by using enqueue + dequeue.
int kernel::run() {
    parseFile();
    ready.print();
    readyCopy = ready;
    compareAlgorithms();
    return 0;
}

/// Processes the input file to create process control blocks.
void kernel::parseFile() {
    string process_id,arrival_time,burst_time,priority;
    string filename("processes.csv");
    string file_contents;
    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    string record;

    while (getline(sstream, record)) {
        istringstream line(record);

        /// Read and copy each line from file into its own new PCB.
        while (getline(line, record, delimiter)) {
            process_id = record;
            getline(line, record, delimiter);
            arrival_time = record;
            getline(line, record, delimiter);
            burst_time = record;
            getline(line, record, delimiter);
            priority = record;
            pcb tmp(stoi(process_id), stoi(arrival_time), stoi(burst_time), stoi(priority));
            ready.enqueue(tmp);
        }
    }
}

/// Reads the given file into a single returned string.
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

/// Calculates and prints the average waiting time of each scheduling algorithm.
void kernel::compareAlgorithms() {
    double avgWaitTimeSJF = ready.sjf();
    double avgWaitTimeNPPS = readyCopy.npps();
    cout << "Average wait time for SJF: " << avgWaitTimeSJF << endl;
    cout << "Average wait time for NPPS: " << avgWaitTimeNPPS << endl;
    // future improvement: Logic for "algo was x seconds less average wait time than the other algo"
}
