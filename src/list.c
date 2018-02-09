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
make_node (int data)
{
  node *new = malloc(sizeof(node));
  new->next = NULL;
  new->data = data;
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
list_push_node (node **headref, node *new)
{
  new->next = *headref;
  *headref = new;
}

void
list_push (node **headref, int data)
{
  list_push_node(headref, make_node(data));
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
  last->next = make_node(0);
}

node *
make_list (int number_of_elements, ...)
{
  node *list = make_node(0);

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

node *
list_nth_node (node *list, int index)
{
  int       pos = 0;
  node *current = list;
  while (current->next) {
    if (pos == index) {
      return current;
    }
    pos++;
    current = current->next;
  }
  exit(-1);
}

// Problem 2: Return data of node at position INDEX in LIST.
int
list_nth (node *list, int index)
{
  return list_nth_node(list, index)->data;
}

// Problem 3: Deallocate LIST.
void
free_list (node **listref)
{
  node *current = *listref;
  node *next;

  while (current) {
    next = current->next;
    free(current);
    current = next;
  }

  *listref = NULL;
}

// Problem 4: Remove the head of LIST.
void
list_pop (node **headref)
{
  node *head = *headref;
  if (!head->next) {
    exit(-1);
  }
  *headref = head->next;
  free(head);
}

void
list_insert_node (node **headref, int index, node *new)
{
  if (index == 0) {
    list_push_node(headref, new);
  } else {
    node *prev = list_nth_node(*headref, index - 1);
    new->next = prev->next;
    prev->next = new;
  }
}

// Problem 5: Insert VALUE at position INDEX in LIST.
void
list_insert (node **headref, int index, int value)
{
  list_insert_node(headref, index, make_node(value));
}

// Problem 6: Insert NODE in sorted LIST.
void
list_insert_sort (node **headref, node *new)
{
  int   index   = 0;
  node *current = *headref;
  while (current->next && current->data < new->data) {
    index++;
    current = current->next;
  }
  list_insert_node(headref, index, new);
}
