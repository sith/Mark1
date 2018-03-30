//
// Created by Oleksandra Baukh on 2/26/18.
//

#include "MySDFileSystem.h"

Pointer<mark_os::filesystem::File> MySDFileSystem::openFile(const char *path) {
    return Pointer<mark_os::filesystem::File>{nullptr};
}

void MySDFileSystem::deleteFile(const char *path) {

}

void MySDFileSystem::createDirectory(const char *path) {

}
