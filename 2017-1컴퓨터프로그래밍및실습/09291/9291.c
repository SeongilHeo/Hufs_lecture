/*
 * 9291.c
 *
 *  Created on: 2016. 9. 29.
 *      Author: tjddl
 */
#include <stdio.h>

void getDigits();
void printDigits();
int digitsToNum();
int getOneDigit();

int num;
int digits[100];
int nDigits;

int main (void)
{
	num=76543;

	printf("%d\n",getOneDigit());
	printf("%d\n",getOneDigit());
	printf("%d\n",getOneDigit());
	printf("%d\n",getOneDigit());
	printf("%d\n",getOneDigit());
	printf("%d\n",getOneDigit());

	printDigits();

	return 0;
}

void getDigits()
{
	int num2=num;
	int i=0;

	for(;;)
	{
		int d = num2%10;
		digits[i]=d;
		i++;
		num2=num2/10;
		printf("%d %d\n", d, num2);

		if(num2==0) break;
	}
	nDigits = i;
}

void printDigits()
{
	int i;

	printf("digits[%d]: ",nDigits);

	for(i=0;i<nDigits;i++)
	{
		printf("%d ",digits[i]);
	}
	printf("\n");
}

int digitsToNum()
{
	int i=0;
	int k=1;
	int numR=0;

		for(i=0;i<nDigits;i++)
		{
			numR=numR+digits[i]*k;
			k=k*10;
		}
		return numR;
}

int getOneDigit()
{
	static int num2=-1;
	static int i=0;
	int d;

	if(num2==-1)
	{
		num2=num;
	}

	d= num2%10;
	if(num2 == 0)
	{
		return -1;
	}
	digits[i]=d;

	num2=num2/10;
	i++;
	nDigits = i;

	return d;
}
