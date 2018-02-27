#include "SRAMMemoryMonitor.h"
#include <MemoryFree.h>

int SRAMMemoryMonitor::available() {
    return freeMemory();
}
