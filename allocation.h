#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <unistd.h>
#include <cstdlib>
#include <stddef.h>

#define FF 1
#define BF 2
#define WF 3

struct Chunk
{
    void *baseAddress;
    size_t chunkSize;
};

void *alloc(size_t chunkSize);

void dealloc(void *chunk);

void showStatus();

#endif
