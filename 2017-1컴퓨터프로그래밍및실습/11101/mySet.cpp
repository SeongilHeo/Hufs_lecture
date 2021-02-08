/*
 * mySet.cpp
 *
 *  Created on: 2016. 11. 10.
 *      Author: tjddl
 */

#include<iostream>
#include "mySet.h"
using namespace std;

int main()
{
	mySet s;//객체 생성
	mySet r(3, "set2");//객체 생성2
	r.add(1);//1을 r집합에 추가
	r.add(2);//2를 r집합에 추가y
	r.add(2);//2를 r집합에 추가
	r.add(3);//3을 r집합에 추가
	r.add(4);//4를 r집합에 추가


	cout<<"contains(1)-"<<r.contains(1)<<endl;
	cout<<"contains(2)-"<<r.contains(2)<<endl;
	cout<<"contains(3)-"<<r.contains(3)<<endl;
	cout<<"contains(4)-"<<r.contains(4)<<endl;
//1,2,3,4 원소가 집합 r에 포함되어있나 확인 yes(1), no(0)
	return 0;
}

