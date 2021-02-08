/*
 * first.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

typedef int ItemType;

struct Node
{
	ItemType info;
	Node* next;
};

class CircularLinkedList
{
public:
	CircularLinkedList()
	{
		tail=NULL;
	}
	~CircularLinkedList(){}
	void insertLast(int data)
	{
		Node* newNode = new Node;

		newNode->info = data;

		if(tail == NULL)
		{
			tail = newNode;
			tail->next = tail;
		}
		else
		{
			newNode->next = tail->next;
			tail ->next =newNode;
			tail = newNode;
		}
	}
	void printNode()
	{
		Node* location=tail->next;
		while(location != tail)
		{
			cout<<location->info<<endl;
			location = location->next;
		}
	}
	void remove(int s, int j, int k)//��� ���� �Լ�
	{

		Node*  tempLoc;//�ӽó�� ������ ����
		Node*  location=tail->next;//��ġ�� ����Ű�� ���� location �ʱⰪ��

		for(int p=0 ; p < s-1; p++)
		{
			location= location ->next;
		}
		for(int q=0 ; q< k; q++)
		{
			for(int i=1; i < j-1; i++)
			{	location = location->next;	}
			tempLoc=location -> next;
			location -> next= location -> next ->next;
			location=location->next;

			cout<< tempLoc->info<<" ";
		    delete tempLoc;//���� �Ҵ� ����

		}

	}

private:
	Node* tail;
};
int main ()
{
	CircularLinkedList A = CircularLinkedList();
	int n, s, j, k;
	cin>>n>>s>>j>>k;

	for (int i=1; i<=n ; i++)
	{
		A.insertLast(i);
	}


	A.remove(s,j,k);


	return 0;

}

