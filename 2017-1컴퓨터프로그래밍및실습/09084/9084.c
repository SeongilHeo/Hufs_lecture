/*
 * 9084.c
 *
 *  Created on: 2016. 9. 8.
 *      Author: tjddl
 */
#include<stdio.h>

int power(int, int);

int main (void)
{
	int d,u;
	scanf("%d", &d);
	scanf("%d", &u);

	printf("power(%d,%d)= %d^%d=%d", d,u,d,u, power(d,u));

	return 0;
}

int power (int x, int n)
{
	int i, p=1;

	for(i=1; i<=n ;i++)//power을 계산하기 위해 변수 p에  main 함수에서 입력받은 밑을 지수만큼 곱한다.
	{
		p=p*x;
	}
	return p;
}

