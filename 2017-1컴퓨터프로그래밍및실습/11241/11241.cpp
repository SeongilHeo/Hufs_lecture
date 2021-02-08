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
	int re, im;//��� ���� real part, imaginary

public:
	Complex():re(0), im(0){}//0+0i//�Ű����� ���� ������
	Complex(int x):re(2), im(0){}//2//�Ű����� �ϳ��� ������
	Complex(int x, int y):re(x), im(y){}//x+yi//�Ű����� �ΰ��� ������

	friend ostream& operator<<(ostream& os, const Complex& c)//����Լ���"<<"������ �ߺ�
	{
		os<<c.re<<"+"<<c.im<<"i";
		return os;
	}
	friend float mod(const Complex& c)//���Ҽ��� modulus ���
	{
		return sqrt(c.re*c.re+c.im*c.im);
	}
	friend Complex operator+(const Complex& c1, const Complex& c2)//����Լ���"+"������ �ߺ�
	{
		return Complex(c1.re+c2.re, c1.im+c2.im);
	}
	friend bool operator>(const Complex& a, const Complex& b)//����Լ���">"������ �ߺ�
	{
		return mod(a)>mod(b);
	}
};
void swap(Complex *a, Complex *b)//�� ������ ���� ��ȯ�ϴ� swap�Լ�
{
	Complex temp;

	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(Complex *a,Complex *b, Complex *c)//ū ���� ������� �����ϴ� sort�Լ�
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
	Complex c0;//��ü����
	Complex c1(2);
	Complex c2(1,1);

	cout<<c0<<endl;//0+0i//��ü���� �� Ȯ��
	cout<<c1<<endl;//2+0i
	cout<<c2<<endl;//1+1i

	cout<<mod(c2)<<endl;//c2�� modulus�� Ȯ��
	cout<<c1+c2<<endl;//c1+c2�� �� ���
	cout<<(c1>c2)<<endl;//c1,c2 ũ�� ��


	sort(&c0,&c1,&c2);//����

	cout<<c0<<endl;//2+0i//sortȮ��
	cout<<c1<<endl;//1+1i
	cout<<c2<<endl;//0+0i

	return 0;
}
