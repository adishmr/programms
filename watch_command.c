/******************************************************************************
 * @File     : watch_command.c
 * @Author   : Adish M R 
 * @About : Implementation of watch command using parent & child process logic.
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

#define SUCCESS 0
#define TIM 2

void back_fn(int sig);

/**
 * @function: cleardisp
 * @brief   : used to clear the terminal
 */
void cleardisp()
{
	pid_t pid2;
	int state;
	pid2 = fork();
	if(!pid2) {
        execlp("clear","clear", NULL);
    }
    else if(pid2 < 0) {
        printf("Error\n");
        exit(0);
    }
    else {
        wait(&state);
    }
}

int main(int argc, char **argv)
{
    int status, time = TIM;
    pid_t pid;
    signal(SIGINT, back_fn);
    if (argc < 2) {
        printf("Error !!\nUsage:\n     ./watch command\n");
        return SUCCESS;
    }
    while(1) {
        pid = fork(); /*fork call create the child process*/
		switch (pid) {
		    case -1: {
		                printf("ERROR !\n");
		                exit (0);
		             }
		    case 0: {
                        cleardisp();
                        printf("Watch every 2.0 sec...    \n\n");
                        execvp(argv[1],argv+1); /*execute the system commands*/
                    }
		    default: {
		                wait(&status);
		                sleep(time);
		             }
		}
		signal(SIGINT,back_fn); /*when CTRL+C pressed it calls back_fn function*/
	}
}

/**
 * @function : back_fn
 * @brief    : cntrl c signal
 */
void back_fn(int sig)
{
        cleardisp();
		exit(3);
}
