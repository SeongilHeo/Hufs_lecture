/*
 * 1006.c
 *
 *  Created on: 2016. 10. 6.
 *      Author: tjddl
 */
#include <stdio.h>
#include <stdlib.h>

int unionset (int *, int *);
int intersectionset (int *, int *);

int U = 0, I = 0;//������, �������� ũ�� ���� ����
int *result1;//������, ������ ������ ������
int *result2;

int main ()
{

	int A[] = {1,2,3};//���� A����
	int B[] = {2,3,4,5};//����B����

	printf("SET A = {1, 2, 3}\n"); //����A���
	printf("SET B = {2, 3, 4, 5}\n");//����B���

	unionset(A,B);//������ �Լ�
	intersectionset(A,B);//������ �Լ�

	return 0;
}

int unionset (int *A, int *B)//������ �Լ�
{
	int i, j, k, l;//���ǹ�, �ݺ����� ���� ���� ����




	U = 5;//�������� ũ��

	for(k = 0; k < U; k++)//������ result�迭�� ����
	{

		if((i < 3) && (j < 4))
		{
			if(A[i] < B[j])
			{
				result1[k] = A[i];
				i++;
			}
			else if(A[i] > B[j])
			{
				result1[k] = B[j];
				j++;
			}
			else if(A[i] == B[j])
			{
				result1[k] = A[i];
				i++;
				j++;
			}
		}
		else if(i > 2)
		{
			result1[k] = B[j];
			j++;
		}
		else if(j > 3)
		{
			result1[k] = A[i];
			i++;
		}
	}

	printf("UNION SET = {");//������ �Լ� ���
	for(l = 0; l < 5; l++)
	{
		printf("%d",result1[l]);
		if(l != 4)
		{
			printf(", ");
		}
	}
	printf("}\n");

	return 0;
}

int intersectionset  (int *A, int *B)//������ �Լ�
{
	int i=0, j=0, k, l;//���ǹ�, �ݺ����� ���� ���� ����



	I = 2;//�������� ũ��

	for(i = 0; i < 3; i++)//������ ����
		for(j = 0; j < 4; j++)
		{
			if(A[i] == B[j])
			{
				result2[k] = A[i];
				k++;
			}
		}

	printf("INTERSECTION SET = {");//������ ���
	for(l = 0; l < 2; l++)
	{
		printf("%d",result2[l]);
		if(l != 1)
		{
			printf(", ");
		}
	}
	printf("}\n");

	return 0;
}


