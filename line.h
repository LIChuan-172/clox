#ifndef clox_line_h
#define clox_line_h

#include "common.h"

typedef struct
{
  int num;
  int repeat;
} Line;

typedef struct
{
  int capacity;
  int count;
  Line *lines;
} LineArray;

void initLineArray(LineArray *array);
void setLine(LineArray *array, int num);
int getLine(LineArray *array, int offset);
void freeLineArray(LineArray *array);

#endif
