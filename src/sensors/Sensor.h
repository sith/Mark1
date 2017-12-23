//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_SENSOR_H
#define MARK1_SENSOR_H

template<typename T>
class Sensor {

    T data;
public:
    virtual T readSensorData() =0;

    const void read() {
        T data = readSensorData();
    }

    const T getData() {
        return data;
    };
};


#endif //MARK1_SENSOR_H
