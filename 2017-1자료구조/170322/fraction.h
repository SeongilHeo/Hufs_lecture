/*
 * fraction.h
 *
 *  Created on: 2017. 3. 22.
 *      Author: tjddl
 */

#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction
{
private:
	int num;
	int denom;
public:
	void read();
	int getnum();
	int getdenom();
	void setnum(int x);
	void setdenom(int x);
	Fraction addFrac(Fraction);
	Fraction operator +(Fraction);
	int Gcd();
};
Fraction addFrac(Fraction bunsu1, Fraction bunsu2);

#endif /* FRACTION_H_ */
