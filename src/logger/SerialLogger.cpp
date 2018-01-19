#include <Arduino.h>
#include "os/logger/Logger.h"
#include "SerialLogger.h"

Logger *SerialLogger::logAppend(const int number) {
    Serial.print(number);
    return this;
}

Logger *SerialLogger::logAppend(const char *c) {
    Serial.print(c);
    return this;

}

Logger *SerialLogger::newLine() {
    Serial.println();
    Serial.print("#");
//    Serial.print(Logger::getCycle());
    Serial.print(":\t");
    Serial.print(name);
    Serial.print(":\t");
    return this;
}


SerialLogger::SerialLogger(const char *name) : name(name) {}
