//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_PROCESS_H
#define MARK1_PROCESS_H

namespace framework {
    class Process {
    private:
        Process *childProcesses;

        void addChildProcess(Process *process);

        void deleteChildProcess(Process *process);

        void runChildProcesses();

        virtual void runCurrentProcess()=0;

    public:
        void run();

    };

}
#endif //MARK1_PROCESS_H

