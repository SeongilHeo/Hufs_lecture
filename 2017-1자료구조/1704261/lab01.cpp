/*
 * 1704261.cpp
 *
 *  Created on: 2017. 4. 26.
 *      Author: tjddl
 */
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

typedef char ItemType;// char���� ItemType���� ����

const int MAX_STACK_SIZE = 1000;//������ �ִ� ũ�� ����

inline void error(const char *message)//error�Լ� ����
{
            cout << message << endl;//�޽����� ����Ѵ�
            exit(1);//�����Ѵ�
}
struct Node// ����Ʈ�� ����ü ���
{
   ItemType  info;// ����� ������ �ʵ�
   Node  *next;// ���� ��带 ����Ű�� ������ ����
};
class Stack// ���� Ŭ����
{
private:
	Node *topPtr;//������ top�� ǥ���� ���
public:
	Stack(){topPtr = NULL;}      // ���� ������
	bool isEmpty() const// ������°˻�
	 {	return topPtr == NULL; }// ���ÿ��� ���� ���� �ִ� ����� �迭��ġ�� -1�϶� true
	void push(ItemType item)  // ���ÿ� ��Ҹ� ����
	 {
	   	Node *newNode;//���ο� ��� ����
	   	newNode = new Node;//��� ���� �Ҵ�
    	newNode->info = item;//�Է°� ������ �ʵ忡 ����
    	newNode->next = topPtr;//���ο� ����� next�� top����
    	topPtr = newNode;//top�� ���ο� ��带 ����ħ
      }
	ItemType pop() // ������ ��Ҹ� ����ϰ� ����
   {
		{
			ItemType item;//��ȯ�� ��� item
			item = topPtr->info;//������ ����� ������ �ʵ带 item�� ����
			topPtr = topPtr ->next;//topPtr�̵�
			return item;//item ��ȯ
		}
   }
	ItemType peek() const  // ������ ��Ҹ� ���
    {
  	  if(isEmpty())  //������ ������� ��� error
  		  error("Stack is Empty");//error�Լ� ȣ��
  	  return topPtr->info;// ������ �� ���� ��� ��ȯ
    }
};


bool isOpen(char symbol)// ���� ��ȣ���� Ȯ��
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))//���� ��ȣ �̸�
	return true;//ture ���
else
	return false;//false ���
}

bool isClosed(char symbol)// �ݴ� ��ȣ�� Ȯ��
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))//�ݴ� ��ȣ �� ��
		return true;//ture ���
	else
		return false;//false ���
}

bool matches(char symbol, char openSymbol)// ���� ��ȣ�� �ݴ� ��ȣ�� �´��� Ȯ��
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));//��ȣ�� ��ġ�Ǹ� ture �ƴϸ� false
}


int main()
{
	char symbol;//�Է� ���� ����
	Stack stack;// ���� stack
	bool balanced = true; // ���� ��ȣ���� ������ �´��� �Ǵ�
	char openSymbol;// ���� ��ȣ
	ifstream fin;

	fin.open("1.txt");

	while (fin.get(symbol)&&balanced)// �Է°��� �ְ�  balanced�� ���� ��� �ݺ�
	{
		if (isOpen(symbol))// ���� ��ȣ�� ���
			stack.push(symbol);//���ÿ� ����
		else if (isClosed(symbol))//�ݴ� ��ȣ�� ���
		{
			if (stack.isEmpty())// ������ ���������
				balanced = false;//������ ����
			else
			{
				openSymbol = stack.pop();//���ÿ� ����ִ� ���� ��ȣ�� ����ؼ� ���� ��ȣ ������ ����
				balanced = matches(symbol, openSymbol);//matches �Լ��� ȣ���Ͽ� ��ȣ ��
			}
		}
	}
    if (!balanced)// ������ ���� ���� ��� -1
    	cout << "-1" << endl;
    else if (stack.isEmpty())//��ȣ�� ��������� �� 1
    	cout << "1" << endl;
    else
    	cout << "-1" << endl;


    return 0;
}


