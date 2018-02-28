//
// Created by Oleksandra Baukh on 2/25/18.
//

#ifndef MARK1_SRAMMEMORYMONITOR_H
#define MARK1_SRAMMEMORYMONITOR_H


#include <memory/MemoryMonitor.h>

class SRAMMemoryMonitor : public MemoryMonitor{
public:
    int available() override;
};


#endif //MARK1_SRAMMEMORYMONITOR_H
