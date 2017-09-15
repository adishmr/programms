/******************************************************************************
 * @File    : flip1.c
 * @Author  : Adish M R
 * @About   : C Program to Count the Number of Bits needed to be
 * Flipped to Integer X to Generate Integer Y
 *****************************************************************************/

#include <stdio.h>

#define SUCCESS 0

int flip_count(int );
int binary(int );

int main()
{
    int flag1 = 0, flag2 = 0, limit = 3;
    int num1, num2;
    unsigned int dif, count;

LOOP1: printf("enter X\n");
    flag1 = scanf("%d",&num1);
    getchar();
    if (flag1 == 0 && limit > 0) {
        printf("Wrong data\n");
        limit--;
        goto LOOP1;
    }
    if(limit == 0) {
        printf("limit over\n");
        return SUCCESS;
    }
    else if (limit > 0) {
        binary(num1);
        limit = 3;
    }
LOOP2:printf("enter Y\n");
    flag2 = scanf("%d",&num2);
    getchar();

    if (flag2 == 0 && limit > 0) {
        printf("Wrong data\n");
        limit--;
        goto LOOP2;
    }

    if(limit == 0) {
        printf("limit over\n");
        return SUCCESS;
    }
    else {
        binary(num2);
        dif = num1^num2;
        count = flip_count(dif);
        printf("\nfor X:%d to generate Y:%d\n",num1,num2);
        printf("no of bits needs to be flipped: %d\n",count);
    }

    return SUCCESS;
}

/**
 * @Function: flip_count
 * @Param   : num
 * @Brief   : returns the no.of bits needs to be flipped.
 */
int flip_count(int num)
{
    unsigned int count = 0;
    while(num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

/**
 * @Function : binary
 * @Param    : num
 * @Brief    : returns the binary of the number.
 */
int binary(int num)
{
    int n, rem, bin, i;
    n = num;
    i = 1;
    while(n) {
        rem= n%2;
        n = n/2;
        bin = bin + (rem*i);
        i = i*10;
    }
    printf("binary of %d : %d\n",num,bin);

    return SUCCESS;
}
