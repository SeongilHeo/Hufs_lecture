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
	mySet s;//��ü ����
	mySet r(3, "set2");//��ü ����2
	r.add(1);//1�� r���տ� �߰�
	r.add(2);//2�� r���տ� �߰�y
	r.add(2);//2�� r���տ� �߰�
	r.add(3);//3�� r���տ� �߰�
	r.add(4);//4�� r���տ� �߰�


	cout<<"contains(1)-"<<r.contains(1)<<endl;
	cout<<"contains(2)-"<<r.contains(2)<<endl;
	cout<<"contains(3)-"<<r.contains(3)<<endl;
	cout<<"contains(4)-"<<r.contains(4)<<endl;
//1,2,3,4 ���Ұ� ���� r�� ���ԵǾ��ֳ� Ȯ�� yes(1), no(0)
	return 0;
}

