#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *elementos;
  int tamanho;
} vetor;

void printArray(int array[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int tamanho)
{
  int key, j, swapCount = 0, comparisonCount = 0;

  for (int i = 1; i < tamanho; i++)
  {
    key = array[i];
    j = i - 1;
    swapCount++;

    while (j >= 0)
    {
      comparisonCount++;
      if (array[j] > key)
      {
        array[j + 1] = array[j];
        j = j - 1;
        swapCount++;
      }
      else
        break;
    }

    array[j + 1] = key;
    swapCount++;
  }

  printf("I %d %d %d\n", tamanho, swapCount, comparisonCount);
  // printArray(array, tamanho);
}

void merge(int array[], int firstSubArrayInitIndex, int firstSubArrayLastIndex, int secondSubArrayLastIndex, int *swapCount, int *comparisonCount)
{
  int i, j, k;
  int firstSubArraySize = firstSubArrayLastIndex - firstSubArrayInitIndex + 1;
  int secondSubArraySize = secondSubArrayLastIndex - firstSubArrayLastIndex;

  int FirstSubArray[firstSubArraySize], SecondSubArray[secondSubArraySize];

  for (i = 0; i < firstSubArraySize; i++)
    FirstSubArray[i] = array[firstSubArrayInitIndex + i];
  for (j = 0; j < secondSubArraySize; j++)
    SecondSubArray[j] = array[firstSubArrayLastIndex + 1 + j];

  i = 0;
  j = 0;
  k = firstSubArrayInitIndex;
  while (i < firstSubArraySize && j < secondSubArraySize)
  {
    *comparisonCount = *comparisonCount + 1;

    if (FirstSubArray[i] <= SecondSubArray[j])
    {
      array[k] = FirstSubArray[i];
      i++;
    }
    else
    {
      array[k] = SecondSubArray[j];
      j++;
    }

    *swapCount = *swapCount + 1;
    k++;
  }

  while (i < firstSubArraySize)
  {
    array[k] = FirstSubArray[i];
    *swapCount = *swapCount + 1;

    i++;
    k++;
  }

  while (j < secondSubArraySize)
  {
    array[k] = SecondSubArray[j];
    *swapCount = *swapCount + 1;

    j++;
    k++;
  }

  k = 0;
  for (int z = firstSubArrayInitIndex; z <= secondSubArrayLastIndex; z++, k++)
  {
    *swapCount = *swapCount + 1;
    SecondSubArray[z] = array[z];
  }
}

void mergeSort(int array[], int initIndex, int endIndex, int *swapCount, int *comparisonCount)
{
  if (initIndex < endIndex)
  {
    int middle = initIndex + (endIndex - initIndex) / 2;

    mergeSort(array, initIndex, middle, swapCount, comparisonCount);
    mergeSort(array, middle + 1, endIndex, swapCount, comparisonCount);

    merge(array, initIndex, middle, endIndex, swapCount, comparisonCount);
  }
}

int main()
{
  int qtdVetores;
  printf("Digite a quantidade de vetores: ");
  scanf("%d", &qtdVetores);

  vetor vetores[qtdVetores];

  for (int i = 0; i < qtdVetores; i++)
  {
    printf("Digite o tamanho do vetor %d: ", i + 1);
    scanf("%d", &vetores[i].tamanho);
  }

  for (int i = 0; i < qtdVetores; i++)
  {
    vetores[i].elementos = (int *)malloc(vetores[i].tamanho * sizeof(int));
    for (int j = 0; j < vetores[i].tamanho; j++)
    {
      printf("Digite o elemento %d do vetor %d: ", j + 1, i + 1);
      scanf("%d", &vetores[i].elementos[j]);
    }
  }

  for (int i = 0; i < qtdVetores; i++)
  {
    printf("Vetor %d: ", i + 1);
    for (int j = 0; j < vetores[i].tamanho; j++)
    {
      printf("%d ", vetores[i].elementos[j]);
    }
    printf("\n");
  }

  for (int i = 0; i < qtdVetores; i++)
  {
    vetor vetorCopia = vetores[i];
    insertionSort(vetorCopia.elementos, vetorCopia.tamanho);

    int swapCount = 0, comparisonCount = 0;
    mergeSort(vetores[i].elementos, 0, vetores[i].tamanho - 1, &swapCount, &comparisonCount);
    printf("M %d %d %d\n", vetores[i].tamanho, swapCount, comparisonCount);
    // printArray(vetores[i].elementos, vetores[i].tamanho);
  }
}