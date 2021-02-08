/*
 * 10181.cpp
 *
 *  Created on: 2016. 10. 18.
 *      Author: tjddl
 */
#include <iostream>

using namespace std;

int get_average(int score[], int n);
void increment(int score[], int n);

int main(void)
{
	const int STUDENTS = 5;
	int grade[STUDENTS] = {1,2,3,4,5};
	int avg;

	increment(&grade[0],STUDENTS);
	avg = get_average(grade,STUDENTS);
	cout<<"평균은"<<avg<<"입니다.\n";

	return 0;
}
void increment(int score[], int n)
{
	int i;

	for(i=0;i<n;i++)
		++score[i];
	for(int j=0; j<n;j++)
	cout<<score[j];
}
int get_average(int score[], int n)
{
	int i;
	int sum =0;

	for(i =0;i<n;i++)
		sum += score[i];

	return sum/n;
}
