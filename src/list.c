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

node *
make_node ()
{
  node *new = malloc(sizeof(node));
  new->next = NULL;
  new->data = 0;
  return new;
}

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
  node *head = make_node();
  head->data = data;
  head->next = *headref;

  *headref = head;
}

node *
list_last (node *head)
{
  node *current = head;
  while (current->next) {
    current = current->next;
  }
  return current;
}

void
list_append (node **headref, int data)
{
  node *last = list_last(*headref);
  last->data = data;
  last->next = make_node();
}

node *
make_list (int number_of_elements, ...)
{
  node *list = make_node();

  va_list elements;
  va_start(elements, number_of_elements);
  for (int i = 0; i < number_of_elements; i++) {
    list_append(&list, va_arg(elements, int));
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

// Problem 2: Return data of node at position INDEX in LIST.
int
list_nth (node *list, int index)
{
  int       pos = 0;
  node *current = list;
  while (current->next) {
    if (pos == index) {
      return current->data;
    }
    pos++;
    current = current->next;
  }
  exit(-1);
}
