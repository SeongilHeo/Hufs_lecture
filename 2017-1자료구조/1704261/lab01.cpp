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

typedef char ItemType;// char형을 ItemType으로 정의

const int MAX_STACK_SIZE = 1000;//스택이 최대 크기 설정

inline void error(const char *message)//error함수 정의
{
            cout << message << endl;//메시지를 출력한다
            exit(1);//종료한다
}
struct Node// 리스트의 구조체 노드
{
   ItemType  info;// 노드의 데이터 필드
   Node  *next;// 다음 노드를 가리키는 포인터 변수
};
class Stack// 스택 클래스
{
private:
	Node *topPtr;//스택의 top을 표시할 노드
public:
	Stack(){topPtr = NULL;}      // 스택 생성자
	bool isEmpty() const// 공백상태검사
	 {	return topPtr == NULL; }// 스택에서 가장 위에 있는 요소의 배열위치가 -1일때 true
	void push(ItemType item)  // 스택에 요소를 삽입
	 {
	   	Node *newNode;//새로운 노드 선언
	   	newNode = new Node;//노드 동적 할당
    	newNode->info = item;//입력값 데이터 필드에 대입
    	newNode->next = topPtr;//새로운 노드의 next에 top대입
    	topPtr = newNode;//top이 새로운 노드를 가르침
      }
	ItemType pop() // 스택의 요소를 출력하고 제거
   {
		{
			ItemType item;//반환할 요소 item
			item = topPtr->info;//맨위의 요소의 데이터 필드를 item에 대입
			topPtr = topPtr ->next;//topPtr이동
			return item;//item 반환
		}
   }
	ItemType peek() const  // 스택의 요소를 출력
    {
  	  if(isEmpty())  //스택이 비어있을 경우 error
  		  error("Stack is Empty");//error함수 호출
  	  return topPtr->info;// 스택의 맨 위의 요소 반환
    }
};


bool isOpen(char symbol)// 여는 괄호인지 확인
{
if ((symbol == '(') || (symbol == '{') || (symbol == '['))//여는 괄호 이면
	return true;//ture 출력
else
	return false;//false 출력
}

bool isClosed(char symbol)// 닫는 괄호를 확인
{
	if ((symbol == ')') || (symbol == '}') || (symbol == ']'))//닫는 괄호 일 때
		return true;//ture 출력
	else
		return false;//false 출력
}

bool matches(char symbol, char openSymbol)// 여는 괄호와 닫는 괄호가 맞는지 확인
{
	return (((openSymbol == '(') && symbol == ')') || ((openSymbol == '{') && symbol == '}') || ((openSymbol == '[') && symbol == ']'));//괄호가 매치되면 ture 아니면 false
}


int main()
{
	char symbol;//입력 받을 문자
	Stack stack;// 스택 stack
	bool balanced = true; // 받은 괄호들이 균형이 맞는지 판단
	char openSymbol;// 여는 괄호
	ifstream fin;

	fin.open("1.txt");

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


