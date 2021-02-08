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
	unsigned long long int compare, everse = 0, temp, original;//������ �Ͱ� �Ųٷ� �� ���� ���ϱ����� ���� ����

    original =num;

    compare = original;//���� �� ���� ������ �Ͱ� �Ųٷ� �Ȱ��� ���ϱ� ����

    while( original!=0 )//������ ���� 0 �� �ƴ϶��
    {
        temp = original % 10;//������ ���� 10���� ���� ������ �� ����
        everse = everse * 10 + temp;//����ҿ� ������ �� ������ �ݺ����� ����
        original = original / 10;//�������ΰ��� ����ҿ� �ٽ� ����
    }


    if (compare == everse)//���� �Է°��� �Ųٷ� �� ���� ���ٸ�.
    	return 1;
   	else//�ƴ϶��
        return 0;

}
unsigned long long int reverse(unsigned long long int num)
{
	int temp;
	unsigned long long int original, verse=0;
	original= num;

	 while( original!=0 )//������ ���� 0 �� �ƴ϶��
	 {
		 temp = original % 10;//������ ���� 10���� ���� ������ �� ����
		 verse = verse * 10 + temp;//����ҿ� ������ �� ������ �ݺ����� ����
		 original = original / 10;//�������ΰ��� ����ҿ� �ٽ� ����
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
	cout<<"����ũ�� ���� ���� : "<<count<<endl;

	return 0;
}


