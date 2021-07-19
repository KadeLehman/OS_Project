#include "pqueue.h"

pqueue::pqueue() {
    clock = 0;
}

void pqueue::resetClock() {
    clock = 0;
}

void pqueue::enqueue(const pcb& block, int pos) {
    if (pos < 0) {
        q.push_back(block);
        return;
    }
    it = q.begin();
    advance(it, pos);
    q.insert(it, block);
}

void pqueue::dequeue(int pos) {
    if (pos < 0) {
        q.pop_front();
        return;
    }
    it = q.begin();
    advance(it, pos);
    q.erase(it);
}

/// Returns the position of the process with given identifier.
int pqueue::position(int pid) {
    // NOTE: Counter will track the position of the current pcb being checked for a matching process_id.
    int counter = 0;
    for (const pcb& block : q) {
        if (block.getPid() == pid) {
            return counter;
        }
        counter++;
    }
    cout << "Error in pqueue::position(int pid) -> requested pid does not match to any PCB in this queue." << endl;
    exit(EXIT_FAILURE);
}

void pqueue::print() {
    for (const pcb& block : q) {
        block.print();
    }
    cout << endl;
}

void pqueue::clear() {
    q.clear();
}

/// Returns the average waiting time of all processes in this queue when using "shortest job first" scheduling.
double pqueue::sjf() {

    /// Initialize variables before while loop.
    unsigned processBeginTime;
    unsigned totalWaitTime = 0;
    unsigned numProcesses = q.size();
    bool noneArrived = true;
    bool firstProcessExecuted = false;
    unsigned waitTimeFirstProcess = 0;

    /// Exhaust the entire queue.
    while (!q.empty()) {

        /// Keep track of time.
        processBeginTime = clock;

        /// Determine which processes have arrived and are ready for execution (according to the input file).
        for (pcb& block : q) {
            if (block.getArrivalTime() >= clock) {
                block.markArrived();
                noneArrived = false;
            }
        }

        /// If no processes have arrived yet, keep track of time and loop back.
        if (noneArrived) {
            waitTimeFirstProcess += 1;
            continue;
        }

        /// Find the process that will take the least amount of time to complete.
        int lowest = std::numeric_limits<int>::max(); // Very big number, effectively infinity.
        int position = 0;
        for (const pcb& block : q) {
            if (block.isArrived() && (block.getBurstTime() < lowest)) {
                lowest = block.getBurstTime();
                position = this->position(block.getPid());
            }
        }

        /// Execute that process; accumulate wait time.
        if (!firstProcessExecuted) { // First process wait time dependent upon arrival_time only.
            dequeue(position);
            firstProcessExecuted = true;
            totalWaitTime += waitTimeFirstProcess;
            continue;
        }
        clock += lowest; // Processes after the first one have wait time also dependent upon previous burst_time.
        dequeue(position);
        totalWaitTime += clock - processBeginTime;
    }
    return static_cast<double>(totalWaitTime) / numProcesses;
}
