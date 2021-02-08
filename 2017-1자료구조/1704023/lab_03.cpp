/*
 * lab_03.cpp
 *
 *  Created on: 2017. 4. 2.
 *      Author: tjddl
 */
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

struct Parenthesis //����ü ����
{
  char  paren;    // ��ȣ
  int    position;  // ���� ��ġ
  int    line_no;   // ���� ��ȣ
};

typedef struct Parenthesis ItemType; // ����üParenthesis�� ItemType�� ����

const int MAX_STACK_SIZE = 300;//������ �ִ� ũ�� ����

inline void error(const char *message) //error�Լ� ����
{
            cout << message << endl;// �޼��� ���
            exit(1);//����
}

class Stack//���� Ŭ������ ����
{
private:
      int top;                          // ���ÿ��� ���� ���� �ִ� ����� �迭��ġ
      ItemType data[MAX_STACK_SIZE];   // ��Ҹ� �����ϴ� �迭
public:
      Stack(){top=-1;}            // ���� ������
      ~Stack(){}                  // ���� �Ҹ���
      bool isEmpty()//������ ����ִ��� Ȯ��
      {		return top==-1;}
      bool isFull()//������ �������ִ��� Ȯ��
      {		return top==MAX_STACK_SIZE-1;}
      void push(ItemType e)// ���ÿ� ��� ���� �Լ�
      {
    	  if(isFull())
    		  error("Stack is Full");//������ ���� ������ ��� error
    	  data[++top]=e;   	  //���ÿ� ��� ����
      }
      ItemType pop( )// ������ ���� ��� ��� �� ���� �Լ�
      {
    	  if(isEmpty())
    		  error("Stack is Empty");//������ ������� ��� error
    	  return data[top--]; //������ ��� ��ȯ �� ����
      }
      ItemType peek( )//������ ���� ��� ��� �Լ�
      {
    	  if(isEmpty())
    		  error("Stack is Empty");//������ ������� ��� error
    	  return data[top];// ������ ��� ��ȯ
      }
};

bool isOpen(char symbol)// ���� ��ȣ���� Ȯ�� �Լ�
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))
	return true;
else
	return false;
}

bool isClosed(char symbol)//�ݴ� ��ȣ���� Ȯ�� �Լ�
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool matches(char symbol, char openSymbol)// �ݴ� ��ȣ�� ���� ��ȣ�� match�Ǵ� �� Ȯ�� �Լ�
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}



int main()
{
	char symbol;// �Է¹��� ���� symbol
	Stack stack;// ���� stack
	bool balanced = true;//�� ��ȣ�� match�Ǵ� �� �� balanced
	char openSymbol;//���� ��ȣ �Է� open symbol
	struct Parenthesis P;//Parenthesis P����
	int a=0,b=1;//����ü���� �����  �� ��,��ġ ����
	ifstream fin;

	fin.open("testcase15.txt");
	while (fin.get(symbol)&&balanced)// �Է¹��� ���ڰ� �ְ� balanced�� ���� ��� �ݺ�
	{
		if(symbol == '\n')//�ٹٲ��� ���� ���
		{
			b++;//�� �� ����
			a=0;//��ġ �ʱ�ȭ
		}
		if(symbol != '\n')//�Է¹��� ���ڰ� �ٹٲ��� �ƴ� ���
			a++;//��ġ ����
		P.paren= symbol;//�Է� ���� ���� ����ü paren�� ����
		P.position =a;// position�� ��ġ �� ����

			P.line_no=b; // line_no�� �� �� �� ����

		if (isOpen(symbol))// ���� ��ȣ�� ���
			stack.push(P);//���ÿ� push
		else if (isClosed(symbol))//�ݴ� ��ȣ�� ���
		{
			if (stack.isEmpty())//������ ���������
			{
				balanced = false;//balanced�� ������
				if(symbol==')')//)�϶� ����1, ��ȣ, ��ġ, ��  �޽��� ���
				{
					cout<<"error 1: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
					return 0;//���α׷� ����
				}
				else if(symbol=='}')//}�� �� ����2, ��ȣ, ��ġ, ��  �޽��� ���
				{
					cout<<"error 2: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
					return 0;//���α׷� ����
				}
				else if(symbol==']')//]�� �� ����3, ��ȣ, ��ġ, ��  �޽��� ���
				{
					cout<<"error 3: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
					return 0;//���α׷� ����
				}
			}
			else//������ ������� ������
			{
				openSymbol = stack.pop().paren;//���ÿ��� pop�� ���� ��ȣ�� opensymbol�� ����
				balanced = matches(symbol, openSymbol);//matches �Լ� ȣ���Ͽ� �� ������ balanced�� �Է�

				if(balanced == false)//balanced�� �����̸�
				{
					if(symbol==')')//)�϶� ����1, ��ȣ, ��ġ, ��  �޽��� ���
					{
						cout<<"error 1: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
						return 0;//���α׷� ����
					}
					else if(symbol=='}')//}�϶� ����2, ��ȣ, ��ġ, ��  �޽��� ���
					{
						cout<<"error 2: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
						return 0;//���α׷� ����
					}
					else if(symbol==']')//]�϶� ����3, ��ȣ, ��ġ, ��  �޽��� ���
					{
						cout<<"error 3: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
						return 0;//���α׷� ����
					}
				}
			}
		}
	}
    if (!(stack.isEmpty()))//������ ������� ������
   	{
    	if( stack.peek().paren == '(')//������ ��ȣ�� (�϶� ����4, ��ȣ, ��ġ, ��  �޽��� ���
    	{
    		cout<<"error 4: "<<stack.peek().paren<<" at position "<<stack.peek().position<<" in line "<<stack.peek().line_no <<endl;
    	}
    	else if(stack.peek().paren =='{')//������ ��ȣ�� {�϶� ����5, ��ȣ, ��ġ, ��  �޽��� ���
    		cout<<"error 5: "<<stack.peek().paren<<" at position "<<stack.peek().position<<" in line "<<stack.peek().line_no <<endl;
    	else if(stack.peek( ).paren== '[')//������ ��ȣ�� [�϶� ����6, ��ȣ, ��ġ, ��  �޽��� ���
    		cout<<"error 6: "<<stack.peek().paren<<" at position "<<stack.peek().position<<" in line "<<stack.peek().line_no<<endl;
		}
    else if (stack.isEmpty())//������ ��������� ���̹Ƿ�
    	cout << "1" << endl;//1���

    return 0;
}
