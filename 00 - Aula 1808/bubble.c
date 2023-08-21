#include <stdio.h>

void bolha(int a[], int n) {
  int contador;
  for (int i = n - 1; i >= 1; i--) {
    contador = -1;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[j+1]) {
        contador = j;
        int aux = a[j];
        a[j] = a[j+1];
        a[j+1] = aux;
      }
    }
  }
}

int main() {
  int n = 5;
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  bolha(a, n);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}