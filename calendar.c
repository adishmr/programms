/******************************************************************************
 * @File   : calendar.c
 * @Author : ADISH M R
 * @About  : A program to display the Full month calendar or a single month of
 *           the given year.I found this calculation and logic in many calendar
 *           programs in the internet and I wrote this program by referring
 *           those.
 *****************************************************************************/
#include<stdio.h>

/*months number starting from 1 to 12 so the zeroth place left empty*/
char *months[]={" ","January","February","March","April","May","June","July",
    "August","September","October","November","December"};
char choice;
int countdown = 3;
int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};/*no.of days in each month*/

int main(void)
{
    int day, month, all, year, code, d1, d2, d3, cmonth;
    printf("Enter calendar year: ");
    scanf("%d", &year);                                     /*Read the year*/

    d1=(year-1.)/4.0;
    d2=(year-1.)/100.;
    d3=(year-1.)/400.;
    code=(year+d1-d2+d3)%7;

    if(year%4==0 && year%100!=0 || year%400==0 ) {  /*checking for leap year*/
        days[2]=29;
    }
    else {
        days[2]=28;
    }

    /*asking to disply full calendar or only for a single month*/
    printf("Do you want to Display full month calendar of %d (y/n): ",year);
    scanf(" %c",&choice);

    if(choice == 'n') {
    retry:printf("Please enter the Month number: ");
        scanf("%d",&cmonth);
        if (cmonth <= 0 ||cmonth >12) {    /* months starting from 1 to 12 */
            if(!(countdown--)) {         /* for setting a max no.of retry */
                printf("!! sorry try again...\nclosing...!\n");
                return 0;       /* after all chances used, exit */
            }
            printf("Please  enter a valid month number (1-12)\n");
            goto retry; /*give a chance to re-enter month number */
        }
    }
    else{
        cmonth = 0;         /* this is for printing all the months */
    }
    month=cmonth;
    all=cmonth;
    printf("\n        Year %d Calendar       \n"
            "*********************************\n",year);
    for(month=0;month<=12;month++)
    {
        if(month >0) {                  /* month starting from 1 */
            if(month==cmonth) { /*if the entered cmonth matches to month */
                /*start printing of dates*/
                printf("\n____________%s____________",months[month]);
                printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
                for(day=1; day<=1+code*5; day++) {
                    printf(" ");
                }
                for(day=1;day<=days[month];day++) {
                    printf("%2d",day);
                    if((day+code)%7>0)
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
}
