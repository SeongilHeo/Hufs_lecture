/*
 * lab_02.cpp\
 *
 *  Created on: 2017. 4. 2.
 *      Author: tjddl
 */
#include<iostream>
#include<cstdlib>

using namespace std;

typedef char ItemType;//ItemType를 char형으로 typedef

const int MAX_STACK_SIZE = 1000;// stack의 최대크기

inline void error(const char *message) // 에러가 발생하면 호출하여 문자를 출력하는 error함수
{
            cout << message << endl;//문자를 출력
            exit(1);//종료
}
class Stack//클래스 선언
{
private:
      int top;                         // 스택에서 가장 위에 있는 요소의 배열위치
      ItemType data[MAX_STACK_SIZE];   // 요소를 저장하는 배열
public:
      Stack(){top=-1;}      // 스택 생성자
      ~Stack(){}            // 스택 소멸자
      bool isEmpty()//스택이 비어있나 확인
      {		return top==-1;}
      bool isFull()//스택이 차있나 확인
      {		return top==MAX_STACK_SIZE-1;}
      void push(ItemType e)//스택에 요소 삽입
      {
    	  if(isFull())
    		  error("Stack is Full");
    	  data[++top]=e;
      }
      ItemType pop( )//스택의 요소 출력 후 제거
      {
    	  if(isEmpty())
    		  error("Stack is Empty");
    	  return data[top--];
      }
      ItemType peek( )//스택의 요소 출력
      {
    	  if(isEmpty())
    		  error("Stack is Empty");
    	  return data[top];
      }
};
bool isOpen(char symbol)//여는 괄호인지 확인
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))
	return true;
else
	return false;
}

bool isClosed(char symbol)//닫는 괄호인지 확인
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool matches(char symbol, char openSymbol)//여는 괄호와 닫는 괄호가 match 되는지 확인
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}


int main()
{
	char symbol; //입력받을 문자 받는 변수
	Stack stack; // 스택 stack 선언
	bool balanced = true; // match 되는지 확인하는 변수
	char openSymbol;//여는 괄호를 대입할 변수

	while (cin.get(symbol)&&balanced)//문자가 입력 되고 balanced가  참일 경우 반복
	{
		if (isOpen(symbol))//여는 괄호일 경우
			stack.push(symbol);//스택에 삽입
		else if (isClosed(symbol))//닫는 괄호일 경우
		{
			if (stack.isEmpty())//스택이 비어 있지 않으면
			{
				balanced = false;//balaced는 거짓
				if(symbol==')')//)일경우 error1출력
				{
					cout<<"error 1"<<endl; //error출력시 프로그램 종료
					return 0;
				}
				else if(symbol=='}')//}일경우 error2출력
				{
					cout<<"error 2"<<endl; //error출력시 프로그램 종료
					return 0;
				}
				else if(symbol==']')//]일경우 error3출력
				{
					cout<<"error 3"<<endl; //error출력시 프로그램 종료
					return 0;
				}
			}
			else//스택이 비어있지 않으면
			{
				openSymbol = stack.pop();//스택에서 pop하여 opensymbol에 대입
				balanced = matches(symbol, openSymbol);//matches함수를 호출하여 balanced확인

				if(balanced == false)//balaced가 거짓일 경우
				{
					if(symbol==')')//)일때 error1 출력
					{
						cout<<"error 1"<<endl; //error출력시 프로그램 종료
						return 0;
					}
					else if(symbol=='}')//}일때 error2 출력
					{
						cout<<"error 2"<<endl; //error출력시 프로그램 종료
						return 0;
					}
					else if(symbol==']')//]일때 error3 출력
					{
						cout<<"error 3"<<endl; //error출력시 프로그램 종료
						return 0;
					}
				}
			}
		}
	}
    if (!(stack.isEmpty()))//스택이 비어있지 않으면
   	{
    	if( stack.peek() == '(')//(일때 error4 출력
    		cout<<"error 4"<<endl;
    	else if(stack.peek() =='{')//{일때 error5 출력
    		cout<<"error 5"<<endl;
    	else if(stack.peek( )== '[')//[일때error6 출력
    		cout<<"error 6"<<endl;
	}
    else if (stack.isEmpty())//스택이 비어있으면 참이므로 1출력
    	cout << "1" << endl;

    return 0;
}

