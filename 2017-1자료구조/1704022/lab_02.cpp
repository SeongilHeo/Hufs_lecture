/*
 * lab_02.cpp\
 *
 *  Created on: 2017. 4. 2.
 *      Author: tjddl
 */
#include<iostream>
#include<cstdlib>

using namespace std;

typedef char ItemType;//ItemType�� char������ typedef

const int MAX_STACK_SIZE = 1000;// stack�� �ִ�ũ��

inline void error(const char *message) // ������ �߻��ϸ� ȣ���Ͽ� ���ڸ� ����ϴ� error�Լ�
{
            cout << message << endl;//���ڸ� ���
            exit(1);//����
}
class Stack//Ŭ���� ����
{
private:
      int top;                         // ���ÿ��� ���� ���� �ִ� ����� �迭��ġ
      ItemType data[MAX_STACK_SIZE];   // ��Ҹ� �����ϴ� �迭
public:
      Stack(){top=-1;}      // ���� ������
      ~Stack(){}            // ���� �Ҹ���
      bool isEmpty()//������ ����ֳ� Ȯ��
      {		return top==-1;}
      bool isFull()//������ ���ֳ� Ȯ��
      {		return top==MAX_STACK_SIZE-1;}
      void push(ItemType e)//���ÿ� ��� ����
      {
    	  if(isFull())
    		  error("Stack is Full");
    	  data[++top]=e;
      }
      ItemType pop( )//������ ��� ��� �� ����
      {
    	  if(isEmpty())
    		  error("Stack is Empty");
    	  return data[top--];
      }
      ItemType peek( )//������ ��� ���
      {
    	  if(isEmpty())
    		  error("Stack is Empty");
    	  return data[top];
      }
};
bool isOpen(char symbol)//���� ��ȣ���� Ȯ��
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))
	return true;
else
	return false;
}

bool isClosed(char symbol)//�ݴ� ��ȣ���� Ȯ��
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool matches(char symbol, char openSymbol)//���� ��ȣ�� �ݴ� ��ȣ�� match �Ǵ��� Ȯ��
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}


int main()
{
	char symbol; //�Է¹��� ���� �޴� ����
	Stack stack; // ���� stack ����
	bool balanced = true; // match �Ǵ��� Ȯ���ϴ� ����
	char openSymbol;//���� ��ȣ�� ������ ����

	while (cin.get(symbol)&&balanced)//���ڰ� �Է� �ǰ� balanced��  ���� ��� �ݺ�
	{
		if (isOpen(symbol))//���� ��ȣ�� ���
			stack.push(symbol);//���ÿ� ����
		else if (isClosed(symbol))//�ݴ� ��ȣ�� ���
		{
			if (stack.isEmpty())//������ ��� ���� ������
			{
				balanced = false;//balaced�� ����
				if(symbol==')')//)�ϰ�� error1���
				{
					cout<<"error 1"<<endl; //error��½� ���α׷� ����
					return 0;
				}
				else if(symbol=='}')//}�ϰ�� error2���
				{
					cout<<"error 2"<<endl; //error��½� ���α׷� ����
					return 0;
				}
				else if(symbol==']')//]�ϰ�� error3���
				{
					cout<<"error 3"<<endl; //error��½� ���α׷� ����
					return 0;
				}
			}
			else//������ ������� ������
			{
				openSymbol = stack.pop();//���ÿ��� pop�Ͽ� opensymbol�� ����
				balanced = matches(symbol, openSymbol);//matches�Լ��� ȣ���Ͽ� balancedȮ��

				if(balanced == false)//balaced�� ������ ���
				{
					if(symbol==')')//)�϶� error1 ���
					{
						cout<<"error 1"<<endl; //error��½� ���α׷� ����
						return 0;
					}
					else if(symbol=='}')//}�϶� error2 ���
					{
						cout<<"error 2"<<endl; //error��½� ���α׷� ����
						return 0;
					}
					else if(symbol==']')//]�϶� error3 ���
					{
						cout<<"error 3"<<endl; //error��½� ���α׷� ����
						return 0;
					}
				}
			}
		}
	}
    if (!(stack.isEmpty()))//������ ������� ������
   	{
    	if( stack.peek() == '(')//(�϶� error4 ���
    		cout<<"error 4"<<endl;
    	else if(stack.peek() =='{')//{�϶� error5 ���
    		cout<<"error 5"<<endl;
    	else if(stack.peek( )== '[')//[�϶�error6 ���
    		cout<<"error 6"<<endl;
	}
    else if (stack.isEmpty())//������ ��������� ���̹Ƿ� 1���
    	cout << "1" << endl;

    return 0;
}

