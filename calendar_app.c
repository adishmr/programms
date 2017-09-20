/******************************************************************************
 * @File   : calendar.c
 * @Author : ADISH M R
 * @About  : A program to display the Full month calendar or a single month of
 *           the given year.I found this calculation and logic in many calendar
 *           programs in the internet and I write this program by referring
 *           that.Input validation is not done. In this the application waits
 *           for user choice once it displayed the calendar user can either
 *           exit or continue using the options.
 *****************************************************************************/
#include<stdio.h>

/*months number starting from 1 to 12 so the zeroth place left empty*/
char *months[]={" ","January","February","March","April","May","June","July",
    "August","September","October","November","December"};
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};/*no.of days in each month*/

int loop (void);
int read_inputs (void);
int print_calendar(int , int , int );

int main()
{
    int option = 0;

    printf("\nWelcome to the Calender application\n"
            "====================================\n");
    do {
        option = loop();
        if (option == 0) {
            read_inputs();
        }
        else if (option == 1) {
            printf("\nThank You....\nExiting...!!!\n");
        }
    } while (!option);

    return 0;
}

/* function to diplay the choice */
int loop(){

    int option;

    printf("\n ___________    ___________"
            "\n|___________MENU___________|\n"
            "\n\t0 -> Check calendar\n\t1 -> Quit\n"
            "\nEnter your choice: ");
    scanf(" %d",&option);

    return option;
}

/*funcction to read the date inputs from user */
int read_inputs() {

    char choice;
    int countdown = 2;                                  /* retry count-1 */
    int year, code, d1, d2, d3, cmonth;

    printf("\n* Enter calendar year: ");
    scanf("%d", &year);                                     /*Read the year*/

    d1=(year-1.)/4.0;
    d2=(year-1.)/100.;
    d3=(year-1.)/400.;
    code=(year+d1-d2+d3)%7;

    if (year%4==0 && year%100!=0 || year%400==0 ) {  /*checking for leap year*/
        days[2]=29;
    }
    else {
        days[2]=28;
    }

    /*asking to disply full calendar or only for a single month*/
    printf("* Do you want to Display full month calendar of %d (y/n): ",year);
    scanf(" %c",&choice);

    if (choice == 'n') {
retry:printf("* Please enter the Month number: ");
        scanf("%d",&cmonth);

        if (cmonth <= 0 ||cmonth >12) {
            if (!(countdown--)) {
                printf("!! sorry try again...\nclosing...!\n");
                return 0;
            }
            printf("Please  enter a valid month number (1-12)\n");
            goto retry;
        }
    }
    else {
        cmonth = 0;         /* this is for printing all the months */
    }

    print_calendar(cmonth, year, code);

    return 0;
}

/* function to display the Calendar */
int print_calendar(int cmonth, int year, int code) {

    int month, all,day;
    month=cmonth;
    all=cmonth;

    printf("\n        Year %d Calender       \n"
            "*********************************\n",year);
    for(month=0;month<=12;month++)
    {
        if(month >0) {                  /* month starting from 1 */
            if(month==cmonth) { /*if the entered cmonth matches to month */
                /*start printing of dates*/
                printf("\n____________%s____________",months[month]);
                printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

                for (day=1; day<=1+code*5; day++) {
                    printf(" ");
                }

                for (day=1;day<=days[month];day++) {
                    printf("%2d",day);

                    if ((day+code)%7>0)
                        printf("   ");
                    else
                        printf("\n ");
                }
                printf("\n");
            }
            code=(code+days[month])%7;
        }

        if(all == 0) {
            cmonth++;
        }
    }
    return 0;
}

