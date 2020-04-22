#include <stdio.h>
#include <stdlib.h>
#include "seperate_by_range.h"

void display_int_array(Int_Array *array)
{
  FOR(0, array->length)
  {
    printf("%d ", array->values[i]);
  }
  printf("\n");
}

void display_int_array_of_arrays(Int_Array *array_of_arrays, int length)
{
  FOR(0, length)
  {
    display_int_array(&array_of_arrays[i]);
  }
}

Int_Array *create_int_array(int *numbers, int length)
{
  Int_Array *array = (Int_Array *)malloc(sizeof(Int_Array));
  array->length = length;
  array->values = (int *)malloc(sizeof(int) * length);
  FOR(0, length)
  {
    array->values[i] = numbers[i];
  }
  return array;
}

Int_Array *seperated_by_range(int *numbers, int length, int start_from, int upto)
{
  int below_the_range[length];
  int in_the_range[length];
  int above_the_range[length];

  Index below_the_range_count = 0;
  Index in_the_range_count = 0;
  Index above_the_range_count = 0;

  FOR(0, length)
  {
    int num = numbers[i];
    if (num < start_from)
    {
      below_the_range[below_the_range_count] = num;
      below_the_range_count++;
    }
    else if (num > upto)
    {
      above_the_range[above_the_range_count] = num;
      above_the_range_count++;
    }
    else
    {
      in_the_range[in_the_range_count] = num;
      in_the_range_count++;
    }
  }

  Int_Array *seperated_arrays = (Int_Array *)malloc(sizeof(Int_Array) * 3);
  seperated_arrays[0] = *create_int_array(below_the_range, below_the_range_count);
  seperated_arrays[1] = *create_int_array(in_the_range, in_the_range_count);
  seperated_arrays[2] = *create_int_array(above_the_range, above_the_range_count);

  return seperated_arrays;
}
