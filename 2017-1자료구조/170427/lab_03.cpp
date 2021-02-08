/*
 * lab_03.cpp
 *
 *  Created on: 2017. 4. 27.
 *      Author: tjddl
 */
#include <iostream>
#include <string>
using namespace std;

typedef struct Book ItemType; //list의 info에 구조체 사용

struct Book// book 구조체 선언
{
	string Book_num;//문자열 도서 번호
	string Book_id;//문자열 도서 이름
	int Book_cost;//도서 가격
	int Book_quan;//도서 재고
};

struct Node//구조체 노드
{
	ItemType info;//노드의 데이터필드
	Node *next;//다음 노드를 가리키는 포인터 변수
};
class List//클래스 list
{
private:
	Node *head;//첫번째 요소를 가리키는 포인터 변수
	int length;//list의 길이
public:
	List()//생성자
	{
		head = NULL;//head초기화
		length = 0;//길이 초기화
	}
	~List(){}//소멸자
	bool isEmpty()//공백상택 확인
	{
		if(head == NULL)//head가 가리키는 것이 없으면
			return true;//true 출력
		else//아니면
			return false;//false 출력
	}
	void insert(ItemType B)//list에 요소 삽입 (sorted list로 구현)
	{
		Node* location;//위치 노드를 가리키는 포인터 변수
	    Node* predLoc;//이전 노드를 가리키는 포인터 변수
	    Node* newNode;//새로운 노드
	    location = head;//시작 위치는 첫번째 노드 head
	    predLoc = NULL;//이전 노드의 시작은 비어있다.
	    while(location != NULL)// list의 마지막 요소 까지
	    {
	    	if (B.Book_num > location->info.Book_num)//새 요소를 list에 있는 요소들과 크기 비교 삽입 위치 찾기
	        {
	    		predLoc = location;// 이전 노드는 location로 변경
	            location = location->next;//현제 노드를 다음 노드로 변경
	        }
	         else//데이터 필드 값이 입력값 보다 작지 않다
	            break;//반복문 탈출
	    }
	    newNode = new Node;//노드 동적 활동 하여 newNode변수에 대입
	    newNode->info = B;//입력값을 데이터 필드에 대입
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
	void remove(ItemType B)//요소 제거 함수
	{
		Node*  location = head ;//위치를 가리키는 변수 location 초기값은 처음값 head
		Node*  tempLoc;//임시노드 포인터 변수
	     if (B.Book_num == head->info.Book_num)//제거할 값이 처음 값이면
	     {
	    	 tempLoc = location;//location 변수를 temp에 대입
	    	 head = head->next;//head의 다음값을 head가 가리킴
	     }
	     else//제거할 값이 처음 값이 아니면
	     {
	        while( B.Book_num != location->next->info.Book_num)//위치의 다음값의 데이터 필드 값이 입력값과 다르면 반복
	            location = location->next;//location이 다음 노드를 가리킴
	        tempLoc = location->next;//temp에 위치가 가리키는 값 대입
	        location->next = location->next->next;//위치가 가리키는 다음 노드에 현재 위치의 next로 변경
	     }
	     delete tempLoc;//동적 할당 삭제
	     length--;//길이 감소
	}
	ItemType getinfo(ItemType B)//데이터 필드값 가져오기
	{
		Node*  location ;//위치를 가리키는 포인터 변수
	    location = head ;//location의 초기값은 head(처음값)
		bool found = false ;//유무를 확인하는 부울 변수 초기값 없다 (false)
		while (location  !=  NULL &&  !found )//list의 마지막이 아니고 찾지 못했으면 반복
		{
	           if (location->info.Book_num <  B.Book_num)    //위치의 데이터 필드 값이 입력값 보다 작다
	                  location = location->next;//다음 위치로 이동
		     else if (B.Book_num == location->info.Book_num) // 값은 값인 데이터 필드 값 발견했을 때
		     {
		    	 found = true;//유무상태가 유
		    	 B = location->info;//위치의 데이터 필드 값을 b노드에 대입
		     }
		     else
		    	 break;
		}
		return B;//찾은값 반환
	}
	bool checkinfo(ItemType B)//데이터 유무 확인함수
	{
		Node*  location ;//위치를 가리키는 포인터 변수
	    location = head ;//location 초기값 head
		bool found = false ;//유무를 확인하는 부울 변수 초기값 없다 (false)
		while (location  !=  NULL &&  !found )//list의 마지막이 아니고 찾지 못했으면 반복
		{
	         if (location->info.Book_num <  B.Book_num)       //위치의 데이터 필드 값이 입력값 보다 작다
	           location = location->next;//다음 위치로 이동
		     else if (B.Book_num== location->info.Book_num)// 값은 값인 데이터 필드 값 발견했을 때
		     {
		    	 found = true;//유무상태가 유
		    	 B = location->info;//위치의 데이터 필드 값을 b노드에 대입
		     }
		     else
		    	 break;
		}
		return found;//유무 상태 반환
	}
	void Plusquan(ItemType B)//재고를 증가시키는 함수
	{
		Node*  location ;//데이터 유무 확인함수
	    location = head ;//location 초기값 head
	    bool found = false;//유무를 확인하는 부울 변수 초기값 없다 (false)
		while (location  !=  NULL &&  !found )//list의 마지막이 아니고 찾지 못했으면 반복
		{
			if (location->info.Book_num <  B.Book_num) //위치의 데이터 필드 값이 입력값 보다 작다
			location = location->next;//다음 위치로 이동
			else if (B.Book_num== location->info.Book_num)// 값은 값인 데이터 필드 값 발견했을 때
			{
				found = true;//유무상태가 유
				location->info.Book_quan = location->info.Book_quan + B.Book_quan;//입력된 수량 만큼 재고량 증가
			}
			else
				break;
		}
	}
	void Subquan(ItemType B)//재고를 감소시키는 함수
		{
			Node*  location ;//데이터 유무 확인함수
		    location = head ;//location 초기값 head
		    bool found = false;//유무를 확인하는 부울 변수 초기값 없다 (false)
			while (location  !=  NULL &&  !found )//list의 마지막이 아니고 찾지 못했으면 반복
			{
				if (location->info.Book_num <  B.Book_num)//위치의 데이터 필드 값이 입력값 보다 작다
				location = location->next;//다음 위치로 이동
				else if (B.Book_num== location->info.Book_num) // 값은 값인 데이터 필드 값 발견했을 때
				{
					found = true;//유무상태가 유
					location->info.Book_quan = location->info.Book_quan - B.Book_quan;//입력된 수량 만큼 재고량 감소
				}
				else
					break;
			}
		}
	void print()//출력하는 함수
	{
		Node *location;//위치 노드
		location = head;//처음 위치는 head
		for(int i=1; i <= length ; i++)//모든 리스트만큼 반복
		{
			cout<<location->info.Book_num<<" "<<location->info.Book_id<<" "<<location->info.Book_cost<<" "<<location->info.Book_quan<<endl;//데이터 필드값 출력
			location = location->next;//다음 노드로 이동
		}
	}
};

int main()
{
  List L;//list L선언
  List S;//list S선언
  string command;  //문자열 명령어 선언

  while (1)//무한 반복
  {
     cin >> command;//명령어 입력
     if (command == "N") // 신규도서 입고
     {
    	ItemType T;//입력값 받아줄 book구조체

        cin>>T.Book_num>>T.Book_id>>T.Book_cost>>T.Book_quan;//구조체 정보 입력
        if(L.checkinfo(T) == 1)//입력값이 이미 있으면
        	cout<<"error: 1"<<endl;//에러 1 출력
        else//아니면
        	L.insert(T);//L list에 대입
     }
     else if (command == "R") // 재고도서 목록에 있는 도서 입고
     {
    	 ItemType T;//입력값 받아줄 book구조체

    	 cin>>T.Book_num>>T.Book_quan;//구조체 정보 입력

    	 if(L.checkinfo(T)==0)//입력값이 없으면
    		 cout<<"error: 2"<<endl;//에러 2 출력
    	 else//아니면
    		 L.Plusquan(T);//입력값의 재고 수량 증가
     }
     else if (command == "S") // 재고도서 목록에 있는 도서를 판매함
     {
    	 ItemType T,K;//입력값 받아줄 book구조체, 임시 저장할 book 구조체

    	 cin>>T.Book_num>>T.Book_quan;//구조체 정보 입력

    	 int A = T.Book_quan;//입력된 판매량 변수에 임시 저장
    	 if(L.checkinfo(T)==0)//입력값이 list에 없으면
    		 cout<<"error: 2"<<endl;//에러 2 출력
    	 else if(L.getinfo(T).Book_quan < T.Book_quan)//재고보다 판매량이 더 많으면
    		 cout<<"error: 3"<<endl;//에러 3 출력
    	 else
    	{
    		 L.Subquan(T);//재고량 감소
    		 K = L.getinfo(T);//입력값을 K에 대입
    		 K.Book_quan= A;//판매량을 K의 수량에 대입

    		 if(S.checkinfo(K)==0)//K가 S list에 없으면
    			 S.insert(K);//S list에 K삽입
    		 else//아니면
    			 S.Plusquan(K);//수량 증가
     	 }
     }
	else if (command == "D") // 도서 폐기 (재고도서 목록에서 완전히 삭제함)
	{
		ItemType T;//입력값 받아줄 book구조체

		cin>>T.Book_num;//도서 번호 입력

		if(L.checkinfo(T)==0)//입력값이 L list에 없으면
			cout<<"error: 2"<<endl;//에러 2 출력
		else
			L.remove(T);//L list에서 제거
	}
	else if (command == "I") // 도서의 재고 상태 조회
	{
		ItemType T;//입력값 받아줄 book구조체

		cin>>T.Book_num;//도서의 번호 입력
		if(L.checkinfo(T)==0)//L list에 입력 도서가 없으면
			cout<<"error: 2"<<endl;//에러 2 출력
		else
			cout<<L.getinfo(T).Book_num<<" "<<L.getinfo(T).Book_id<<" "<<L.getinfo(T).Book_cost<<" "<<L.getinfo(T).Book_quan<<endl;//재고상태 출력
	}
	else if (command == "P")// 도서재고 목록에 있는 모든 도서의 재고상태(도서번호, 도서이름, 가격, 재고수량)를 도서번호 오름차순으로 출력
		L.print();
	else if (command == "L")// 판매한 모든 도서의 판매정보(도서번호, 도서이름, 가격, 판매수량)를 도서번호 오름차순으로 출력
		S.print();
     else if (command == "Q")// 프로그램을 종료함
       break;
     else
    	 break;
  }

  return 0;
}
