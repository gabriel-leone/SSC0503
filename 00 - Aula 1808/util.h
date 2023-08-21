#include <stdio.h>

void print(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void swap(int a[], int i, int j)
{
  int aux = a[i];
  a[i] = a[j];
  a[j] = aux;
}