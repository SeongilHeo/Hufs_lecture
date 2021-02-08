/*
 * 11241.cpp
 *
 *  Created on: 2016. 11. 28.
 *      Author: tjddl
 */
#include<iostream>
#include<math.h>
using namespace std;

class Complex
{
	int re, im;//멤버 변수 real part, imaginary

public:
	Complex():re(0), im(0){}//0+0i//매개변수 없는 생성자
	Complex(int x):re(2), im(0){}//2//매개변수 하나인 생성자
	Complex(int x, int y):re(x), im(y){}//x+yi//매개변수 두개인 생성자

	friend ostream& operator<<(ostream& os, const Complex& c)//멤버함수로"<<"연산자 중복
	{
		os<<c.re<<"+"<<c.im<<"i";
		return os;
	}
	friend float mod(const Complex& c)//복소수의 modulus 계산
	{
		return sqrt(c.re*c.re+c.im*c.im);
	}
	friend Complex operator+(const Complex& c1, const Complex& c2)//멤버함수로"+"연산자 중복
	{
		return Complex(c1.re+c2.re, c1.im+c2.im);
	}
	friend bool operator>(const Complex& a, const Complex& b)//멤버함수로">"연산자 중복
	{
		return mod(a)>mod(b);
	}
};
void swap(Complex *a, Complex *b)//두 변수의 값을 교환하는 swap함수
{
	Complex temp;

	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(Complex *a,Complex *b, Complex *c)//큰 수의 순서대로 정렬하는 sort함수
{
	if (!(*a>*b))
		swap(*a,*b);
	if(!(*b>*c))
	{
		swap(*b,*c);
		if(!(*a>*b))
			swap(*a,*b);
	}
}
int main()//
{
	Complex c0;//객체생성
	Complex c1(2);
	Complex c2(1,1);

	cout<<c0<<endl;//0+0i//객체들의 값 확인
	cout<<c1<<endl;//2+0i
	cout<<c2<<endl;//1+1i

	cout<<mod(c2)<<endl;//c2의 modulus값 확인
	cout<<c1+c2<<endl;//c1+c2의 값 계산
	cout<<(c1>c2)<<endl;//c1,c2 크기 비교


	sort(&c0,&c1,&c2);//정렬

	cout<<c0<<endl;//2+0i//sort확인
	cout<<c1<<endl;//1+1i
	cout<<c2<<endl;//0+0i

	return 0;
}
