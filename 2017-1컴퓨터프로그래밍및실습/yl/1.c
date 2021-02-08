/*
 * 1.c
 *
 *  Created on: 2016. 11. 27.
 *      Author: tjddl
 */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define PASS 1
#define FAIL 0

void display_menu();
int check_PW();
void check_balance();
void deposit();
void withdraw();

int balance=50000;

int main()
{
   int service;


   printf("Thank you for using our service");
   fflush(stdout);

   do
   {
      display_menu();
      printf("Please select the service you want\n");
      fflush(stdout);
      scanf("%d",&service);

      switch(service)
      {
         case 1 : check_balance();break;
         case 2 : deposit();break;
         case 3 : withdraw();break;
         case 4 : exit(0);
      }



      printf("Press any key to continue to service.\n");
      fflush(stdout);
      getch();
      system("cls");
    } while (service != 4);

    return 0;
}


void check_balance()
{
   if(check_PW()==PASS)
       printf("Current Balance : %d won \n", balance);
   	   fflush(stdout);
}


void deposit()
{
   int amount;

   printf("\nHow much will you deposit?");
   fflush(stdout);
   scanf("%d", &amount);

   balance += amount;
   printf("\nCurrent balance after deposit : %d won\n", balance);
   fflush(stdout);
}


void withdraw()
{
   int amount;

   if (check_PW() == PASS)
   {
      printf("How much will you withdraw?");
      fflush(stdout);
	  scanf("%d", &amount);
      if (balance < amount)
      {
    	  printf("\nThere is not enough balance. Current balance %d won \n", balance);
      	  fflush(stdout);
      }
      else
      {
         balance -= amount;
         printf("\nCurrent balance after withdraw : %d won \n", balance);
         fflush(stdout);
       }
   }
}


int check_PW()
{
   static int count = 0;
   int system_PW = 1111;
   int limit = 3;
   int input_PW;

   printf("\nPlease enter the system number.");
   fflush(stdout);
   scanf("%d", &input_PW);

   if(input_PW == system_PW)
	   return PASS;

   else
   {
      count++;
      if(count == limit)
      {
         printf("3 password errors! \n");
         fflush(stdout);
         printf("Please visit our service center with your ID \n");
         fflush(stdout);
         exit(0);
      }
      else
      {
         printf("The password is incorrect. %d total errors!\n", count);
         fflush(stdout);
         return FAIL;
      }
   }
}

void display_menu()
{
   printf("\n\n");
   printf("==================\n");
   printf("== 1. Display balance ==\n");
   printf("== 2. deposit ==\n");
   printf("== 3. withdraw ==\n");
   printf("== 4. stop ==\n");
   printf("==================\n");
   fflush(stdout);
}

