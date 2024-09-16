#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

#define CAR 1
#define SCOOTER 2

struct vehicle
{
 int num;
 int row;
 int col;
 int type;
};

int parkinfo[4][10];
int vehcount;
int carcount;
int scootercount;
struct vehicle * add(int,int,int,int);
void getfreerowcol(int,int * );
void display( );

struct vehicle * add(int t,int num,int row,int col)
{
 struct vehicle *v;
   v =( struct vehicle * )malloc(sizeof(struct vehicle));

    v->type=t;
    v->row=row;
    v->col=col;

    if(t==CAR)
           carcount++;
    else
           scootercount++;
    vehcount++ ;
    parkinfo[row][col]=num;

    return v;
}

void getfreerowcol(int type,int *arr)
{
 int r,c,fromrow=0,torow=2 ;
 if(type==SCOOTER)
    {
     fromrow+=2 ;
     torow+=2 ;
    }
 for(r=fromrow;r<torow;r++)
    {
        for (c=0;c<10;c++)
        {
            if(parkinfo[r][c]==0)
            {
             arr[0]=r;
             arr[1]=c;
             return;
            }
        }
    }
arr[0]=-1 ;
arr[1]=-1 ;
}


void display( )
{
 int r,c;
 printf("Cars->\n");

 for(r=0;r<4;r++)
    {
     if(r==2)
     printf("Scooters->\n");

     for(c=0;c<10;c++)
           printf("%d\t",parkinfo[r][c]);
           printf("\n");
    }
}

void main( )
{
    int  type,number,row=0,col=0;
    int i,tarr[2];
    int finish=1;
    struct vehicle *v;
    char choice[20];
    struct vehicle *car[2][10],*scooter[2][10];

while(finish)
    {
        printf("\n Parking Lot System \n");
        printf("1. Arrival of a vehicle\n");
        printf("2. Total number of vehicles parked\n");
        printf("3. Total number of cars parked\n");
        printf("4. Total number of scooters parked\n");
        printf("5. Display order in which vehicles are parked\n");
        printf("6. Exit\n");
        scanf("%s",choice);

        switch(atoi(choice))
        {
         case 1:
                printf("\n Add: \n");
                type=0;
while(type!=CAR&&type!=SCOOTER)
                {
                 printf("Enter vehicle type (1 for Car / 2 for Scooter ): \n");
                 scanf("%d",&type);
                 if(type!=CAR&&type!=SCOOTER)
                    printf("\nInvalid vehicle type.\n");
                }
                printf("Enter vehicle number: ");
                scanf("%d",&number);
if(type==CAR||type==SCOOTER)
            {
                getfreerowcol(type,tarr);

                 if(tarr[0]!=-1&&tarr[1]!=-1)
                    {
                     row=tarr[0];
                     col=tarr[1];

                     if(type==CAR)
                        car[row][col]=add(type,number,row,col);
                     else
                        scooter[row-2][col]=add(type,number,row,col);
                    }
                    else
                    {
                     if(type==CAR)
                        printf("\nNo parking slot free to park a car\n");
                     else
                        printf("\nNo parking slot free to park a scooter\n");
                    }
                }
                else
                {
                 printf("Invalid type\n");
                 break;
                }

                printf("\nPress any key to continue...");
                getch( );
                break;
        case 2:
                printf("Total vehicles parked: %d\n",vehcount);
                printf("\nPress any key to continue...");
                getch( );
                break;

        case 3:
                printf("Total cars parked: %d\n",carcount);
                printf("\nPress any key to continue...");
                getch( );
                break;

        case 4:
                printf("Total scooters parked: %d\n",scootercount);
                printf("\nPress any key to continue...");
                getch( );
                break;

        case 5:
                printf("Display\n");
                display( );
                printf("\nPress any key to continue...");
                getch( );
                break;
        case 6:
               exit(0);

        default:
                printf("\nEnter valid number\n\n");
        }
    }
}
