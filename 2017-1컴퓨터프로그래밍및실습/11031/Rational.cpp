/*
 * rational.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: tjddl
 */
#include <iostream>
#include "Rational.h"
using namespace std;

void Rational::setNuminator(int x)//numerator ����
{
	numerator=x;
}
void Rational::setDenominator(int y)//denominator ����
{
	denominator =y;
}

int Rational::getNumerator()//numerator ����
{
	return numerator;
}

int Rational::getDenominator()//denominator ����
{
	return denominator;
}
void Rational::setRational(int x,int y)//rational ����
{
	numerator =x, denominator=y;
}
int Rational::getRational(int x,int y)//rational ����
{
	return x/y;
}
void Rational::printRational()//rational ����Ʈ
{
	cout<<"rational = "<<numerator<<"/"<<denominator<<endl;
}
int Rational::getGcd()//�ִ����� ����
{
	int gcd =1;
	for(int i=1; i<=numerator;i++)
	{
		if(numerator%i==0 && denominator%i==0)
			gcd =i;
	}
	return gcd;
}
void Rational::reduce()//���м��� ��ȯ
{
	int gcd= getGcd();
	numerator = numerator /gcd;
	denominator = denominator /gcd;

	cout<<"���м� : "<<numerator<<"/"<<denominator<<endl;
}
void Rational::add(Rational x)//rational�� ���ϱ� �ϴ� �Լ�
{

	numerator = numerator*x.denominator + x.numerator*denominator;
	denominator= x.denominator * denominator;
}
void Rational::sub(Rational x)//rational�� ���� �ϴ� �Լ�
{
	numerator = numerator * x.denominator - x.numerator * denominator;
	denominator = x.denominator * denominator;
}

void Rational::mult(Rational x)//rational�� ���ϱ� �ϴ� �Լ�
{
	numerator = numerator * x.numerator;
	denominator= denominator * x.denominator;
}
void Rational::div(Rational x)//rational�� ������ �ϴ� �Լ�
{
	numerator = numerator * x.denominator;
	denominator = denominator * x.numerator;
}
