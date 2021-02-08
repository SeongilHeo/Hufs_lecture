/*
 * main.cpp
 *
 *  Created on: 2017. 3. 22.
 *      Author: tjddl
 */
#include<iostream>
#include "fraction.h"
using namespace std;

int main()
{
	Fraction A,B,C,D,E;

	A.read();
	B.read();

	A.addFrac(B);
	C=A.operator +(B);
	D=A+B;
	E = addFrac(A,B);

	cout<<C.getnum()<<" "<< C.getdenom()<<endl;
	cout<<D.getnum()<<" "<< D.getdenom()<<endl;
	cout<<E.getnum()<<" "<< E.getdenom()<<endl;
	return 0;
}

