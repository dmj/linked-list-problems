/**
 * Linked list library.
 *
 * Author: David Maus <dmaus@dmaus.name>
 *
 */

#include <stdlib.h>
#include <stdarg.h>

typedef struct node node;
typedef struct node {
  int   data;
  node *next;
} node;

int
list_length (node *head)
{
  int count     = 0;
  node *current = head;
  while (current->next) {
    count++;
    current = current->next;
  }
  return count;
}

void
list_push (node **headref, int data)
{
  node *head = malloc(sizeof(node));
  head->data = data;
  head->next = *headref;

  *headref = head;
}

node *
make_list (int number_of_elements, ...)
{
  node *list = malloc(sizeof(node));
  list->next = NULL;
  list->data = 0;

  va_list elements;
  va_start(elements, number_of_elements);
  for (int i = 0; i < number_of_elements; i++) {
    list_push(&list, va_arg(elements, int));
  }
  va_end(elements);

  return list;
}

// Problem 1: Return number of times VALUE occurs in LIST.
int
list_count (node *list, int value)
{
  int count     = 0;
  node *current = list;
  while (current->next) {
    if (current->data == value) {
      count++;
    }
    current = current->next;
  }
  return count;
}
