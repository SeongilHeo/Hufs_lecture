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

	for(i=1; i <=x; i++)//main �Լ����� �Է¹��� ���� 1���� 1�� �������� �Է¹��� ������ ���������� �������� 0�ϰ�� print�Ѵ�.
	{
		if(x%i==0)
			printf("%d ", i);
	}
}

