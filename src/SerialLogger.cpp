#include <Arduino.h>
#include "Logger.h"

class SerialLogger : public Logger {
public:
    SerialLogger() {
        Serial.println("Logger started");
    }

    ~SerialLogger() {
        Serial.println("SerialLogger stopped");
    }

    Logger *logAppend(const int number) override {
        Serial.print(number);
        return this;

    }

    Logger *logAppend(const char *c) override {
        Serial.print(c);
        return this;

    }

    Logger *newLine() override {
        Serial.println();
        return this;
    }
};