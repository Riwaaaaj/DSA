#include <stdio.h>
#include <stdlib.h>

int main() {
  int size, i, *ptr, sum = 0;

  printf("Enter the number of elements");
  scanf("%d", &size);

  ptr = (int *)calloc(size, sizeof(int));

  if (ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(1);
  }

  printf("Enter the elements of array: \n");
  for (i = 0; i < size; ++i) {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }
  printf("Sum = %d", sum);
  free(ptr);
  return 0;
}