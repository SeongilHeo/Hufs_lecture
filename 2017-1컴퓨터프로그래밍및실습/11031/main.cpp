/*
 * 11031.cpp
 *
 *  Created on: 2016. 11. 3.
 *      Author: tjddl
 */
#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{

	Rational r;//r객체생성
	r.setNuminator(4);//r의 numerator 설정
	r.setDenominator(6);//r의 denominator설정
	r.setRational(4,6);//r의 rational설정


	cout<<"numerator = "<<r.getNumerator()<<endl; //numerator 출력
	cout<<"denominator = "<<r.getDenominator()<<endl;//denominator 출력

	r.printRational();//r rational출력
	cout<<"GCD = "<<r.getGcd()<<endl;//r의 numerator, denominator의 최대공약수 출력
	r.reduce();//r을 기약분수로 전환

	Rational x;//x객체 생성
	x.setNuminator(4);//x의 numerator설정
	x.setDenominator(3);//x의 denominator설정
	x.printRational();//x의 rational 출력
	x.reduce();//x를 기약분수로 전환

	r.add(x);//r,x 더하기

	cout<<"add numerator = "<<r.getNumerator()<<endl;//더한 numerator결과 출력
	cout<<"add denominator = "<<r.getDenominator()<<endl;//더한 denominator결과 출력
	r.printRational();//더한 결과 출력
	r.reduce();//결과 기약분수로 전환

	r.sub(x);//r,x 빼기
		cout<<"sub numerator = "<<r.getNumerator()<<endl;//뺀 numerator결과 출력
		cout<<"sub denominator = "<<r.getDenominator()<<endl;//뺀 denominator결과 출력
		r.printRational();//뺀 결과 출력
		r.reduce();//결과 기약분수로 전환

	r.mult(x);//r,x 곱하기
		cout<<"mult numerator = "<<r.getNumerator()<<endl;//곱한 numerator결과 출력
		cout<<"mult denominator = "<<r.getDenominator()<<endl;//곱한 denominator결과 출력
		r.printRational();//곱한 결과 출력
		r.reduce();//기약분수로 전환

	r.div(x);//r,x 나누기
		cout<<"mult numerator = "<<r.getNumerator()<<endl;//나누기한 numerator 결과 출력
		cout<<"mult denominator = "<<r.getDenominator()<<endl;//나누기한 denominator 결과 출력
		r.printRational();//나누기한 결과 출력
		r.reduce();//기약분수로 전환
	return 0;
}
