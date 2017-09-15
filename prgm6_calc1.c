/******************************************************************************
 * @File    : prgm6_calc1.c
 * @Author  :Adish M R
 * @About:C program to Make a Simple Calculator to
 * Add, Subtract,Multiply or Divide Using switch...case.
 *****************************************************************************/

#include <stdio.h>

#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define END 5
#define SUCCESS 0
#define EXIT -1

int loop(void );
int calc(int );

int main()
{
    int option;
    do {
    	option = loop();
    }while(option != 5);
    return SUCCESS;
}

/**
 * @function: loop
 * @brief   : display and read options from user
 */
int loop()
{
    int option, flag = 0;

    printf("\nenter an option\n-------------\n1.add\n2.sub\n3.mul\n4.div\n"
            "5.exit\n--------------\n");
    flag = scanf("%d",&option);
    getchar();
    if (flag == 0 || option < 1 || option > 5 ) {
        printf("input only integer option between 1 and 5\n");
        return SUCCESS;
    }
    if ( option == 5) {
        printf("exit\n");
        return option;
    }
    calc(option);
    return option;
}

/**
 * @function: calc
 * @param   : option
 * @brief   : perform calculator operations
 */
int calc (int option)
{
    int flag1 = 0, flag2 = 0;
    float num1,num2;

READ_A:printf("enter number A\n");
    flag1 = scanf("%f", &num1);
    getchar();
    if (flag1 == 0) {
        printf("input only integer or float values\n");
        goto READ_A;
    }

READ_B:printf("enter number B\n");
    flag2 = scanf("%f",&num2);
    getchar();
    if (flag2 == 0) {
        printf("input only integer or float values\n");
        goto READ_B;
    }
    switch (option) {
        case ADD: printf("%4.0f + %4.0f = %4.0f\n",num1, num2, num1 + num2);
                  break;
        case SUB: printf("%4.0f - %4.0f = %f\n",num1, num2, num1 - num2);
                  break;
        case MUL: printf("%f * %f = %f\n",num1, num2, num1 * num2);
                  break;
        case DIV: printf("%4.0f / %4.0f = %f\n",num1, num2, num1 / num2);
                  break;
        case END: printf("exit\n");
                  break;
        default: printf("wrong option\n");
                 break;
    }
    return SUCCESS;
}
