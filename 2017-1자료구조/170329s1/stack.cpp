/*
 * stack.cpp
 *
 *  Created on: 2017. 3. 29.
 *      Author: tjddl
 */
/*
#include "stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int ItemType;

void error(char*message)
{
	cout << message << endl;
	exit(1);
}
Stack::Stack(){top=-1;}
Stack::~Stack(){}
bool Stack::isEmpty()
{	return top==-1;}
bool Stack::isFull()
{	return top==MAX_STACK_SIZE-1;}
void Stack::push(ItemType e)
{
	if(isFull())
		error("Stack is  Full");
	data[++top]=e;
}
ItemType Stack::pop()
{
	if(isEmpty())
		error("Stack is Empty");
	return data[top--];
}
ItemType Stack::peek( )
{
	if(isEmpty())
		error("Stack is Empty");
	return data[top];
}
*/
