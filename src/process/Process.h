//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_PROCESS_H
#define MARK1_PROCESS_H

#include <StandardCplusplus.h>
#include <list>

namespace framework {
    class Process {
    private:
        std::list<Process *> childProcesses;

        void addProcess(Process *process);

        void deleteProcess(Process *process);

        void runChildProcesses();

        virtual void runCurrentProcess()=0;

    public:
         void run();

    };

}
#endif //MARK1_PROCESS_H

