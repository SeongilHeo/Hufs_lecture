/*
 * rational.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: tjddl
 */
#include <iostream>
#include "Rational.h"
using namespace std;

void Rational::setNuminator(int x)//numerator 설정
{
	numerator=x;
}
void Rational::setDenominator(int y)//denominator 설정
{
	denominator =y;
}

int Rational::getNumerator()//numerator 접근
{
	return numerator;
}

int Rational::getDenominator()//denominator 접근
{
	return denominator;
}
void Rational::setRational(int x,int y)//rational 설정
{
	numerator =x, denominator=y;
}
int Rational::getRational(int x,int y)//rational 접근
{
	return x/y;
}
void Rational::printRational()//rational 프린트
{
	cout<<"rational = "<<numerator<<"/"<<denominator<<endl;
}
int Rational::getGcd()//최대공약수 접근
{
	int gcd =1;
	for(int i=1; i<=numerator;i++)
	{
		if(numerator%i==0 && denominator%i==0)
			gcd =i;
	}
	return gcd;
}
void Rational::reduce()//기약분수로 전환
{
	int gcd= getGcd();
	numerator = numerator /gcd;
	denominator = denominator /gcd;

	cout<<"기약분수 : "<<numerator<<"/"<<denominator<<endl;
}
void Rational::add(Rational x)//rational을 더하기 하는 함수
{

	numerator = numerator*x.denominator + x.numerator*denominator;
	denominator= x.denominator * denominator;
}
void Rational::sub(Rational x)//rational을 뺄셈 하는 함수
{
	numerator = numerator * x.denominator - x.numerator * denominator;
	denominator = x.denominator * denominator;
}

void Rational::mult(Rational x)//rational을 곱하기 하는 함수
{
	numerator = numerator * x.numerator;
	denominator= denominator * x.denominator;
}
void Rational::div(Rational x)//rational을 나누기 하는 함수
{
	numerator = numerator * x.denominator;
	denominator = denominator * x.numerator;
}
