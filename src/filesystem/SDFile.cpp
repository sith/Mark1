//
// Created by Oleksandra Baukh on 2/26/18.
//

#include "SDFile.h"
#include <memory/move.h>
#include <memory/Pointer.h>
#include <string/String.h>

int SDFile::readInt() {
    return 0;
}

Pointer<const char *> SDFile::readString() {
    const char *string = "asdf";
    Pointer<const char *> pointer{nullptr};
    return mark_os::memory::move(pointer);
}
