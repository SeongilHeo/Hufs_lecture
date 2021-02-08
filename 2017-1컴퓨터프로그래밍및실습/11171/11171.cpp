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
	Rational():n(0),d(1){}//생성자
	Rational(int x):n(x),d(1){}
	Rational(int x,int y):n(x),d(y){}
	~Rational(){}//소멸자
	friend ostream& operator<<(ostream &os,const Rational& x)// '<<'연산의 역활
	{
		os<<x.n<<"/"<<x.d;
		return os;
	}
	friend Rational operator+(const Rational& x,const Rational& y)//'+'연산을 분수에서 사용
	{

		Rational z;
		z.n=x.n*y.d+y.n*x.d;
		z.d=x.d*y.d;
		z.reduce();

		return z;
	}
	friend Rational operator+(const Rational& x, const int& y)//'+'연산을 분수와 정수에서 사용
	{
		Rational z;
		z.n=x.n+y*x.d;
		z.d=x.d;
		z.reduce();

		return z;
	}
	friend Rational operator+(const int& x, const Rational& y)//'+'연산을 정수와 분수에서 사용
	{
		Rational z;
		z.n=x*y.d+y.n;
		z.d=y.d;
		z.reduce();

		return z;
	}
	int getGcd()//gcd구하기
	{
		int gcd =1;
		for(int i=1; i<=n;i++)
		{
			if(n%i==0 && d%i==0)
				gcd =i;
		}
		return gcd;
	}
	void reduce()//기약분수 만들기
	{
		n=n/ getGcd();
		d=d/ getGcd();
	}
};
int main()
{
	Rational r1;//객체 생성
	Rational r2(2);
	Rational r3(2,3);


	cout<<r1<<endl;//r1,r2,r3 값 확인
	cout<<r2<<endl;
	cout<<r3<<endl;

	r1=r2+r3;//분수+븐수 연산
	cout<<r1<<endl;//확인

	r1=r2+2;//분수+정수 연산
	cout<<r1<<endl;//확인

	r1=2+r3;//정수+분수 연산
	cout<<r1<<endl;//확인


	return 0;
}
