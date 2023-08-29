#include <stdio.h>
#include <string.h>

void printTroca(int index1, int index2) {
    printf("T %d %d\n", index1, index2);
}

void printComparacao(int index1, int index2) {
    printf("C %d %d\n", index1, index2);
}

void bubble(int array[], int arraySize)
{
  int mark;
  for (int i = arraySize - 1; i >= 1; i = mark)
  {
    mark = -1;
    for (int j = 0; j < i; j++)
    {
      printComparacao(j, j + 1 );
      if (array[j] > array[j + 1])
      {
        printTroca(j, j + 1);
        mark = j;
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}

void selection(int array[], int arraySize)
{
  for (int i = 0; i < arraySize - 1; i++)
  {
    int m = i;
    for (int j = i + 1; j < arraySize; j++)
    {
      printComparacao(m, j);
      if (array[j] < array[m])
      {
        m = j;
      }
    }

    if (m != i)
    {
      printTroca(i, m);
      int tmp = array[i];
      array[i] = array[m];
      array[m] = tmp;
    }
  }
}

int main()
{
  // Define o método de ordenação
  char metodo[100];
  scanf("%s", metodo);

  // Lê o tamanho do array
  int arraySize;
  scanf("%d", &arraySize);
  int array[arraySize];

  // Lê os elementos do array
  for (int i = 0; i < arraySize; i++)
  {
    scanf("%d", &array[i]);
  }

  // Chama a função de ordenação
  if (strcmp(metodo, "selecao") == 0)
  {
    selection(array, arraySize);
  }
  else if (strcmp(metodo, "bolha") == 0)
  {
    bubble(array, arraySize);
  }
  else
  {
    printf("Metodo de ordenacao invalido.\n");
    return 1;
  }

  // Imprime o array ordenado
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", array[i]);
  }
}