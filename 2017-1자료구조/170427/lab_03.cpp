/*
 * lab_03.cpp
 *
 *  Created on: 2017. 4. 27.
 *      Author: tjddl
 */
#include <iostream>
#include <string>
using namespace std;

typedef struct Book ItemType; //list�� info�� ����ü ���

struct Book// book ����ü ����
{
	string Book_num;//���ڿ� ���� ��ȣ
	string Book_id;//���ڿ� ���� �̸�
	int Book_cost;//���� ����
	int Book_quan;//���� ���
};

struct Node//����ü ���
{
	ItemType info;//����� �������ʵ�
	Node *next;//���� ��带 ����Ű�� ������ ����
};
class List//Ŭ���� list
{
private:
	Node *head;//ù��° ��Ҹ� ����Ű�� ������ ����
	int length;//list�� ����
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
	void insert(ItemType B)//list�� ��� ���� (sorted list�� ����)
	{
		Node* location;//��ġ ��带 ����Ű�� ������ ����
	    Node* predLoc;//���� ��带 ����Ű�� ������ ����
	    Node* newNode;//���ο� ���
	    location = head;//���� ��ġ�� ù��° ��� head
	    predLoc = NULL;//���� ����� ������ ����ִ�.
	    while(location != NULL)// list�� ������ ��� ����
	    {
	    	if (B.Book_num > location->info.Book_num)//�� ��Ҹ� list�� �ִ� ��ҵ�� ũ�� �� ���� ��ġ ã��
	        {
	    		predLoc = location;// ���� ���� location�� ����
	            location = location->next;//���� ��带 ���� ���� ����
	        }
	         else//������ �ʵ� ���� �Է°� ���� ���� �ʴ�
	            break;//�ݺ��� Ż��
	    }
	    newNode = new Node;//��� ���� Ȱ�� �Ͽ� newNode������ ����
	    newNode->info = B;//�Է°��� ������ �ʵ忡 ����
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
	void remove(ItemType B)//��� ���� �Լ�
	{
		Node*  location = head ;//��ġ�� ����Ű�� ���� location �ʱⰪ�� ó���� head
		Node*  tempLoc;//�ӽó�� ������ ����
	     if (B.Book_num == head->info.Book_num)//������ ���� ó�� ���̸�
	     {
	    	 tempLoc = location;//location ������ temp�� ����
	    	 head = head->next;//head�� �������� head�� ����Ŵ
	     }
	     else//������ ���� ó�� ���� �ƴϸ�
	     {
	        while( B.Book_num != location->next->info.Book_num)//��ġ�� �������� ������ �ʵ� ���� �Է°��� �ٸ��� �ݺ�
	            location = location->next;//location�� ���� ��带 ����Ŵ
	        tempLoc = location->next;//temp�� ��ġ�� ����Ű�� �� ����
	        location->next = location->next->next;//��ġ�� ����Ű�� ���� ��忡 ���� ��ġ�� next�� ����
	     }
	     delete tempLoc;//���� �Ҵ� ����
	     length--;//���� ����
	}
	ItemType getinfo(ItemType B)//������ �ʵ尪 ��������
	{
		Node*  location ;//��ġ�� ����Ű�� ������ ����
	    location = head ;//location�� �ʱⰪ�� head(ó����)
		bool found = false ;//������ Ȯ���ϴ� �ο� ���� �ʱⰪ ���� (false)
		while (location  !=  NULL &&  !found )//list�� �������� �ƴϰ� ã�� �������� �ݺ�
		{
	           if (location->info.Book_num <  B.Book_num)    //��ġ�� ������ �ʵ� ���� �Է°� ���� �۴�
	                  location = location->next;//���� ��ġ�� �̵�
		     else if (B.Book_num == location->info.Book_num) // ���� ���� ������ �ʵ� �� �߰����� ��
		     {
		    	 found = true;//�������°� ��
		    	 B = location->info;//��ġ�� ������ �ʵ� ���� b��忡 ����
		     }
		     else
		    	 break;
		}
		return B;//ã���� ��ȯ
	}
	bool checkinfo(ItemType B)//������ ���� Ȯ���Լ�
	{
		Node*  location ;//��ġ�� ����Ű�� ������ ����
	    location = head ;//location �ʱⰪ head
		bool found = false ;//������ Ȯ���ϴ� �ο� ���� �ʱⰪ ���� (false)
		while (location  !=  NULL &&  !found )//list�� �������� �ƴϰ� ã�� �������� �ݺ�
		{
	         if (location->info.Book_num <  B.Book_num)       //��ġ�� ������ �ʵ� ���� �Է°� ���� �۴�
	           location = location->next;//���� ��ġ�� �̵�
		     else if (B.Book_num== location->info.Book_num)// ���� ���� ������ �ʵ� �� �߰����� ��
		     {
		    	 found = true;//�������°� ��
		    	 B = location->info;//��ġ�� ������ �ʵ� ���� b��忡 ����
		     }
		     else
		    	 break;
		}
		return found;//���� ���� ��ȯ
	}
	void Plusquan(ItemType B)//��� ������Ű�� �Լ�
	{
		Node*  location ;//������ ���� Ȯ���Լ�
	    location = head ;//location �ʱⰪ head
	    bool found = false;//������ Ȯ���ϴ� �ο� ���� �ʱⰪ ���� (false)
		while (location  !=  NULL &&  !found )//list�� �������� �ƴϰ� ã�� �������� �ݺ�
		{
			if (location->info.Book_num <  B.Book_num) //��ġ�� ������ �ʵ� ���� �Է°� ���� �۴�
			location = location->next;//���� ��ġ�� �̵�
			else if (B.Book_num== location->info.Book_num)// ���� ���� ������ �ʵ� �� �߰����� ��
			{
				found = true;//�������°� ��
				location->info.Book_quan = location->info.Book_quan + B.Book_quan;//�Էµ� ���� ��ŭ ��� ����
			}
			else
				break;
		}
	}
	void Subquan(ItemType B)//��� ���ҽ�Ű�� �Լ�
		{
			Node*  location ;//������ ���� Ȯ���Լ�
		    location = head ;//location �ʱⰪ head
		    bool found = false;//������ Ȯ���ϴ� �ο� ���� �ʱⰪ ���� (false)
			while (location  !=  NULL &&  !found )//list�� �������� �ƴϰ� ã�� �������� �ݺ�
			{
				if (location->info.Book_num <  B.Book_num)//��ġ�� ������ �ʵ� ���� �Է°� ���� �۴�
				location = location->next;//���� ��ġ�� �̵�
				else if (B.Book_num== location->info.Book_num) // ���� ���� ������ �ʵ� �� �߰����� ��
				{
					found = true;//�������°� ��
					location->info.Book_quan = location->info.Book_quan - B.Book_quan;//�Էµ� ���� ��ŭ ��� ����
				}
				else
					break;
			}
		}
	void print()//����ϴ� �Լ�
	{
		Node *location;//��ġ ���
		location = head;//ó�� ��ġ�� head
		for(int i=1; i <= length ; i++)//��� ����Ʈ��ŭ �ݺ�
		{
			cout<<location->info.Book_num<<" "<<location->info.Book_id<<" "<<location->info.Book_cost<<" "<<location->info.Book_quan<<endl;//������ �ʵ尪 ���
			location = location->next;//���� ���� �̵�
		}
	}
};

int main()
{
  List L;//list L����
  List S;//list S����
  string command;  //���ڿ� ��ɾ� ����

  while (1)//���� �ݺ�
  {
     cin >> command;//��ɾ� �Է�
     if (command == "N") // �űԵ��� �԰�
     {
    	ItemType T;//�Է°� �޾��� book����ü

        cin>>T.Book_num>>T.Book_id>>T.Book_cost>>T.Book_quan;//����ü ���� �Է�
        if(L.checkinfo(T) == 1)//�Է°��� �̹� ������
        	cout<<"error: 1"<<endl;//���� 1 ���
        else//�ƴϸ�
        	L.insert(T);//L list�� ����
     }
     else if (command == "R") // ����� ��Ͽ� �ִ� ���� �԰�
     {
    	 ItemType T;//�Է°� �޾��� book����ü

    	 cin>>T.Book_num>>T.Book_quan;//����ü ���� �Է�

    	 if(L.checkinfo(T)==0)//�Է°��� ������
    		 cout<<"error: 2"<<endl;//���� 2 ���
    	 else//�ƴϸ�
    		 L.Plusquan(T);//�Է°��� ��� ���� ����
     }
     else if (command == "S") // ����� ��Ͽ� �ִ� ������ �Ǹ���
     {
    	 ItemType T,K;//�Է°� �޾��� book����ü, �ӽ� ������ book ����ü

    	 cin>>T.Book_num>>T.Book_quan;//����ü ���� �Է�

    	 int A = T.Book_quan;//�Էµ� �Ǹŷ� ������ �ӽ� ����
    	 if(L.checkinfo(T)==0)//�Է°��� list�� ������
    		 cout<<"error: 2"<<endl;//���� 2 ���
    	 else if(L.getinfo(T).Book_quan < T.Book_quan)//����� �Ǹŷ��� �� ������
    		 cout<<"error: 3"<<endl;//���� 3 ���
    	 else
    	{
    		 L.Subquan(T);//��� ����
    		 K = L.getinfo(T);//�Է°��� K�� ����
    		 K.Book_quan= A;//�Ǹŷ��� K�� ������ ����

    		 if(S.checkinfo(K)==0)//K�� S list�� ������
    			 S.insert(K);//S list�� K����
    		 else//�ƴϸ�
    			 S.Plusquan(K);//���� ����
     	 }
     }
	else if (command == "D") // ���� ��� (����� ��Ͽ��� ������ ������)
	{
		ItemType T;//�Է°� �޾��� book����ü

		cin>>T.Book_num;//���� ��ȣ �Է�

		if(L.checkinfo(T)==0)//�Է°��� L list�� ������
			cout<<"error: 2"<<endl;//���� 2 ���
		else
			L.remove(T);//L list���� ����
	}
	else if (command == "I") // ������ ��� ���� ��ȸ
	{
		ItemType T;//�Է°� �޾��� book����ü

		cin>>T.Book_num;//������ ��ȣ �Է�
		if(L.checkinfo(T)==0)//L list�� �Է� ������ ������
			cout<<"error: 2"<<endl;//���� 2 ���
		else
			cout<<L.getinfo(T).Book_num<<" "<<L.getinfo(T).Book_id<<" "<<L.getinfo(T).Book_cost<<" "<<L.getinfo(T).Book_quan<<endl;//������ ���
	}
	else if (command == "P")// ������� ��Ͽ� �ִ� ��� ������ ������(������ȣ, �����̸�, ����, ������)�� ������ȣ ������������ ���
		L.print();
	else if (command == "L")// �Ǹ��� ��� ������ �Ǹ�����(������ȣ, �����̸�, ����, �Ǹż���)�� ������ȣ ������������ ���
		S.print();
     else if (command == "Q")// ���α׷��� ������
       break;
     else
    	 break;
  }

  return 0;
}
