#include <string>
#include <list>
#include <iostream>
#include "allocation.h"
#include "allocation.h"

using std::cout;
using std::endl;
int option;

std::list<Chunk> freed, allocated;

void *alloc(size_t chunkSize)
{
    void *ptr = NULL;
    bool found = false;
    Chunk chunkFound;
    int n = 0;
    if (option == FF)
    {
        /*traversing the linked list using an iterator
        till a sufficiently big memory block is found */
        for (std::list<Chunk>::iterator chunk = freed.begin(); chunk != freed.end();
             ++chunk)
        {
            n++;
            if (chunk->chunkSize >= chunkSize)
            {
                found = true;
                chunkFound = *chunk;
                break;
            }
        }
    }
    else if (option == BF)
    {
        int i = 0;
        size_t minBalSize = chunkSize;
        //traversing the linked list using an iterator
        //till a sufficiently big memory block is found
        for (std::list<Chunk>::iterator chunk = freed.begin();
             chunk != freed.end(); ++chunk)
        {
            i++; //counting the nodes

            /* if the current chunk is greater than the required size and
            the difference is less than the minimum difference, we update the chunk found */
            if (chunk->chunkSize >= chunkSize &&
                (chunk->chunkSize - chunkSize) <= minBalSize)
            {
                chunkFound = *chunk;
                n = i;
                minBalSize = chunk->chunkSize - chunkSize; //updating the minumum difference
            }
        }
        //a chunk is found only if the balance is less than the required size
        if (minBalSize < chunkSize)
        {
            found = true;
        }
    }
    else
    {
        int i = 0;
        size_t maxChunkSize = 0;
        for (std::list<Chunk>::iterator chunk = freed.begin();
             chunk != freed.end(); ++chunk)
        {
            i++;
            if (chunk->chunkSize >= maxChunkSize)
            {
                chunkFound = *chunk;
                n = i;
                maxChunkSize = chunk->chunkSize;
            }
        }
        if (maxChunkSize >= chunkSize)
        {
            found = true;
        }
    }
    /*if a matching chunk is found in the freed linked list, 
    memory is allocated from that
    here we can have 2 cases: either the chunk is used as a whole 
    or further divided into two chunks */
    if (found)
    {
        //chunk is being used as a whole because sizes are same
        if (chunkFound.chunkSize == chunkSize)
            allocated.push_back(chunkFound);
        else
        {
            /* we create two partitions of the chunk, one is added to the 
            allocated list and the remaining portion is added to the freed list */
            Chunk c1 = {chunkFound.baseAddress, chunkSize};
            Chunk c2 = {(char *)chunkFound.baseAddress + chunkSize,
                        chunkFound.chunkSize - chunkSize};
            allocated.push_back(c1);
            freed.push_back(c2);
        }

        std::list<Chunk>::iterator tmp = freed.begin();

        //to remove the selected chunk from the freed linked list
        while (--n)
        {
            tmp++;
        }

        freed.erase(tmp);

        return chunkFound.baseAddress;
    }

    /*in case no chunk is found from the freed list,
    fresh memory is allocated from RAM */
    else
    {
        ptr = sbrk(0);
        sbrk(chunkSize);
        Chunk chk = {ptr, chunkSize};
        allocated.push_back(chk);
        return ptr;
    }
}
/*first check if the given address is in the allocated list, 
deallocate it and add it to the freed list
in case the address is not found, generate a fatal error
*/
void dealloc(void *chunk)
{
    bool found = false;
    Chunk temp;
    int n = 0;
    for (std::list<Chunk>::iterator allocatedChunk = allocated.begin();
         allocatedChunk != allocated.end(); ++allocatedChunk)
    {
        ++n;
        if (allocatedChunk->baseAddress == chunk)
        {
            found = true;
            temp = *allocatedChunk;
            break;
        }
    }

    if (found)
    {
        freed.push_back(temp);
        std::list<Chunk>::iterator tmp = allocated.begin();
        while (--n)
        {
            tmp++;
        }

        allocated.erase(tmp);
    }
    else
    {
        cout << "Fatal error: can not deallocate a memory which was never allocated \n";
        exit(0);
    }
}
void showStatus()
{
    int totalAllocatedChunks = 0;
    int totalFreedChunks = 0;
    int n = 1;
    size_t totalAllocatedMem = 0;

    cout << "\nAllocated memory blocks: \n";
    for (std::list<Chunk>::iterator chunk = allocated.begin();
         chunk != allocated.end(); ++chunk)
    {

        cout << "Chunk Number " << n++ << "\nBase Address " << chunk->baseAddress
             << "\nSize " << chunk->chunkSize << endl;
        totalAllocatedMem += chunk->chunkSize;
        totalAllocatedChunks++;
    }
    n = 1;

    cout << "\nFree memory blocks: \n";
    for (std::list<Chunk>::iterator chunk = freed.begin(); chunk != freed.end(); ++chunk)
    {

        cout << "Chunk Number " << n++ << "\nBase Address " << chunk->baseAddress
             << "\nSize " << chunk->chunkSize << endl;
        totalAllocatedMem += chunk->chunkSize;
        totalFreedChunks++;
    }

    cout << "\n\n**********Status Summary**********" << endl;
    cout << "Total Allocated Memory: " << totalAllocatedMem
         << "\nTotal Allocated Chunks: " << totalAllocatedChunks
         << "\nTotal Freed Chunks: " << totalFreedChunks;
    cout << endl;

}
