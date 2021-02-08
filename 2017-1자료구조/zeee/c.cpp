/*
 * c.cpp
 *
 *  Created on: 2017. 5. 24.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

unsigned long long int palindrome(unsigned long long int num)
{
	unsigned long long int compare, everse = 0, temp, original;//기존의 것과 거꾸로 된 것의 비교하기위해 변수 설정

    original =num;

    compare = original;//저장 할 공간 기존의 것과 거꾸로 된것을 비교하기 위함

    while( original!=0 )//원래의 수가 0 이 아니라면
    {
        temp = original % 10;//원래의 값을 10으로 나눈 나머지 값 저장
        everse = everse * 10 + temp;//저장소에 원래의 값 저장후 반복문을 돌림
        original = original / 10;//나머지인것은 저장소에 다시 저장
    }


    if (compare == everse)//만약 입력값과 거꾸로 된 값이 같다면.
    	return 1;
   	else//아니라면
        return 0;

}
unsigned long long int reverse(unsigned long long int num)
{
	int temp;
	unsigned long long int original, verse=0;
	original= num;

	 while( original!=0 )//원래의 수가 0 이 아니라면
	 {
		 temp = original % 10;//원래의 값을 10으로 나눈 나머지 값 저장
		 verse = verse * 10 + temp;//저장소에 원래의 값 저장후 반복문을 돌림
		 original = original / 10;//나머지인것은 저장소에 다시 저장
	 }

	 return verse;
}
unsigned long long int like (unsigned long long int n)
{
	int i;
	unsigned long long int x=0;
	for(i=1; i<50; i++)
	{
		x= reverse(n)+n;

		if(palindrome(x)==1)
		{
			return 0;
		}
		n=reverse(n)+n;

	}
	return 1;
}

int main ()
{
	int n1, n2;
	int i, count=0;

	cin>>n1>>n2;

	for(i=n1; i<=n2; i++)
	{
		if(like(i)==1)
		{
			count++;
			cout<<i<<endl;
		}
	}
	cout<<"라이크렐 수의 개수 : "<<count<<endl;

	return 0;
}


