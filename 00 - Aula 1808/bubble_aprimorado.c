#include <stdio.h>
#include "util.h"

void bolha(int a[], int n)
{
  print(a, n);
  int contador;
  int i = n - 1;
  while (i >= 1)
  {
    contador = -1;
    for (int j = 0; j < i; j++)
    {
      if (a[j] > a[j + 1])
      {
        contador = j;
        swap(a, j, j + 1);
        print(a, n);
        printf("\n");
      }
    }
    i--;
  }
}

int main()
{
  int a[] = {3, 4, 5, 6, 1, 2};
  bolha(a, 6);
}