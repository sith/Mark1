//
// Created by Oleksandra Baukh on 12/20/17.
//

#ifndef MARK1_SERIALLOGGER_H
#define MARK1_SERIALLOGGER_H


#include <HardwareSerial.h>
#include <logger/Logger.h>


class SerialLogger : public Logger {
private:
    const char *name;
public:

    SerialLogger(const char *name);

    Logger *logAppend(int number) override;

    Logger *logAppend(long number) override;

    Logger *logAppend(const char *c) override;

    Logger *newLine() override;

};

#endif //MARK1_SERIALLOGGER_H
