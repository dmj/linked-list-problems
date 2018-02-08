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
  node *list = make_list(3, 1, 2, 3);
  TEST_ASSERT_EQUAL(3, list_length(list));
  free_list(&list);
}

void
test_problem_01 ()
{
  node *list = make_list(5, 1, 2, 2, 3, 2);
  TEST_ASSERT_EQUAL(3, list_count(list, 2));
  TEST_ASSERT_EQUAL(1, list_count(list, 1));
  TEST_ASSERT_EQUAL(0, list_count(list, 0));
  free_list(&list);
}

void
test_problem_02 ()
{
  node *list = make_list(5, 1, 2, 2, 3, 2);
  TEST_ASSERT_EQUAL(1, list_nth(list, 0));
  TEST_ASSERT_EQUAL(2, list_nth(list, 4));
  TEST_ASSERT_EQUAL(3, list_nth(list, 3));
  free_list(&list);
}

void
test_problem_04 ()
{
  node *list = make_list(3, 1, 2, 3);
  TEST_ASSERT_EQUAL(1, list_nth(list, 0));
  list_pop(&list);
  TEST_ASSERT_EQUAL(2, list_nth(list, 0));
  list_pop(&list);
  TEST_ASSERT_EQUAL(3, list_nth(list, 0));
  list_pop(&list);
  TEST_ASSERT_EQUAL(0, list_length(list));
  free_list(&list);
}

void
test_problem_05 ()
{
  node *list = make_list(3, 1, 2, 3);
  list_insert(&list, 0, 0);
  TEST_ASSERT_EQUAL(0, list_nth(list, 0));
  list_insert(&list, 2, 128);
  TEST_ASSERT_EQUAL(128, list_nth(list, 2));
  free_list(&list);
}

int
main()
{
    UNITY_BEGIN();
    RUN_TEST(test_basic_functions);
    RUN_TEST(test_problem_01);
    RUN_TEST(test_problem_02);
    RUN_TEST(test_problem_04);
    RUN_TEST(test_problem_05);
    return UNITY_END();
}
