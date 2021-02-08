/*
 * stack.cpp
 *
 *  Created on: 2017. 3. 29.
 *      Author: tjddl
 */

#include "stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int ItemType;

Stack::Stack(){top=-1;}
Stack::~Stack(){}
bool Stack::isEmpty()
{	return top==-1;}
bool Stack::isFull()
{	return top==MAX_STACK_SIZE-1;}
void Stack::push(ItemType e)
{
	if(isFull())
	{
		cout <<"Stack is  Full"<< endl;
		exit(1);
	}
	data[++top]=e;
}
ItemType Stack::pop()
{
	if(isEmpty())
	{
		cout <<"Stack is Empty"<< endl;
		exit(1);
	}
	return data[top--];
}
ItemType Stack::peek( )
{
	if(isEmpty())
	{
		cout <<"Stack is Empty"<< endl;
		exit(1);
	}
	return data[top];
}
