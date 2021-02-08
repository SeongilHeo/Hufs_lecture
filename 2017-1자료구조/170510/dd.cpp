/*
  dd.cpp
 *
 *  Created on: 2017. 5. 10.
 *      Author: tjddl
 */
#include <iostream>
using namespace std;

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}
int array_max1(int L[],int len)
{
	if(len ==1);
		return L[0];

	return max(array_max1(L,len-1),L[len-1]);
}
int array_max2(int L[], int first, int last)
{
	if(first ==last)
		return L[first];

	int mid = (first+last)/2;
	return max(array_max2(L,first, mid),array_max2(L,mid+1,last));
}
int main ()
{
	int L[5]={2,10,30,5,3};

	cout<<array_max1(L,5)<<endl;

	cout<<array_max2(L, 0,4);

	return 0;
}







