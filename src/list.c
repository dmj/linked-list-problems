/**
 * Linked list library v2.
 *
 * Author: David Maus <dmaus@dmaus.name>
 *
 */

#include <stdlib.h>
#include <stdarg.h>

typedef struct lnode lnode;
typedef struct lnode {
  int    data;
  lnode *next;
} lnode;

#define NULLIFY(_name_) \
  _name_ = NULL;

#define FAIL() \
  abort();

lnode *
make_node (int value)
{
  lnode *node = malloc(sizeof(lnode));
  node->data = value;
  node->next = NULL;
  return node;
}

int
llength (lnode *list)
{
  int count = 0;
  lnode *current = list;
  while (current) {
    count++;
    current = current->next;
  }
  return count;
}

void
lfree (lnode **list)
{
  lnode *head = *list;
  lnode *next;
  while (head) {
    next = head->next;
    free(head);
    head = next;
  }
  NULLIFY(*list);
}

void
lpush (lnode **list, int value)
{
  lnode *node = make_node(value);
  if (list) {
    node->next = *list;
  }
  *list = node;
}

int
lpop (lnode **list)
{
  if (!list) {
    FAIL();
  }

  lnode *head = *list;
  int   value = head->data;

  *list = head->next;
  free(head);

  return value;
}

lnode *
lexample ()
{
  lnode *list = NULL;
  lpush(&list, 3);
  lpush(&list, 2);
  lpush(&list, 1);
  return list;
}

int
lcount (lnode *list, int value)
{
  int count = 0;
  lnode *current = list;
  while (current) {
    if (current->data == value) {
      count++;
    }
    current = current->next;
  }
  return count;
}

int
lgetnth (lnode *list, int index)
{
  int pos = 0;
  lnode *current = list;
  while (current) {
    if (pos == index) {
      return current->data;
    }
    pos++;
    current = current->next;
  }
  FAIL();
}

void
linsnth (lnode **list, int index, int value)
{
  if (!*list || !index) {
    lpush(list, value);
  } else {
    int pos = 0;
    lnode *current = *list;
    while (current && pos < (index - 1)) {
      pos++;
      current = current->next;
    }
    if (!current) {
      FAIL();
    }
    lnode *node = make_node(value);
    node->next = current->next;
    current->next = node;
  }
}

void
linsnode (lnode **list, lnode *node)
{
  lnode *current = *list;
  lnode *prev = NULL;
  while (current && current->data < node->data) {
    prev = current;
    current = current->next;
  }
  node->next = current;
  if (prev) {
    prev->next = node;
  } else {
    *list = node;
  }
}

void
lsort (lnode **list)
{
  if (*list && (*list)->next) {

    lnode *sort = *list;
    lnode *iter = (*list)->next;
    lnode *next;

    sort->next = NULL;
    while (iter) {
      next = iter->next;
      linsnode(&sort, iter);
      iter = next;
    }

    *list = sort;
  }
}

void
lappend (lnode **a, lnode **b)
{
  if (*a) {
    lnode *current = *a;
    while (current->next) {
      current = current->next;
    }
    current->next = *b;
  } else {
    *a = *b;
  }
  *b = NULL;
}

void
lsplit (lnode *source, lnode **front, lnode **back)
{
  lnode *iter = source;
  int iterlen = llength(source) >> 1;
  for (int i = 0; i < iterlen; i++) {
    iter = iter->next;
  }
  *front = source;
  *back  = iter->next;
  NULLIFY(iter->next);
}

void
ldeldupl (lnode **list)
{
  if (*list) {
    lnode *iter = (*list)->next;
    lnode *prev = *list;
    lnode *dupl;
    while (iter) {
      if (iter->data == prev->data) {
        dupl = iter;
        iter = iter->next;
        prev->next = iter;
        free(dupl);
      } else {
        prev = iter;
        iter = iter->next;
      }
    }
  }
}

void
lmove (lnode **a, lnode **b)
{
  if (*b) {
    lnode *detach = *b;
    *b = detach->next;
    detach->next = *a;
    *a = detach;
  }
}

void
lsplitalt (lnode *source, lnode **a, lnode **b)
{
  lnode *iter = source;
  lnode *next;
  int odd = 0;
  while (iter) {
    next = iter->next;
    if (odd) {
      lmove(b, &iter);
    } else {
      lmove(a, &iter);
    }
    iter = next;
    odd ^= 1;
  }
}
