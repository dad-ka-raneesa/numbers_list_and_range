#ifndef __RANGE_H_
#define __RANGE_H_

#define FOR(start, limit) for (Index i = start; i < limit; i++)

typedef unsigned int Index;
typedef struct
{
  int *values;
  int length;
} Int_Array;

typedef Int_Array *Int_Arrays;

typedef enum
{
  BELOW,
  IN,
  ABOVE
} Position;

Int_Arrays seperated_by_range(int *numbers, int length, int start_from, int upto);
Int_Array *create_int_array(int *numbers, int length);
void display_int_array_of_arrays(Int_Array *array_of_arrays, int length);
void display_int_array(Int_Array *array);
#endif