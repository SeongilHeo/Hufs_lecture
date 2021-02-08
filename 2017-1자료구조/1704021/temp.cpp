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

typedef char ItemType;// char형을 ItemType으로 정의

const int MAX_STACK_SIZE = 1000;//스택이 최대 크기 설정

inline void error(const char *message)//error함수 정의
{
            cout << message << endl;//메시지를 출력한다
            exit(1);//종료한다
}
class Stack
{
private:
      int top;                         // 스택에서 가장 위에 있는 요소의 배열위치
      ItemType data[MAX_STACK_SIZE];   // 요소를 저장하는 배열
public:
      Stack(){top=-1;}      // 스택 생성자
      ~Stack(){}            // 스택 소멸자
      bool isEmpty()        // 스택이 비어있는지 확인
      {		return top==-1;}// 스택에서 가장 위에 있는 요소의 배열위치가 -1일때 true
      bool isFull()
      {		return top==MAX_STACK_SIZE-1;}// 스택이 가득차있는지 확인
      void push(ItemType e)  // 스택에 요소를 삽입
      {
    	  if(isFull())      //스택이 가득차있을 경우 error
    		  error("Stack is Full");
    	  data[++top]=e;    //top을 증가시키고 index top에 변수 대입
      }
      ItemType pop( ) // 스택의 요소를 출력하고 제거
      {
    	  if(isEmpty())   //스택이 비어있을 경우 error
    		  error("Stack is Empty");
    	  return data[top--];// 스택의 요소를 반환하고 제거
      }
      ItemType peek( )  // 스택의 요소를 출력
      {
    	  if(isEmpty())  //스택이 비어있을 경우 error
    		  error("Stack is Empty");
    	  return data[top];// 스택의 맨 위의 요소 반환
      }
};


bool isOpen(char symbol)// 여는 괄호인지 확인
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))
	return true;
else
	return false;
}

bool isClosed(char symbol)// 닫는 괄호를 확인
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool matches(char symbol, char openSymbol)// 여는 괄호와 닫는 괄호가 맞는지 확인
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}


int main()
{
	char symbol;//입력 받을 문자
	Stack stack;// 스택 stack
	bool balanced = true; // 받은 괄호들이 균형이 맞는지 판단
	char openSymbol;// 여는 괄호
	ifstream fin;

	fin.open("test");

	while (fin.get(symbol)&&balanced)// 입력값이 있고  balanced가 참일 경우 반복
	{
		if (isOpen(symbol))// 여는 괄호일 경우
			stack.push(symbol);//스택에 삽입
		else if (isClosed(symbol))//닫는 괄호일 경우
		{
			if (stack.isEmpty())// 스택이 비어있으면
				balanced = false;//균형이 맞지
			else
			{
				openSymbol = stack.pop();//스택에 들어있는 여는 괄호를 출력해서 여는 괄호 변수에 대입
				balanced = matches(symbol, openSymbol);//matches 함수를 호출하여 괄호 비교
			}
		}
	}
    if (!balanced)// 균형이 맞지 않을 경우 -1
    	cout << "-1" << endl;
    else if (stack.isEmpty())//괄호가 비어있으면 참 1
    	cout << "1" << endl;
    else
    	cout << "-1" << endl;

    return 0;
}
