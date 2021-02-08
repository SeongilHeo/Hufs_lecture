/*
 * 10051.c
 *
 *  Created on: 2016. 10. 5.
 *      Author: tjddl
 */
#include <stdio.h>
#include <math.h>
#define SIZE 3

int sum(int *, int );
float mean(int *,int );
float variance(int *, int );
float std(int *, int );

int main()
{
	int a[SIZE] = {1, 2, 3};


	printf("%d\n", sum(a, SIZE));
	printf("%f\n", mean(a, SIZE));
	printf("%f\n", variance(a, SIZE));
	printf("%f\n", std(a, SIZE));

	return 0;
}

int sum(int *a, int n)
{
	int i=0, asum=0;

	for(i=0; i<n; i++)
	{
		asum= asum+ *(a+i);
	}

	return asum;
}
float mean(int *a, int n)
{
	float average;

	average = sum(a, SIZE)/n;

   return average;
}
float variance(int *a, int n)
{
	int i;
	float m = 0, s = 0, v = 0;

	m = mean(a, SIZE);

	for(i=1; i <= n ; i++)
	{
		s = s + ((i-m) * (i-m));
	}

	v = s/n;

	return v;
}
float std(int *a, int n)
{
	float dev;

	dev = sqrt(variance(a, SIZE));

	return dev;
}
