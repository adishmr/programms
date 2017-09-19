/*
 * A C program that prints its source code.
 * compile with gcc -c /full/path/to/file.c
 * otherwise it will not show full path
 */
#include <stdio.h>

int main (void)
{
    char c;
    FILE *fp= fopen(__FILE__, "r");
    printf("the source-code name is %s\n\n",__FILE__);
    if (fp != NULL) {
        do {
            c = fgetc(fp);
            putchar(c);
        } while (c != EOF);
        fclose(fp);
    }
    else {
        printf("sorry file not found\n");
    }
    return 0;
}
