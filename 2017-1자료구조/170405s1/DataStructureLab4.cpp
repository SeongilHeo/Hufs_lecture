/*
 * DataStructureLab4.cpp
 *
 *  Created on: 2017. 4. 5.
 *      Author: tjddl
 */
#include<iostream>
#include "SimpleLinkedList.h"
using namespace std;

SimpleLinkedList::SimpleLinkedList()
{
	head =NULL;
}
bool SimpleLinkedList::isEmpty() const
{
	if(head != NULL)
		return true;
	else
		return false;
}
void SimpleLinkedList::removeBefore()
{
	/*if(isEmpty())
		cout<<"Error; the list is empty." <<endl;
		return ;
	Node* temp = head;

	cout<< "Remove success!"<<endl;*/
}
void SimpleLinkedList::insertBefore(int insertValue)
{
	Node* tmpPtr;
	tmpPtr = new Node;
	tmpPtr -> info =insertValue;
	tmpPtr -> next =head;
	head =tmpPtr;
}
void SimpleLinkedList::printAll() const
{
	Node* tmpPtr = head;
	while (tmpPtr != NULL)
	{
		cout<<tmpPtr->info<<endl;
		tmpPtr=tmpPtr->next;
	}
}

