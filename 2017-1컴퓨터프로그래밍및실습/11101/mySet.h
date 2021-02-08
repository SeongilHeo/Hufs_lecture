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
private://private ��� ���� ����
	int *data;
	int sizeMax, currentSize;
	string name;

public://public ��� �Լ� ����
	mySet()//default ������
	{
		cout<<"default constructor"<<endl;
		name = "default";
		sizeMax=3;
		data=new int[sizeMax];
		currentSize =0;
	}
	mySet(int n, string str)//������
	{
		cout<<"constructor-2"<<endl;
		name= str;
		sizeMax=n;
		data=new int[sizeMax];
		currentSize =0;
	}
	~mySet()//�Ҹ���
	{
		cout<<"�Ҹ���-"<<name<<endl;
		delete [] data;
	}
	void add(int x)//������ ���� �߰� �Լ�
	{
		if(currentSize >= sizeMax)//sizeMax�� �ʰ��ϸ� error
		{
			cout<<"error-"<<x<<endl;
			return;
		}
		else if(contains(x)==true)//�̹� ���Ե� ������ ���  error
		{
			cout<<"error-"<<x<<endl;
			return;
		}
		else//�������� ��Ȳ�� ��� clear
		{
			data[currentSize] = x;
				currentSize++;
			cout<<"clear-"<<x<<endl;
		}
	}
	bool contains(int x)//�Ű�����x�� ���տ� ���ԵǾ����� Ȯ���ϴ� ��� �Լ�
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
