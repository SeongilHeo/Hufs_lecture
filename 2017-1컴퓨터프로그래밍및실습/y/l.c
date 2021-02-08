/*
 * l.c
 *
 *  Created on: 2016. 10. 17.
 *      Author: tjddl
 */
#include<stdio.h>

int main(void)
{
   int number;

   printf("숫자를 입력해주세요: ");
   fflush(stdout);
   scanf("%i",&number);

   while(number<10)
   {
	   printf("number is %i\n",number);
	   number++;

	   if(number%2==0)
	   {
		   printf("True\n");
		   printf("break number is %i\n", number);
		   break;
	   }
	   else
	   {
		   printf("False\n");
		   continue;
	   }
   }
   return 0;
}

