//
// Created by Oleksandra Baukh on 12/22/17.
//

#include "Process.h"


void framework::Process::addProcess(framework::Process *process) {
    childProcesses.insert(childProcesses.end(), process);
}

void framework::Process::deleteProcess(framework::Process *process) {
    childProcesses.remove(process);
}

void framework::Process::runChildProcesses() {
    for (auto &&process : childProcesses) {
        process->run();
    }
}

void framework::Process::run() {
    runCurrentProcess();
    runChildProcesses();
}
