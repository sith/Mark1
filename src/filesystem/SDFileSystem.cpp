//
// Created by Oleksandra Baukh on 2/26/18.
//

#include "SDFileSystem.h"

Pointer<File> SDFileSystem::openFile(const char *path) {
    return Pointer<File>{nullptr};
}

void SDFileSystem::deleteFile(const char *path) {

}

void SDFileSystem::createDirectory(const char *path) {

}

Pointer<List<Pointer<File>>> SDFileSystem::listFiles() {
    return Pointer<List<Pointer<File>>>(nullptr);
}
