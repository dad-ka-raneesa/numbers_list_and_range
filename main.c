#include <stdio.h>
#include "seperate_by_range.h"

int main(void)
{
  int numbers[] = {3, 1, 7, 4, 6, 5, 8, 2};
  int length = sizeof(numbers) / sizeof(int);
  Int_Arrays seperated_arrays = seperated_by_range(numbers, length, 4, 7);
  display_int_array_of_arrays(seperated_arrays, 3);
  return 0;
}