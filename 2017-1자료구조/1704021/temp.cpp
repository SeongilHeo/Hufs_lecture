/*
 * lab_01.cpp
 *
 *  Created on: 2017. 3. 30.
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
class Stack
{
private:
      int top;                         // ���ÿ��� ���� ���� �ִ� ����� �迭��ġ
      ItemType data[MAX_STACK_SIZE];   // ��Ҹ� �����ϴ� �迭
public:
      Stack(){top=-1;}      // ���� ������
      ~Stack(){}            // ���� �Ҹ���
      bool isEmpty()        // ������ ����ִ��� Ȯ��
      {		return top==-1;}// ���ÿ��� ���� ���� �ִ� ����� �迭��ġ�� -1�϶� true
      bool isFull()
      {		return top==MAX_STACK_SIZE-1;}// ������ �������ִ��� Ȯ��
      void push(ItemType e)  // ���ÿ� ��Ҹ� ����
      {
    	  if(isFull())      //������ ���������� ��� error
    		  error("Stack is Full");
    	  data[++top]=e;    //top�� ������Ű�� index top�� ���� ����
      }
      ItemType pop( ) // ������ ��Ҹ� ����ϰ� ����
      {
    	  if(isEmpty())   //������ ������� ��� error
    		  error("Stack is Empty");
    	  return data[top--];// ������ ��Ҹ� ��ȯ�ϰ� ����
      }
      ItemType peek( )  // ������ ��Ҹ� ���
      {
    	  if(isEmpty())  //������ ������� ��� error
    		  error("Stack is Empty");
    	  return data[top];// ������ �� ���� ��� ��ȯ
      }
};


bool isOpen(char symbol)// ���� ��ȣ���� Ȯ��
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))
	return true;
else
	return false;
}

bool isClosed(char symbol)// �ݴ� ��ȣ�� Ȯ��
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool matches(char symbol, char openSymbol)// ���� ��ȣ�� �ݴ� ��ȣ�� �´��� Ȯ��
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}


int main()
{
	char symbol;//�Է� ���� ����
	Stack stack;// ���� stack
	bool balanced = true; // ���� ��ȣ���� ������ �´��� �Ǵ�
	char openSymbol;// ���� ��ȣ
	ifstream fin;

	fin.open("test");

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
