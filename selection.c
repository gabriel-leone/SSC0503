#include <stdio.h>
#include "util.h"

void selection(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[min])
      {
        min = j;
      }
      if (min != i)
      {
        swap(a, i, min);
        print(a, n);
        printf("\n");
      }
    }
  }
}

int main()
{
  int a[] = {5, 7, 3, 9, 1};
  selection(a, 5);
}