/*
 * 9082.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: tjddl
 */
#include <stdio.h>

int myFunction(int, int);

int main (void)
{
	int a,b,c;
	a=2;
	b=4;
	c=myFunction(a,b);
	printf("%d",c);

	return 0;
}
int myFunction(int x, int y)
{
	int i, z=0;

	for(i =x ; i <=y ; i++)
	{
		z=z+i;
	}

	return z;
}
