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

void display_int_array_of_arrays(Int_Arrays array_of_arrays, int length)
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

Int_Arrays seperated_by_range(int *numbers, int length, int start_from, int upto)
{
  int temp_ranges[3][length];
  int lengths[] = {0, 0, 0};
  Position pos;

  FOR(0, length)
  {
    int num = numbers[i];
    pos = num < start_from ? BELOW : num > upto ? ABOVE : IN;
    temp_ranges[pos][lengths[pos]] = num;
    lengths[pos] += 1;
  }

  Int_Arrays seperated_arrays = (Int_Arrays)malloc(sizeof(Int_Arrays) * 3);
  FOR(0, 3)
  {
    seperated_arrays[i] = *create_int_array(temp_ranges[i], lengths[i]);
  }
  return seperated_arrays;
}
