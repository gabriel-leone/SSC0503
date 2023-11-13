#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SET_SIZE 10000


/*
Nome: Bruno Giacomini Volpe - NoUSP: 14651980
Nome: Enzo Vasconcellos Pagotto - NoUSP: 13632844
Nome: Gabriel Pietro Leone - NoUSP: 13874729
Nome: Guilherme Aureliano Xavier da Silva - NoUSP: 14575641
*/

typedef struct Node
{
  int key;
  struct Node *next;
} Node;

typedef struct Set
{
  Node *table[SET_SIZE];
} Set;

Set *createSet()
{
  Set *set = (Set *)malloc(sizeof(Set));
  for (int i = 0; i < SET_SIZE; i++)
  {
    set->table[i] = NULL;
  }
  return set;
}

void insert(Set *set, int key)
{
  int index = abs(key) % SET_SIZE;
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = set->table[index];
  set->table[index] = newNode;
}

bool contains(Set *set, int key)
{
  int index = abs(key) % SET_SIZE;
  Node *current = set->table[index];
  while (current != NULL)
  {
    if (current->key == key)
    {
      return true;
    }
    current = current->next;
  }
  return false;
}

int main()
{
  int initialArraySize;
  scanf("%d", &initialArraySize);

  int *array = (int *)malloc(initialArraySize * sizeof(int));
  for (int i = 0; i < initialArraySize; i++)
  {
    scanf("%d", &array[i]);
  }

  int searchArraySize;
  scanf("%d", &searchArraySize);

  Set *set = createSet();

  for (int i = 0; i < initialArraySize; i++)
  {
    insert(set, array[i]);
  }

  for (int i = 0; i < searchArraySize; i++)
  {
    int searchElement;
    scanf("%d", &searchElement);
    if (contains(set, searchElement))
    {
      printf("1\n");
    }
    else
    {
      printf("0\n");
    }
  }

  free(array);
  free(set);

  return 0;
}