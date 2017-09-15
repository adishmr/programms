/******************************************************************************
 * @File    : commandline_strcmp.c
 * @Author  : Adish M R
 * @About   : Program to implement the "strcmp" functions without using
 * pre-defined functions. Get the input from command line.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define LENGTHDIFFER -2

/**
 * @function: length
 * @param   : string
 * @brief   : It will find the length of the string.
 */
int length(char *str)
{
    int len = 0;

    while(*str) {
        str++;
        len++;
    }

    return len;
}
/**
 * @function: compare
 * @param   : string1, string2
 * @brief   : compare the strings, if length different return -2
 *            if length equal but strings are different return -1
 *            if strings are equal return 0
 */
int compare(char *str1, char *str2)
{
    if (length(str1) != length(str2)) {
        return LENGTHDIFFER;
    }
    else {
        while(*str1) {
            if (*(str2++) != *(str1++)) {
                return FAILURE;
            }
        }

    }

    return SUCCESS;
}


int main(int argc, char *argv[])
{
    char *str1, *str2;
    int result;

    if (argc == 1) {
        printf("Error ! 2 arguments required\n");
    }
    else if (argc >  3) {
        printf("Error !, enter only 2 arguments\n");
    }
    else if (argc == 3) {
        str1 = argv[1];
        str2 = argv[2];
        result = compare(str1, str2);
        if (result == SUCCESS) {
            printf("strings are equal\n");
        }
        else if (result == LENGTHDIFFER) {
            printf("different length\nstrings are not equal\n");
        }
        else {
            printf("strings are not equal\n");
        }
    }

    return SUCCESS;
}
