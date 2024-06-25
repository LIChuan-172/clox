#include "memory.h"
#include "line.h"

void initLineArray(LineArray *array)
{
  array->capacity = 0;
  array->count = 0;
  array->lines = NULL;
}

void setLine(LineArray *array, int num)
{
  if (array->count > 0 && array->lines[array->count - 1].num == num)
  {
    array->lines[array->count - 1].repeat++;
    return;
  }

  if (array->capacity < array->count + 1)
  {
    int oldCapacity = array->capacity;
    array->capacity = GROW_CAPACITY(oldCapacity);
    array->lines = GROW_ARRAY(Line, array->lines, oldCapacity, array->capacity);
  }

  array->lines[array->count].num = num;
  array->lines[array->count].repeat = 1;
  array->count++;
}

int getLine(LineArray *array, int offset)
{
  int index = 0;
  int chunkCount = 0;
  while (index < array->count)
  {
    chunkCount += array->lines[index].repeat;
    if (chunkCount > offset)
    {
      return array->lines[index].num;
    }
    index++;
  }
  return -1;
}

void freeLineArray(LineArray *array)
{
  FREE_ARRAY(Line, array->lines, array->capacity);
  initLineArray(array);
}
