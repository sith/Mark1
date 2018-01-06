//
// Created by Oleksandra Baukh on 12/25/17.
//

#include "ArrayList.h"

template<class T>
void util::ArrayList<T>::add(T &t) {

}

template<class T>
void util::ArrayList<T>::add(int index, T &t) {

}

template<class T>
T *util::ArrayList<T>::get(int index) {
    return nullptr;
}

template<class T>
T *util::ArrayList<T>::remove(int index) {
    return nullptr;
}

template<class T>
T *util::ArrayList<T>::remove(T &t) {
    return nullptr;
}

template<class T>
int util::ArrayList<T>::size() {
    return 0;
}

template<class T>
util::ArrayList<T>::ArrayList() {
    array = new T[16];
    lastIndex = 0;
}

template<class T>
util::ArrayList<T>::ArrayList(int size) {
    array = new T[size];
    lastIndex = 0;
}
