/*
 * Rational.h
 *
 *  Created on: 2016. 11. 3.
 *      Author: tjddl
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational
{
private://private 멤버 변수
	int numerator;
	int denominator;

public://public 멤버 함수
	void setNuminator(int x);//설정자
	void setDenominator(int y);
	int getNumerator();//접근자
	int getDenominator();

	void setRational(int x, int y);
	int getRational(int x,int y);

	void printRational();//rational 출력

	int getGcd();//최대공약수

	void reduce();//기약분수

	void add(Rational x);//더하기
	void sub(Rational x);//빼기
	void mult(Rational x);//곱하기
	void div(Rational x);//나누기
};




#endif /* RATIONAL_H_ */
