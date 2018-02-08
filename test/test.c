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
}

int
main()
{
    UNITY_BEGIN();
    RUN_TEST(test_basic_functions);
    return UNITY_END();
}
