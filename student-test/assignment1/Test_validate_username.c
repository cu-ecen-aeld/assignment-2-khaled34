#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

#define NULL_TERMINATOR_BYTE_LEN 1
/**
* This function should:
*   1) Call the my_username() function in Test_assignment_validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    char* ptr_config_name;
    char* ptr_my_name;
    uint8_t my_name_len;
    /**
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     */

    //TEST_ASSERT_TRUE_MESSAGE(false,"AESD students, please fix me!");
    my_name_len = strlen(my_username()) + NULL_TERMINATOR_BYTE_LEN;
    ptr_my_name = (char*) malloc(my_name_len);
    strcpy(ptr_my_name, my_username()); 
    
    ptr_config_name = malloc_username_from_conf_file();

    TEST_ASSERT_EQUAL_STRING_MESSAGE(ptr_my_name, ptr_config_name, "Name Validation");

    /* Destruction */
    free(ptr_my_name);
    free(ptr_config_name);

}
