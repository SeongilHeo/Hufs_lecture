/*
 * lab02.cpp
 *
 *  Created on: 2017. 4. 26.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;

typedef string ItemType;//string자료형을 ItemType으로 자료형 정의

struct Node//구조체 노드
{
	ItemType info;//노드의 데이터 필드
	Node *next;//다음 노드를 가리키는 포인터 변수
};
class List//클래스 list
{
private:
	Node *head;//첫번째 요소를 가리키는 포인터 변수
	int length;
public:
	List()//생성자
	{
		head = NULL;//head초기화
		length = 0;//길이 초기화
	}
	~List(){}//소멸자
	bool isEmpty()//공백상태 확인
	{
		if(head == NULL)//head가 가리키는 것이 없으면
			return true;//true 출력
		else//아니면
			return false;//false 출력
	}
	void insert(string Str)//요소 삽입 함수(sorted list로 구현)
	{
		Node* location;//위치 노드를 가리키는 포인터 변수
	    Node* predLoc;//이전 노드를 가리키는 포인터 변수
	    Node* newNode;//새로운 노드
	    location = head;//시작 위치는 첫번째 노드 head
	    predLoc = NULL;//이전 노드의 시작은 비어있다.
	    while(location != NULL)//리스트의 마지막이 아니면
	    {
	    	if (Str>location->info)//데이터 필드 값이 입력값보다 작으면 다음 노드로
	        {
	    		predLoc = location;// 이전 노드는 location로 변경
	            location = location->next;//현제 노드를 다음 노드로 변경
	         }
	         else//데이터 필드 값이 입력값 보다 작지 않다
	            break;//반복문 탈출
	    }
	    newNode = new Node;//노드 동적 할당 하여 newNode변수에 대입
	    newNode->info = Str;//입력값을 데이터 필드에 대입
	    if (predLoc == NULL)//list가 비어 있으면
	    {
	    	newNode->next = head;//newNode가 head가 가리키는 노드를 가리킴
	        head = newNode;//head가 newNode를 가리킴
	    }
	    else
	    {
	    	newNode->next = location;//새로운 노드의 next가 다음 요소(location)를 가리킴
	        predLoc->next = newNode;//이전요소가 가리키는 노드가 새로운 노드를 가리킴
	     }
	     length++;//길이증가
	}
	void remove(string Str)//요소 제거 함수
	{
		Node*  location = head ;//위치를 가리키는 변수 location 초기값은 처음값 head
		Node*  tempLoc;//임시노드 포인터 변수
	     if (Str == head->info)//제거할 값이 처음 값이면
	     {
	    	 tempLoc = location;//location 변수를 temp에 대입
	    	 head = head->next;//head의 다음값을 head가 가리킴
	     }
	     else//제거할 값이 처음 값이 아니면
	     {
	        while( Str != location->next->info)//위치의 다음값의 데이터 필드 값이 입력값과 다르면 반복
	            location = location->next;//location이 다음 노드를 가리킴
	        tempLoc = location->next;//temp에 위치가 가리키는 값 대입
	        location->next = location->next->next;//위치가 가리키는 다음 노드에 현재 위치의 next로 변경
	     }
	     delete tempLoc;//동적 할당 반납
	     length--;//길이 감소
	}

	int size() const//리스트의 크기확인 함수
	{
		cout<<length<<endl;//길이 출력

		return 0;
	}
	void print()//출력하는 함수
	{
		Node *location;//위치 노드
		location = head;//처음 위치는 head
		for(int i=1; i <= length ; i++)//모든 리스트만큼 반복
		{
			cout<<location->info<<" ";//데이터 필드값 출력
			location = location->next;//다음 노드로 이동
		}
		cout<<endl;//줄바꿈 출력
	}
};

int main()
{
	List L;//list L선언
	string command;//문자열 명령어 선언
	string st_id;//문자열  학번 선언
	while(1)//무한 반복
	{
		cin>>command;//명령어 입력
		if(command == "N")//N명령 학번이 id인 학생이 수강신청을 함
		{
			cin>>st_id;//학번 입력
			L.insert(st_id);//학생 삽입
		}
		else if(command == "C")//C명령 학번이 id인 학생이 수강신청을 취소함
		{
			cin>>st_id;//학번 입력
			L.remove(st_id);//학생 제거
		}
		else if(command =="P")//P명령  수강 학생들을 학번순서(오름차순)대로 출력
		{
			L.print();//학생들 출력
		}
		else if(command =="S")//S명령 수강 학생수를 출력
		{
			L.size();//학생수
		}
		else if(command == "Q")//Q명령 끝내기
		{
			break;//프로그램 종료
		}
	}

	return 0;
}
