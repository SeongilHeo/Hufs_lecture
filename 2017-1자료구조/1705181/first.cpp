/*
 * first.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

typedef int ItemType;//아이템타이프를 int형으로 정의

struct Node//node구조체 선언
{
	ItemType info;//노드의 info값
	Node* next;//노드의 next값 선언
};

class CircularLinkedList//원형연결리스트
{
public:
	CircularLinkedList()//생성자함수
	{
		tail=NULL;// tail값 초기화
	}
	~CircularLinkedList(){}//소멸자
	void insertLast(int data)//데이터삽입함수
	{
		Node* newNode = new Node;//newNode동적 할당

		newNode->info = data;//입력값을 info값에 대입

		if(tail == NULL)//처음 값 입력일때
		{
			tail = newNode;//newNode를 tail이 가리킴
			tail->next = tail;//tail을 자신에게 연결
		}
		else//처음이 아닐때
		{
			newNode->next = tail->next;//newNode를 처음값에 연결
			tail ->next =newNode;//원래의 tail이 newNode를 가리킴
			tail = newNode;//newNode가 tail이 됨
		}
	}
	void printNode()//모든 node출력
	{
		Node* location=tail->next;//위치나타내는 포인트 노드를 처음값으로 초기화
		while(location != tail)//처음부터 tail까지 반복
		{
			cout<<location->info<<endl;//location의 data값 출력
			location = location->next;//location을 다음으로 넘김
		}
	}
	void remove(int s, int j, int k)//요소 제거 함수로 입력받은 s,j,k를 매개변수로함
	{

		Node*  tempLoc;//임시노드 포인터 변수
		Node*  location=tail->next;//위치를 가리키는 변수 location 초기값은 처음 값

		for(int p=0 ; p < s-1; p++)//시작접을 나타내기 위해 location이동
		{
			location= location ->next;//location이동
		}
		for(int q=0 ; q< k; q++)//출력할 갯수만큼 반복
		{
			for(int i=1; i < j-1; i++)//j-1번째 만큼 이동
			{	location = location->next;	}
			tempLoc=location -> next;//제거할 node를 temp에 저장
			location -> next= location -> next ->next;//제거할node 전 node가 제거할 node 다음 node를 가리킴
			location=location->next;//시작node를 제거할 다음 node로 변경

			cout<< tempLoc->info<<" ";//제거할 node출력
		    delete tempLoc;//동적 할당 삭제

		}

	}

private:
	Node* tail;//member변수tail값 선언
};
int main ()
{
	CircularLinkedList A = CircularLinkedList();//원형연결리스트a 선언 후 초기화
	int n, s, j, k;//입력 받을 4개 문자 선언
	cin>>n>>s>>j>>k;//숫자 4개 입력

	for (int i=1; i<=n ; i++)//n개 만큼 입력
	{
		A.insertLast(i);//insert함수 호출
	}


	A.remove(s,j,k);//remove함수 호출


	return 0;//프로그램 종료

}

