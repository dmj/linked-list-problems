/**
 * Test the linked list library.
 *
 * Author: David Maus <dmaus@dmaus.name>
 *
 */

#include "unity/unity.h"
#include "../src/list.c"

void
test_basic_functions ()
{
  lnode *list = NULL;
  TEST_ASSERT_EQUAL(0, llength(list));
  lpush(&list, 3);
  TEST_ASSERT_EQUAL(1, llength(list));
  lpush(&list, 2);
  TEST_ASSERT_EQUAL(2, llength(list));
  lpush(&list, 1);
  TEST_ASSERT_EQUAL(3, llength(list));
  lfree(&list);
  TEST_ASSERT_EQUAL(0, llength(list));
}

void
test_problem_01 ()
{
  lnode *list = lexample();
  TEST_ASSERT_EQUAL(1, lcount(list, 2));
  TEST_ASSERT_EQUAL(0, lcount(list, 5));
  lfree(&list);
}

void
test_problem_02 ()
{
  lnode *list = lexample();
  TEST_ASSERT_EQUAL(1, lgetnth(list, 0));
  lfree(&list);
}

void
test_problem_03 ()
{
  lnode *list = lexample();
  TEST_ASSERT_EQUAL(1, lpop(&list));
  TEST_ASSERT_EQUAL(2, lpop(&list));
  TEST_ASSERT_EQUAL(3, lpop(&list));
  lfree(&list);
}

void
test_problem_05 ()
{
  lnode *list = NULL;
  linsnth(&list, 0, 3);
  TEST_ASSERT_EQUAL(1, llength(list));
  linsnth(&list, 0, 1);
  TEST_ASSERT_EQUAL(2, llength(list));
  linsnth(&list, 1, 2);
  TEST_ASSERT_EQUAL(3, llength(list));
  lfree(&list);
}

void
test_problem_06 ()
{
  lnode *list = lexample();
  linsnode(&list, make_node(0));
  TEST_ASSERT_EQUAL(4, llength(list));
  TEST_ASSERT_EQUAL(0, lgetnth(list, 0));
  linsnode(&list, make_node(2));
  TEST_ASSERT_EQUAL(5, llength(list));
  TEST_ASSERT_EQUAL(3, lgetnth(list, 4));
  lfree(&list);
}

void
test_problem_07 ()
{
  lnode *list = lexample();
  lpush(&list, 4);
  lsort(&list);
  TEST_ASSERT_EQUAL(1, lgetnth(list, 0));
  TEST_ASSERT_EQUAL(4, lgetnth(list, 3));
  lfree(&list);
}

void
test_problem_08 ()
{
  lnode *a = NULL;
  lnode *b = lexample();
  lnode *c = lexample();
  lappend(&a, &b);
  TEST_ASSERT_EQUAL(3, llength(a));
  TEST_ASSERT_NULL(b);
  lappend(&a, &c);
  TEST_ASSERT_EQUAL(6, llength(a));
  TEST_ASSERT_NULL(c);
  lfree(&a);
}

void
test_problem_09 ()
{
  lnode *source = lexample();
  lnode *front = NULL;
  lnode *back = NULL;
  lsplit(source, &front, &back);
  TEST_ASSERT_EQUAL(2, llength(front));
  TEST_ASSERT_EQUAL(1, llength(back));
  TEST_ASSERT_EQUAL(3, lgetnth(back, 0));
  lfree(&front);
  lfree(&back);
}

void
test_problem_10 ()
{
  lnode *list = lexample();
  linsnode(&list, make_node(2));
  TEST_ASSERT_EQUAL(4, llength(list));
  ldeldupl(&list);
  TEST_ASSERT_EQUAL(3, llength(list));
  TEST_ASSERT_EQUAL(1, lgetnth(list, 0));
  TEST_ASSERT_EQUAL(2, lgetnth(list, 1));
  TEST_ASSERT_EQUAL(3, lgetnth(list, 2));
  lfree(&list);
}

void
test_problem_11 ()
{
  lnode *a = lexample();
  lnode *b = lexample();
  lmove(&a, &b);
  TEST_ASSERT_EQUAL(4, llength(a));
  TEST_ASSERT_EQUAL(2, llength(b));
  TEST_ASSERT_EQUAL(1, lgetnth(a, 0));
  TEST_ASSERT_EQUAL(1, lgetnth(a, 1));
  lfree(&a);
  lfree(&b);
}

void
test_problem_12 ()
{
  lnode *list = lexample();
  lnode *a = NULL;
  lnode *b = NULL;
  lsplitalt(list, &a, &b);
  TEST_ASSERT_EQUAL(2, llength(a));
  TEST_ASSERT_EQUAL(1, llength(b));
  TEST_ASSERT_EQUAL(3, lgetnth(a, 0));
  TEST_ASSERT_EQUAL(1, lgetnth(a, 1));
  TEST_ASSERT_EQUAL(2, lgetnth(b, 0));
  lfree(&a);
  lfree(&b);
}

int
main()
{
    UNITY_BEGIN();
    RUN_TEST(test_basic_functions);
    RUN_TEST(test_problem_01);
    RUN_TEST(test_problem_02);
    RUN_TEST(test_problem_03);
    RUN_TEST(test_problem_05);
    RUN_TEST(test_problem_06);
    RUN_TEST(test_problem_07);
    RUN_TEST(test_problem_08);
    RUN_TEST(test_problem_09);
    RUN_TEST(test_problem_10);
    RUN_TEST(test_problem_11);
    RUN_TEST(test_problem_12);
    return UNITY_END();
}
