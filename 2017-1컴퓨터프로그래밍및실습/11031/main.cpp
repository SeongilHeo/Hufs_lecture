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

	Rational r;//r��ü����
	r.setNuminator(4);//r�� numerator ����
	r.setDenominator(6);//r�� denominator����
	r.setRational(4,6);//r�� rational����


	cout<<"numerator = "<<r.getNumerator()<<endl; //numerator ���
	cout<<"denominator = "<<r.getDenominator()<<endl;//denominator ���

	r.printRational();//r rational���
	cout<<"GCD = "<<r.getGcd()<<endl;//r�� numerator, denominator�� �ִ����� ���
	r.reduce();//r�� ���м��� ��ȯ

	Rational x;//x��ü ����
	x.setNuminator(4);//x�� numerator����
	x.setDenominator(3);//x�� denominator����
	x.printRational();//x�� rational ���
	x.reduce();//x�� ���м��� ��ȯ

	r.add(x);//r,x ���ϱ�

	cout<<"add numerator = "<<r.getNumerator()<<endl;//���� numerator��� ���
	cout<<"add denominator = "<<r.getDenominator()<<endl;//���� denominator��� ���
	r.printRational();//���� ��� ���
	r.reduce();//��� ���м��� ��ȯ

	r.sub(x);//r,x ����
		cout<<"sub numerator = "<<r.getNumerator()<<endl;//�� numerator��� ���
		cout<<"sub denominator = "<<r.getDenominator()<<endl;//�� denominator��� ���
		r.printRational();//�� ��� ���
		r.reduce();//��� ���м��� ��ȯ

	r.mult(x);//r,x ���ϱ�
		cout<<"mult numerator = "<<r.getNumerator()<<endl;//���� numerator��� ���
		cout<<"mult denominator = "<<r.getDenominator()<<endl;//���� denominator��� ���
		r.printRational();//���� ��� ���
		r.reduce();//���м��� ��ȯ

	r.div(x);//r,x ������
		cout<<"mult numerator = "<<r.getNumerator()<<endl;//�������� numerator ��� ���
		cout<<"mult denominator = "<<r.getDenominator()<<endl;//�������� denominator ��� ���
		r.printRational();//�������� ��� ���
		r.reduce();//���м��� ��ȯ
	return 0;
}
