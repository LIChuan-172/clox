#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"
#include "object.h"

#define ALLOCATE(type, count) \
  (type *)reallocate(NULL, 0, sizeof(type) * (count))

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type *)reallocate(pointer, sizeof(type) * (oldCount), sizeof(type) * (newCount)) 

#define FREE_ARRAY(type, pointer, oldCount) \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

/**
 * This reallocate() function is the single function we'll use for all dynamic
 * memory management in clox -- allocating memory, freeing it, and changing the size
 * of an existing allocation. Routing all of those operations through a single function
 * will be important later when we add a garbage collector that needs to keep track of how
 * much memory is in use.
 * 
 * The two size arguments passed to reallocate() control which operation to perform:
 * 
 * oldSize      newSize               Operation
 * 0            Non-zero              Allocate new block
 * Non-zero     0                     Free allocation
 * Non-zero     Smaller than oldSize  Shrink existing allocation
 * Non-zero     Larger than oldSize   Grow existing allocation  
 */
void * reallocate(void *pointer, size_t oldSize, size_t newSize);
void freeObjects();

#endif
