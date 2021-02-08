/*
 * 11171.cpp
 *
 *  Created on: 2016. 11. 17.
 *      Author: tjddl
 */
#include <iostream>
using namespace std;

class Rational
{
	int n,d;

public:
	Rational():n(0),d(1){}//������
	Rational(int x):n(x),d(1){}
	Rational(int x,int y):n(x),d(y){}
	~Rational(){}//�Ҹ���
	friend ostream& operator<<(ostream &os,const Rational& x)// '<<'������ ��Ȱ
	{
		os<<x.n<<"/"<<x.d;
		return os;
	}
	friend Rational operator+(const Rational& x,const Rational& y)//'+'������ �м����� ���
	{

		Rational z;
		z.n=x.n*y.d+y.n*x.d;
		z.d=x.d*y.d;
		z.reduce();

		return z;
	}
	friend Rational operator+(const Rational& x, const int& y)//'+'������ �м��� �������� ���
	{
		Rational z;
		z.n=x.n+y*x.d;
		z.d=x.d;
		z.reduce();

		return z;
	}
	friend Rational operator+(const int& x, const Rational& y)//'+'������ ������ �м����� ���
	{
		Rational z;
		z.n=x*y.d+y.n;
		z.d=y.d;
		z.reduce();

		return z;
	}
	int getGcd()//gcd���ϱ�
	{
		int gcd =1;
		for(int i=1; i<=n;i++)
		{
			if(n%i==0 && d%i==0)
				gcd =i;
		}
		return gcd;
	}
	void reduce()//���м� �����
	{
		n=n/ getGcd();
		d=d/ getGcd();
	}
};
int main()
{
	Rational r1;//��ü ����
	Rational r2(2);
	Rational r3(2,3);


	cout<<r1<<endl;//r1,r2,r3 �� Ȯ��
	cout<<r2<<endl;
	cout<<r3<<endl;

	r1=r2+r3;//�м�+��� ����
	cout<<r1<<endl;//Ȯ��

	r1=r2+2;//�м�+���� ����
	cout<<r1<<endl;//Ȯ��

	r1=2+r3;//����+�м� ����
	cout<<r1<<endl;//Ȯ��


	return 0;
}
