/*
 * midterm exam.cpp
 *
 *  Created on: 2016. 10. 25.
 *      Author: tjddl
 */
#include <iostream>

using namespace std;

int dotProduct(int *X, int *Y,int num);

int main (void)
{
	int n=3;

	int *A=new int[n];
	int *B=new int[n];

	A[0]=1,A[1]=2,A[2]=3,B[0]=4,B[1]=5,B[2]=6;

	cout<<dotProduct(A,B,n);

	delete[] A;
	delete[] B;

	return 0;
}
int dotProduct(int *X, int *Y, int num)
{
	int z[num];
	int i,j,k=0;

	for(i=0; i<num; i++)
	{
		z[i]=(*(X+i))*(*(Y+i));
	}
	for(j=0;j<num;j++)
	{
		k=k+z[j];
	}
	return k;
}

