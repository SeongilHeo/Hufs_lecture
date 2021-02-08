/*
 * lab_02.cpp
 *
 *  Created on: 2017. 3. 22.
 *      Author: tjddl
 */
#include<iostream>
#include "fraction.h"
using namespace std;

void Fraction ::read()
{
	cin>>num>>denom;
}
int Fraction :: getnum()
{
	return num;
}
int Fraction :: getdenom()
{
	return denom;
}
void Fraction :: setnum(int x)
{
	num=x;
}
void Fraction :: setdenom(int x)
{
	denom=x;
}
int Fraction :: Gcd()
{
	int gcd=1;
	for(int i=1; i <num ; i++)
	{
		if((num%i==0) && (denom%i==0))
			gcd=i;
	}
	return gcd;
}
Fraction Fraction::addFrac(Fraction bunsu)
{
   Fraction result;
   result.denom = denom*bunsu.getdenom();
   result.num = num * bunsu.denom + denom * bunsu.num;

   if (result.num == 0)
   {
     result.setdenom(1);
     return result;
   }
   if(result.denom < 0)
   {
	   result.setnum(result.getnum()*-1);
	   result.setdenom(result.getdenom()*-1);
   }
   result.num=result.num / result.Gcd();
   result.denom=result.denom/ result.Gcd();

   return result;
}
Fraction Fraction ::operator +(Fraction bunsu)
{
	 Fraction result;
	   result.denom = denom * bunsu.getdenom();
	   result.num = num * bunsu.denom + denom * bunsu.num;

	   if (result.num == 0)
	   {
	     result.setdenom(1);
	     return result;
	   }
	   if(result.denom < 0)
	   {
		   result.setnum(result.getnum()*-1);
		   result.setdenom(result.getdenom()*-1);
	   }
	   result.num=result.num / result.Gcd();
	   result.denom=result.denom/ result.Gcd();

	   return result;
}
Fraction addFrac(Fraction bunsu1, Fraction bunsu2)
{
   Fraction result;
   result.setdenom(bunsu1.getdenom()*bunsu2.getdenom());
   result.setnum(bunsu1.getnum() * bunsu2.getdenom() + bunsu1.getdenom() * bunsu2.getnum());

   if (result.getnum() == 0)
   {
     result.setdenom(1);
     return result;
   }
   if(result.getdenom() < 0)
   {
	   result.setnum(result.getnum()*-1);
	   result.setdenom(result.getdenom()*-1);
   }
   result.setnum(result.getnum() / result.Gcd());
   result.setdenom(result.getdenom()/ result.Gcd());

   return result;
}

