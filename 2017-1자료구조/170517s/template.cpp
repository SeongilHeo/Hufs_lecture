/*
 * template.cpp
 *
 *  Created on: 2017. 5. 17.
 *      Author: tjddl
 */

/*template<class ItemType>
void SimpleLinkedList<ItemType>::printAll
*/
/*
#include<iostream>
using namespace std;

template <class ItemType>
void SimpleLinkedList<ItemType>::searchItem()
{
	return search(head, value);
}
template<class ItemType>
void SimpleLinkedList<ItemType>::search(Node<ItemType>*ptr, ItemType value)
{
	if(ptr ==NULL)
	{
		cout<<"해당하는 값이 없음"<<endl;
		return false;
	}
	if(ptr != NULL)
	{
	    if(value== ptr->data)
	    {
	    	cout<<"해당하는 값이 있음"<<endl;
	    	return ture;
	    }
	    else
	    	return searchItem(ptr->next);
	}

}
template<class  >
void SimpleLinkedList<ItemType>::deleteLinkedList(Node<ItemType>*&ptr)
{
	Node<ItemType>* temp = NULL;
	if(ptr != NULL)
	{
		temp=ptr;
		ptr=ptr->next;
		delete temp;
		return deleteLinkedList(ptr);
	}
}
template<class ItemType>
void SimpleLinkedList<ItemType>::deleteAll()
{
	deleteLinkedList(head);
}
template<class ItemType>
void SimpleLinkedList<ItemType>::removeItem(ItemType item)*/
