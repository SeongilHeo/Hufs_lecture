/*
 * 9085.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: tjddl
 */
#include <stdio.h>

void printDivisors (int );

int main (void)
{

	int a;
	scanf("%d", &a);
	printDivisors(a);
	return 0;
}

void printDivisors(int x)
{
	int i;

	for(i=1; i <=x; i++)//main 함수에서 입력받은 수를 1부터 1씩 증가시켜 입력받은 수까지 나누었을때 나머지가 0일경우 print한다.
	{
		if(x%i==0)
			printf("%d ", i);
	}
}

