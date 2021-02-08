/*
 * 1.c
 *
 *  Created on: 2016. 10. 6.
 *      Author: tjddl
 */
#include <stdio.h>
#include <stdlib.h>

int unionset (int *, int *);
int intersectionset (int *, int *);

int U = 0, I = 0;
int *result;

int main ()
{

	int A[] = {1,2,3};
	int B[] = {2,3,4,5};


	unionset(A,B);
	intersectionset(A,B);

	printf("SET A = {1, 2, 3}\n");
	printf("SET B = {2, 3, 4, 5}\n");


	return 0;
}

int unionset (int *A, int *B)
{
	int i, j, k, l;
	U = 5;
	result = (int*)malloc((U)*sizeof(int));

	for(k = 0; k < U; k++)
	{

		if((i < 3) && (j < 4))
		{
			if(A[i] < B[j])
			{
				result[k] = A[i];
				i++;
			}
			else if(A[i] > B[j])
			{
				result[k] = B[j];
				j++;
			}
			else if(A[i] == B[j])
			{
				result[k] = A[i];
				i++;
				j++;
			}
		}
		else if(i > 2)
		{
			result[k] = B[j];
			j++;
		}
		else if(j > 3)
		{
			result[k] = A[i];
			i++;
		}
	}

	printf("UNION SET = {");
	for(l = 0; l < 5; l++)
	{
		printf("%d",result[l]);
		if(l != 4)
		{
			printf(", ");
		}
	}
	printf("}\n");

	free(result);

	return 0;
}

int intersectionset  (int *A, int *B)
{
	int i, j, k, l;

	result = (int*)malloc((I)*sizeof(int));

	for(i = 0; i < 3; i++)
		for(j = 0; j < 4; j++)
		{
			if(A[i] == B[j])
			{
				result[k] = A[i];
				k++;
			}
		}

	printf("INTERSECTION SET = {");
	for(l = 0; l < 2; l++)
	{
		printf("%d",result[l]);
		if(l != 1)
		{
			printf(", ");
		}
	}
	printf("}\n");

	free(result);

	return 0;
}




