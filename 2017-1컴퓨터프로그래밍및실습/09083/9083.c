/*
 * 9083.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: tjddl
 */
#include <stdio.h>

int factorial (int);

int main (void)
{
	int a;
	scanf("%d",&a);
	printf("factorial(%d) = %d! = %d", a,a,factorial(a));

	return 0;
}

int factorial (int n)
{
	int i,fact=1;

	for( i=1; i <= n; i++)//변수 fact에 변수 i를 1씩 증가시키며 곱하여 factorial을 계산한다.
	{
		fact= fact* i;
	}
	return fact;
}

