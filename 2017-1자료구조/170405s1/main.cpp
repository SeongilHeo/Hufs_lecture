/*
 * main.cpp
 *
 *  Created on: 2017. 4. 5.
 *      Author: tjddl
 */
#include <iostream>
#include "SimpleLinkedList.h"
using namespace std;

int main()
{
	SimpleLinkedList list;
	int input;
	int n;
	cin >> n;
	for(int i=0; i < n ; i++)
	{
		cin >> input;
		list.insertBefore(input);
	}

	cout<<"출력"<<endl;
	list.printAll();

	/*cout<<"삭제"<<endl;
	list.removeBefore();

	cout<<"출력"<<endl;
	list.printAll();*/

	//return 0;
}

