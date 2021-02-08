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

int U = 0, I = 0;//합집합, 교집합의 크기 변수 설정
int *result1;//합집합, 교집합 저장할 포인터
int *result2;

int main ()
{

	int A[] = {1,2,3};//집합 A정의
	int B[] = {2,3,4,5};//집합B정의

	printf("SET A = {1, 2, 3}\n"); //집합A출력
	printf("SET B = {2, 3, 4, 5}\n");//집합B출력

	unionset(A,B);//합집합 함수
	intersectionset(A,B);//교집합 함수

	return 0;
}

int unionset (int *A, int *B)//합집합 함수
{
	int i, j, k, l;//조건문, 반복문을 위한 변수 설정




	U = 5;//합집합의 크기

	for(k = 0; k < U; k++)//합집합 result배열에 생성
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

	printf("UNION SET = {");//합집합 함수 출력
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

int intersectionset  (int *A, int *B)//교집합 함수
{
	int i=0, j=0, k, l;//조건문, 반복문을 위한 변수 설정



	I = 2;//교집합의 크기

	for(i = 0; i < 3; i++)//교집합 생성
		for(j = 0; j < 4; j++)
		{
			if(A[i] == B[j])
			{
				result2[k] = A[i];
				k++;
			}
		}

	printf("INTERSECTION SET = {");//교집합 출력
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


