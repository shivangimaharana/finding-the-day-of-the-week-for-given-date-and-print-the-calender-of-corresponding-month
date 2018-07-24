#include<stdio.h>
char *day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int tell_the_day(int d,int m,int y)
{
    int code;
    switch(m)   //returns the code for the months
    {
        case 1: code=0;
                break;
        case 2: code=3;
                break;
        case 3: code=3;
                break;
        case 4: code=6;
                break;
        case 5: code=1;
                break;
        case 6: code=4;
                break;
        case 7: code=6;
                break;
        case 8: code=2;
                break;
        case 9: code=5;
                break;
        case 10: code=0;
                break;
        case 11: code=3;
                break;
        case 12: code=5;
                break;
    }
y-=1900;    //returns the century code
int ly= y/4; // returns the leap year to fit into the formula
int sum= d+ code+ y+ ly; //formula
sum%=7;         //modulus will tell the day of the week

    return sum;
}

void print_the_calender(int m,int y)
{
    int a,i,j;
    printf("\n\n\n");
    printf("Su  Mo  Tu  We  Th  Fr  Sa\n\n");   //calender style printing
    a= tell_the_day(1,m,y);     //returns the day of the week when the month starts

        if(y%4==0||(y%100==0&&y%400))   //if its a leap year
        {
            if(m==2)
            {
                mon[1]=29;      //the February has 29 days
                a-=1;           //special arrangement for the leap year's February
            }

            for(i=1;i<=a;i++)
            { printf("XX  ");       //covers the blank space on which there is no date for the given month
            }
        }
        else
        {
            for(i=1;i<=a;i++)
            { printf("XX  ");       //covers the blank space on which there is no date for the given month
            }
        }

    for(j=1;j<=mon[m-1];j++)
    {
        if(j<10)
        {
            printf("0");        //attaches 0 to the single digit dates
            printf("%d  ",j);
        }
        else printf("%d  ",j);  //directly prints the date if it is not single digit

        a++;            //increments the value of sum and let us know if the weekend is approaching
        if(a==7)
        {
            a=0;        //starting the week again
            printf("\n");//prints the corresponding first date of the new week on the next line
        }

    }

}

void main()
{
    int d,m,y;
printf("enter the date:\n");
printf("Date:");
scanf("%d",&d);
printf("Month:");
scanf("%d",&m);
printf("Year:");
scanf("%d",&y);

if(d>31 || m>12)
{
    printf("Invalid date");
    exit(0);
}

    if(y%4==0||(y%100==0&&y%400))
    {
        if(m==2)
          {
            if(d>29)
            {
                printf("Invalid date");
                exit(0);
            }
          }
        else
        {
            if(d>mon[m-1])
            {
                printf("Invalid date");
                exit(0);
            }
        }
    }
    else
    {
        if(d>mon[m-1])
            {
                printf("Invalid date");
                exit(0);
            }
    }

int c=tell_the_day(d,m,y); //finds the day of the week for the given date

printf("the above date falls on:");

     if(y%4==0||(y%100==0&&y%400))
        {
            if(m==2)
              {
                  printf("%s",day[c-1]); //correction for leap year February
              }
            else printf("%s",day[c]);
        }
     else printf("%s",day[c]);

print_the_calender(m,y);    //prints the calender for corresponding month and year

}
