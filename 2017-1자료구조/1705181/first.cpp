/*
 * first.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

typedef int ItemType;//������Ÿ������ int������ ����

struct Node//node����ü ����
{
	ItemType info;//����� info��
	Node* next;//����� next�� ����
};

class CircularLinkedList//�������Ḯ��Ʈ
{
public:
	CircularLinkedList()//�������Լ�
	{
		tail=NULL;// tail�� �ʱ�ȭ
	}
	~CircularLinkedList(){}//�Ҹ���
	void insertLast(int data)//�����ͻ����Լ�
	{
		Node* newNode = new Node;//newNode���� �Ҵ�

		newNode->info = data;//�Է°��� info���� ����

		if(tail == NULL)//ó�� �� �Է��϶�
		{
			tail = newNode;//newNode�� tail�� ����Ŵ
			tail->next = tail;//tail�� �ڽſ��� ����
		}
		else//ó���� �ƴҶ�
		{
			newNode->next = tail->next;//newNode�� ó������ ����
			tail ->next =newNode;//������ tail�� newNode�� ����Ŵ
			tail = newNode;//newNode�� tail�� ��
		}
	}
	void printNode()//��� node���
	{
		Node* location=tail->next;//��ġ��Ÿ���� ����Ʈ ��带 ó�������� �ʱ�ȭ
		while(location != tail)//ó������ tail���� �ݺ�
		{
			cout<<location->info<<endl;//location�� data�� ���
			location = location->next;//location�� �������� �ѱ�
		}
	}
	void remove(int s, int j, int k)//��� ���� �Լ��� �Է¹��� s,j,k�� �Ű���������
	{

		Node*  tempLoc;//�ӽó�� ������ ����
		Node*  location=tail->next;//��ġ�� ����Ű�� ���� location �ʱⰪ�� ó�� ��

		for(int p=0 ; p < s-1; p++)//�������� ��Ÿ���� ���� location�̵�
		{
			location= location ->next;//location�̵�
		}
		for(int q=0 ; q< k; q++)//����� ������ŭ �ݺ�
		{
			for(int i=1; i < j-1; i++)//j-1��° ��ŭ �̵�
			{	location = location->next;	}
			tempLoc=location -> next;//������ node�� temp�� ����
			location -> next= location -> next ->next;//������node �� node�� ������ node ���� node�� ����Ŵ
			location=location->next;//����node�� ������ ���� node�� ����

			cout<< tempLoc->info<<" ";//������ node���
		    delete tempLoc;//���� �Ҵ� ����

		}

	}

private:
	Node* tail;//member����tail�� ����
};
int main ()
{
	CircularLinkedList A = CircularLinkedList();//�������Ḯ��Ʈa ���� �� �ʱ�ȭ
	int n, s, j, k;//�Է� ���� 4�� ���� ����
	cin>>n>>s>>j>>k;//���� 4�� �Է�

	for (int i=1; i<=n ; i++)//n�� ��ŭ �Է�
	{
		A.insertLast(i);//insert�Լ� ȣ��
	}


	A.remove(s,j,k);//remove�Լ� ȣ��


	return 0;//���α׷� ����

}

