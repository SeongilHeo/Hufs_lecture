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

	cout<<"���"<<endl;
	list.printAll();

	/*cout<<"����"<<endl;
	list.removeBefore();

	cout<<"���"<<endl;
	list.printAll();*/

	//return 0;
}

