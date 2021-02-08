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

struct Parenthesis //구조체 선언
{
  char  paren;    // 괄호
  int    position;  // 문자 위치
  int    line_no;   // 라인 번호
};

typedef struct Parenthesis ItemType; // 구조체Parenthesis를 ItemType로 선언

const int MAX_STACK_SIZE = 300;//스택의 최대 크기 설정

inline void error(const char *message) //error함수 선언
{
            cout << message << endl;// 메세지 출력
            exit(1);//종료
}

class Stack//스택 클래스로 선언
{
private:
      int top;                          // 스택에서 가장 위에 있는 요소의 배열위치
      ItemType data[MAX_STACK_SIZE];   // 요소를 저장하는 배열
public:
      Stack(){top=-1;}            // 스택 생성자
      ~Stack(){}                  // 스택 소멸자
      bool isEmpty()//스택이 비어있는지 확인
      {		return top==-1;}
      bool isFull()//스택이 가득차있는지 확인
      {		return top==MAX_STACK_SIZE-1;}
      void push(ItemType e)// 스택에 요소 삽입 함수
      {
    	  if(isFull())
    		  error("Stack is Full");//스택이 가득 차있을 경우 error
    	  data[++top]=e;   	  //스택에 요소 삽입
      }
      ItemType pop( )// 스택의 맨위 요소 출력 후 제거 함수
      {
    	  if(isEmpty())
    		  error("Stack is Empty");//스택이 비어있을 경우 error
    	  return data[top--]; //스택의 요소 반환 후 제거
      }
      ItemType peek( )//스택의 맨위 요소 출력 함수
      {
    	  if(isEmpty())
    		  error("Stack is Empty");//스택이 비어있을 경우 error
    	  return data[top];// 스택의 요소 반환
      }
};

bool isOpen(char symbol)// 여는 괄호인지 확인 함수
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))
	return true;
else
	return false;
}

bool isClosed(char symbol)//닫는 괄호인지 확인 함수
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
		return true;
	else
		return false;
}

bool matches(char symbol, char openSymbol)// 닫는 괄호와 여는 괄호가 match되는 지 확인 함수
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));
}



int main()
{
	char symbol;// 입력받을 문자 symbol
	Stack stack;// 스택 stack
	bool balanced = true;//두 괄호가 match되는 지 값 balanced
	char openSymbol;//여는 괄호 입력 open symbol
	struct Parenthesis P;//Parenthesis P선언
	int a=0,b=1;//구조체에서 사용할  줄 수,위치 변수
	ifstream fin;

	fin.open("testcase15.txt");
	while (fin.get(symbol)&&balanced)// 입력받은 문자가 있고 balanced가 참일 경우 반복
	{
		if(symbol == '\n')//줄바꿈이 있을 경우
		{
			b++;//줄 수 증가
			a=0;//위치 초기화
		}
		if(symbol != '\n')//입력받은 문자가 줄바꿈이 아닌 경우
			a++;//위치 증가
		P.paren= symbol;//입력 받은 문자 구조체 paren에 대입
		P.position =a;// position의 위치 값 대입

			P.line_no=b; // line_no에 줄 수 값 대입

		if (isOpen(symbol))// 여는 괄호일 경우
			stack.push(P);//스택에 push
		else if (isClosed(symbol))//닫는 괄호일 경우
		{
			if (stack.isEmpty())//스택이 비어있으면
			{
				balanced = false;//balanced가 거짓일
				if(symbol==')')//)일때 에러1, 괄호, 위치, 줄  메시지 출력
				{
					cout<<"error 1: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
					return 0;//프로그램 종료
				}
				else if(symbol=='}')//}일 때 에러2, 괄호, 위치, 줄  메시지 출력
				{
					cout<<"error 2: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
					return 0;//프로그램 종료
				}
				else if(symbol==']')//]일 때 에러3, 괄호, 위치, 줄  메시지 출력
				{
					cout<<"error 3: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
					return 0;//프로그램 종료
				}
			}
			else//스택이 비어있지 않으면
			{
				openSymbol = stack.pop().paren;//스택에서 pop한 것의 괄호를 opensymbol에 대입
				balanced = matches(symbol, openSymbol);//matches 함수 호출하여 참 거짓을 balanced에 입력

				if(balanced == false)//balanced가 거짓이면
				{
					if(symbol==')')//)일때 에러1, 괄호, 위치, 줄  메시지 출력
					{
						cout<<"error 1: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
						return 0;//프로그램 종료
					}
					else if(symbol=='}')//}일때 에러2, 괄호, 위치, 줄  메시지 출력
					{
						cout<<"error 2: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
						return 0;//프로그램 종료
					}
					else if(symbol==']')//]일때 에러3, 괄호, 위치, 줄  메시지 출력
					{
						cout<<"error 3: "<<P.paren<<" at position "<<P.position<<" in line "<<P.line_no <<endl;
						return 0;//프로그램 종료
					}
				}
			}
		}
	}
    if (!(stack.isEmpty()))//스택이 비어있지 않으면
   	{
    	if( stack.peek().paren == '(')//마지막 괄호가 (일때 에러4, 괄호, 위치, 줄  메시지 출력
    	{
    		cout<<"error 4: "<<stack.peek().paren<<" at position "<<stack.peek().position<<" in line "<<stack.peek().line_no <<endl;
    	}
    	else if(stack.peek().paren =='{')//마지막 괄호가 {일때 에러5, 괄호, 위치, 줄  메시지 출력
    		cout<<"error 5: "<<stack.peek().paren<<" at position "<<stack.peek().position<<" in line "<<stack.peek().line_no <<endl;
    	else if(stack.peek( ).paren== '[')//마지막 괄호가 [일때 에러6, 괄호, 위치, 줄  메시지 출력
    		cout<<"error 6: "<<stack.peek().paren<<" at position "<<stack.peek().position<<" in line "<<stack.peek().line_no<<endl;
		}
    else if (stack.isEmpty())//스택이 비어있으면 참이므로
    	cout << "1" << endl;//1출력

    return 0;
}
