/*
 * mySet.h
 *
 *  Created on: 2016. 11. 10.
 *      Author: tjddl
 */
#include <iostream>
#ifndef MYSET_H_
#define MYSET_H_
using namespace std;
class mySet
{
private://private 멤버 변수 설정
	int *data;
	int sizeMax, currentSize;
	string name;

public://public 멤버 함수 설정
	mySet()//default 생성자
	{
		cout<<"default constructor"<<endl;
		name = "default";
		sizeMax=3;
		data=new int[sizeMax];
		currentSize =0;
	}
	mySet(int n, string str)//생성자
	{
		cout<<"constructor-2"<<endl;
		name= str;
		sizeMax=n;
		data=new int[sizeMax];
		currentSize =0;
	}
	~mySet()//소멸자
	{
		cout<<"소멸자-"<<name<<endl;
		delete [] data;
	}
	void add(int x)//집합의 원소 추가 함수
	{
		if(currentSize >= sizeMax)//sizeMax를 초과하면 error
		{
			cout<<"error-"<<x<<endl;
			return;
		}
		else if(contains(x)==true)//이미 포함된 원소인 경원  error
		{
			cout<<"error-"<<x<<endl;
			return;
		}
		else//정상적인 상황인 경우 clear
		{
			data[currentSize] = x;
				currentSize++;
			cout<<"clear-"<<x<<endl;
		}
	}
	bool contains(int x)//매개변수x가 집합에 포함되었는지 확인하는 멤버 함수
	{
		for(int i=0; i<currentSize;i++)
		{
			if(data[i] == x)
				return true;
		}
				return false;
	}
};

#endif /* MYSET_H_ */
