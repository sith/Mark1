//
// Created by Oleksandra Baukh on 12/22/17.
//

#include "Process.h"


void framework::Process::addChildProcess(framework::Process *process) {
    }

void framework::Process::deleteChildProcess(framework::Process *process) {

}

void framework::Process::runChildProcesses() {

}

void framework::Process::run() {
    runCurrentProcess();
    runChildProcesses();
}
