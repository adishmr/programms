/******************************************************************************
 * @file name : process.c
 * @author    : Adish M R
 * @about     : Simple program to understand process id, creation of child
 *              process using fork.
 *****************************************************************************/
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid,i;

    printf("Start of main \n");

    pid = fork();
    if(pid > 0) {
        printf("Parent process\n"); /*parent process*/
    }
    else if(pid == 0) {
        printf("\nfork created\n");  /*child process*/
    }
    else {
        printf("\nfork creation failed!!!\n");  /*fork creation failed*/

        return 0;
    }

    printf("Printing the numbers from 1 to 10 using %s process\n",(pid > 0? "parent":"child") );
    printf("Process id : %d\n",pid);
    for(i = 1; i <= 10; i++) {
        printf("%d ",i);
    }

    printf("\n");
    printf("End of the main\n");

    return 0;
}
