/******************************************************************************
 * @file   : timer.c
 * @brief  : thi is a program for stop watch timer using 4 threads
 * @Author : Adish M R 
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

#define SUCCESS 0

int HH = 0, MM = 0, SS = 0;
int input = 0, flag = 0;
pthread_t thrd1, thrd2, thrd3, thrd4;
sem_t read_hold, sec_inc, min_inc, hr_inc;
pthread_mutex_t num_hold;

/*user input reading thread*/
void *read_input(void *arg)
{
	system("clear");
    while(1) {
    printf("\n------stop watch timer----------\n"
        "\n\t %02d::%02d::%02d\n",HH,MM,SS);
    printf("\n1)start  2)reset  3)stop  4)exit\n>> ");
    scanf("%d",&input);
    system("clear");
    if (input == 1) {
    		flag = 0;
            sem_post(&sec_inc);
        }
        if (input == 2) {
            HH = 0;
            MM = 0;
            SS = 0;
            flag = 1;
        }
        if (input ==3) {
        	flag = 1; 
        }
        if (input == 4) {
			sem_post(&read_hold);
        }
    }
    return SUCCESS;
}
/*second counting thread*/
void *sec_thread(void *arg)
{
    sem_wait(&sec_inc);
    while(1) {
    	if ( flag == 0 ) {
    		system("clear");
    		printf("------stop watch timer----------\n"
    		"\n\t %02d::%02d::%02d\n",HH,MM,SS);
    		printf("\n1)start  2)reset  3)stop  4)exit\n");
    		SS++;
    		sleep(1);
    		if ( SS == 60) {
        		SS = 0;
        		sem_post(&min_inc);
    		}
    	}
    }
    return SUCCESS;
}
/*minute counting thread*/
void *min_thread(void *arg)
{
    while(1) {
    	sem_wait(&min_inc);
    	if ( flag == 0 ) {
    		MM++;
    		if ( MM == 60) {
        		MM = 0;
        		sem_post(&hr_inc);
    		}
    	}
    }
    return SUCCESS;
}
/* hour count function*/
void *hr_thread(void *arg)
{

    while(1) {
        sem_wait(&hr_inc);
    	if( flag == 0 ) {
    		HH++;
    		if (HH == 24) {
        		HH = 0;
    		}
    	}
    }
    return SUCCESS;
}
int main()
{
    sem_init(&read_hold,0,0);
    sem_init(&hr_inc, 0,0);
    sem_init(&min_inc,0,0);
    sem_init(&sec_inc,0,0);
    if (pthread_create(&thrd4, NULL, &read_input, NULL)) {
            printf ("Thread creation Failure\n");
            return (EXIT_FAILURE);
        }
	if (pthread_create(&thrd1, NULL, &sec_thread, NULL)) {
			printf ("Thread creation Failure\n");
        	return (EXIT_FAILURE);
	}
    if(pthread_create(&thrd2, NULL, &min_thread, NULL)) {
			printf("Thread creation failure\n");
			return (EXIT_FAILURE);
	}
	if (pthread_create(&thrd3, NULL, &hr_thread, NULL)) {
			printf ("Thread creation Failure\n");
			return (EXIT_FAILURE);
	}
    sem_wait(&read_hold);
    sem_destroy;
    system("clear");
    return SUCCESS;
}

