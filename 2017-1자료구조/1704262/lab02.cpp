/*
 * lab02.cpp
 *
 *  Created on: 2017. 4. 26.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;

typedef string ItemType;//string�ڷ����� ItemType���� �ڷ��� ����

struct Node//����ü ���
{
	ItemType info;//����� ������ �ʵ�
	Node *next;//���� ��带 ����Ű�� ������ ����
};
class List//Ŭ���� list
{
private:
	Node *head;//ù��° ��Ҹ� ����Ű�� ������ ����
	int length;
public:
	List()//������
	{
		head = NULL;//head�ʱ�ȭ
		length = 0;//���� �ʱ�ȭ
	}
	~List(){}//�Ҹ���
	bool isEmpty()//������� Ȯ��
	{
		if(head == NULL)//head�� ����Ű�� ���� ������
			return true;//true ���
		else//�ƴϸ�
			return false;//false ���
	}
	void insert(string Str)//��� ���� �Լ�(sorted list�� ����)
	{
		Node* location;//��ġ ��带 ����Ű�� ������ ����
	    Node* predLoc;//���� ��带 ����Ű�� ������ ����
	    Node* newNode;//���ο� ���
	    location = head;//���� ��ġ�� ù��° ��� head
	    predLoc = NULL;//���� ����� ������ ����ִ�.
	    while(location != NULL)//����Ʈ�� �������� �ƴϸ�
	    {
	    	if (Str>location->info)//������ �ʵ� ���� �Է°����� ������ ���� ����
	        {
	    		predLoc = location;// ���� ���� location�� ����
	            location = location->next;//���� ��带 ���� ���� ����
	         }
	         else//������ �ʵ� ���� �Է°� ���� ���� �ʴ�
	            break;//�ݺ��� Ż��
	    }
	    newNode = new Node;//��� ���� �Ҵ� �Ͽ� newNode������ ����
	    newNode->info = Str;//�Է°��� ������ �ʵ忡 ����
	    if (predLoc == NULL)//list�� ��� ������
	    {
	    	newNode->next = head;//newNode�� head�� ����Ű�� ��带 ����Ŵ
	        head = newNode;//head�� newNode�� ����Ŵ
	    }
	    else
	    {
	    	newNode->next = location;//���ο� ����� next�� ���� ���(location)�� ����Ŵ
	        predLoc->next = newNode;//������Ұ� ����Ű�� ��尡 ���ο� ��带 ����Ŵ
	     }
	     length++;//��������
	}
	void remove(string Str)//��� ���� �Լ�
	{
		Node*  location = head ;//��ġ�� ����Ű�� ���� location �ʱⰪ�� ó���� head
		Node*  tempLoc;//�ӽó�� ������ ����
	     if (Str == head->info)//������ ���� ó�� ���̸�
	     {
	    	 tempLoc = location;//location ������ temp�� ����
	    	 head = head->next;//head�� �������� head�� ����Ŵ
	     }
	     else//������ ���� ó�� ���� �ƴϸ�
	     {
	        while( Str != location->next->info)//��ġ�� �������� ������ �ʵ� ���� �Է°��� �ٸ��� �ݺ�
	            location = location->next;//location�� ���� ��带 ����Ŵ
	        tempLoc = location->next;//temp�� ��ġ�� ����Ű�� �� ����
	        location->next = location->next->next;//��ġ�� ����Ű�� ���� ��忡 ���� ��ġ�� next�� ����
	     }
	     delete tempLoc;//���� �Ҵ� �ݳ�
	     length--;//���� ����
	}

	int size() const//����Ʈ�� ũ��Ȯ�� �Լ�
	{
		cout<<length<<endl;//���� ���

		return 0;
	}
	void print()//����ϴ� �Լ�
	{
		Node *location;//��ġ ���
		location = head;//ó�� ��ġ�� head
		for(int i=1; i <= length ; i++)//��� ����Ʈ��ŭ �ݺ�
		{
			cout<<location->info<<" ";//������ �ʵ尪 ���
			location = location->next;//���� ���� �̵�
		}
		cout<<endl;//�ٹٲ� ���
	}
};

int main()
{
	List L;//list L����
	string command;//���ڿ� ��ɾ� ����
	string st_id;//���ڿ�  �й� ����
	while(1)//���� �ݺ�
	{
		cin>>command;//��ɾ� �Է�
		if(command == "N")//N��� �й��� id�� �л��� ������û�� ��
		{
			cin>>st_id;//�й� �Է�
			L.insert(st_id);//�л� ����
		}
		else if(command == "C")//C��� �й��� id�� �л��� ������û�� �����
		{
			cin>>st_id;//�й� �Է�
			L.remove(st_id);//�л� ����
		}
		else if(command =="P")//P���  ���� �л����� �й�����(��������)��� ���
		{
			L.print();//�л��� ���
		}
		else if(command =="S")//S��� ���� �л����� ���
		{
			L.size();//�л���
		}
		else if(command == "Q")//Q��� ������
		{
			break;//���α׷� ����
		}
	}

	return 0;
}
