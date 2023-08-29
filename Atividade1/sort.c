#include <stdio.h>
#include <string.h>

void swap(int *endereco1, int *endereco2, int index1, int index2)
{
  printf("T %d %d\n", index1, index2);
  int temp = *endereco1;
  *endereco1 = *endereco2;
  *endereco2 = temp;
}

void bubble(int array[], int arraySize)
{
  int i = arraySize - 1;

  while (i >= 1)
  {
    for (int j = 0; j < i; j++)
    {
      printf("C %d %d\n", j, j + 1);
      if (array[j] > array[j + 1])
      {
        // printf("T %d %d\n", j, j + 1);
        // int tmp = array[j];
        // array[j] = array[j + 1];
        // array[j + 1] = tmp;
        swap(&array[j], &array[j + 1], j, j + 1);
      }
    }
    i--;
  }
}

void selection(int array[], int arraySize)
{
  for (int i = 0; i < arraySize - 1; i++)
  {
    int m = i;

    for (int j = i + 1; j < arraySize; j++)
    {
      printf("C %d %d\n", m, j);
      if (array[j] < array[m])
      {
        m = j;
      }
    }
    if (m == i)
      continue;
    swap(&array[m], &array[i], i, m);
  }
}

int main()
{
  // Define o método de ordenação
  char metodoOrdenacao[10];
  scanf("%s", metodoOrdenacao);
  char bolha[10] = "bolha";
  char selecao[10] = "selecao";

  // Define o tamanho do array e faz a leitura
  int arraySize;
  scanf("%d", &arraySize);
  int array[arraySize];
  for (int i = 0; i < arraySize; i++)
  {
    scanf("%d", &array[i]);
  }

  // Chama a função de ordenação
  if (strcmp(metodoOrdenacao, bolha) == 0)
  {
    bubble(array, arraySize);
  }
  else if (strcmp(metodoOrdenacao, selecao) == 0)
  {
    selection(array, arraySize);
  }

  // Imprime o array ordenado
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", array[i]);
  }
}