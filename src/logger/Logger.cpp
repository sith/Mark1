//
// Created by Oleksandra Baukh on 12/20/17.
//

#include "Logger.h"
#include "SerialLogger.h"

unsigned long Logger::cycle = 0;

Logger *Logger::createLogger(char *name) {
    return new SerialLogger(name);
}

void Logger::nextCycle() {
    cycle++;
}

unsigned long Logger::getCycle() {
    return cycle;
}
