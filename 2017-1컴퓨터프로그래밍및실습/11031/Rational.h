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
private://private ��� ����
	int numerator;
	int denominator;

public://public ��� �Լ�
	void setNuminator(int x);//������
	void setDenominator(int y);
	int getNumerator();//������
	int getDenominator();

	void setRational(int x, int y);
	int getRational(int x,int y);

	void printRational();//rational ���

	int getGcd();//�ִ�����

	void reduce();//���м�

	void add(Rational x);//���ϱ�
	void sub(Rational x);//����
	void mult(Rational x);//���ϱ�
	void div(Rational x);//������
};




#endif /* RATIONAL_H_ */
