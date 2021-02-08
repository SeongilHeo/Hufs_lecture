/*
 * BOOK.cpp
 *
 *  Created on: 2017. 5. 30.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;

typedef struct Book ItemType;

struct Book
{
	string book_num;//도서번호
	string book_name;//도서이름
	int book_charge;//도서가격
	int book_amount;//도서수량
};
struct TreeNode//구조체 노드
{
	ItemType info;//노드의 데이터 필드
	TreeNode *leftChild;
	TreeNode *rightChild;//다음 노드를 가리키는 포인터 변수
};
class BSTree//이진트르 클래스
{
public:
	BSTree();//생성자
	~BSTree();//소멸자
	void insert(ItemType);//삽입함수
	void remove(ItemType);//제거함수
	int size()const;//이진트르 노드수 갯수 함수
	void print();//출력함수
	bool checkinfo(ItemType);//유무를 확인하는 함수
	void Plusquan(ItemType);//도서 양을 증가시키는 함수
	void Subquan(ItemType);//도서 양 감소 시키는 함수
	ItemType getinfo(ItemType);
private:
	TreeNode* root;//root 노드
	int count;//노드 수 변수
};
BSTree::BSTree()//생성자
{
	root=NULL;//root값 NULL 초기화
	count=0;//count 0 초기화
}
BSTree::~BSTree(){}//소멸자
void InsertItem(TreeNode*& tree,ItemType id)//삽입함수
{
	if(tree== NULL)//입력 받은 tree가 비어 있으면
	{
		tree = new TreeNode;//새로운 노드를 동적할당해서 tree에 저장
		tree->leftChild = NULL;//왼쪽 자식노드를 null로 초기화
		tree->rightChild = NULL;//오른쪽 자식 노드를 null로 초기화
		tree->info = id;//tree의 데이터 값에 입력받은 데이터 저장
	}
	else if(id.book_num < tree->info.book_num)//tree의 도서 번호가  입력 받은 도서 번호보다 크면
		InsertItem(tree->leftChild, id);//왼쪽 자식노드로 재귀
	else//tree의 도서 번호가  입력 받은 도서 번호보다 작으면
		InsertItem(tree->rightChild,id);//오른쪽 자식노드로 재귀
}
void BSTree::insert(ItemType id)//삽입함수
{
	count++;//count증가
	InsertItem(root, id);//삽입함수 호출
}
void RemoveItem(TreeNode*& tree, ItemType id)//제거함수
{
	if(id.book_num< tree->info.book_num)//tree의 도서 번호가  입력 받은 도서 번호보다 크면
		RemoveItem(tree->leftChild, id);//왼쪽 자식노드로 재귀
	else if(id.book_num>tree->info.book_num)//tree의 도서 번호가  입력 받은 도서 번호보다 작으면
		RemoveItem(tree->rightChild,id);//오른쪽 자식노드로 재귀
	else//tree의 도서 번호가  입력 받은 도서 번호와 같으면
	{
		TreeNode* tempPtr;//임시 포인트 노드 생성
		if(tree->leftChild==NULL)//왼쪽 자식이 비어있으면
		{
			tempPtr=tree;//입력받은 tree노드를 임시 포인트 노드에 저장
			tree = tree->rightChild;//tree값을 오른쪽 자식 노드로 변경
			delete tempPtr;//임시 포인트 노드 삭제
		}
		else if(tree->rightChild==NULL)//왼쪽 자식이 비어있지 않고 오른쪽 자식이 비어있으면
		{
			tempPtr=tree;//임시 노드에 tree저장
			tree=tree->leftChild;//tree값을 왼쪽 자식노드로 변경
			delete tempPtr;//임시 노드 삭제
		}
		else//왼쪽 자식노드와 오른쪽 자식노드 둘다 존재 할 경우
		{
			tempPtr=tree->rightChild;//임시 노드에 tree오른쪽 자식을 저장
			while(tempPtr->leftChild !=NULL)//임시 노드의 왼쪽 자식노드가 null일때 까지
				tempPtr = tempPtr->leftChild;//임시노드를 왼쪽 자식 노드로 이동
			tree->info = tempPtr->info;//임시 노드의 데이터 값을 트리의 데이터 값에 저장
			RemoveItem(tree->rightChild, tree->info);//tree의 오른쪽 자식노드 제거
		}
	}
}
void BSTree::remove(ItemType id)//제거함수
{
	count--;//count값 감소
	RemoveItem(root,id);//제거 함수 호출
}
int BSTree::size()const//노드의 개수 함수
{
	return count;//count값 반환
}
void inorder(TreeNode*& tree)//중위 순환 함수
{
	if(tree!=NULL)//tree가 NULL이 아니면
	{
		inorder(tree->leftChild);//왼쪽 자식 노드를 재귀
		cout<<tree->info.book_num<<" "<<tree->info.book_name<<" "<<tree->info.book_charge<<" "<<tree->info.book_amount<<endl;//데이터 값 출력
		inorder(tree->rightChild);//오른쪽 자식 노드를 재귀
	}
}
void BSTree::print()//출력 함수
{
	inorder(root);//중위순환 함수 호출
}
bool BSTree::checkinfo(ItemType id)
{
	TreeNode *current;//위치를 가리키는 노드
	bool found =false;//발견 유무 변수

	if(root==NULL)//root가 null이면
		return found;//초기 found false를 반환
	else//아니면
	{
		current=root;//root부터 시작
		while(current != NULL && !found)//root가 null이 아니고 아직 못찾았으면 계속 반복
		{
			if(current->info.book_num==id.book_num)//현재 위치의 도서 번호와  입력 받은 도서 번호가 같으면
				found=true;//찾았다
			else if(current->info.book_num>id.book_num)//입력받은 도서 번호보다 현재 위치의 도서번호가 더 크면
				current = current->leftChild;//왼쪽 자식 노드로 이동
			else
				current = current->rightChild;//오른쪽 자식 노드로 이동
		}
	}
	return found;//found값을 반환
}
void BSTree::Plusquan(ItemType id)//책의 권수를 늘리는 함수
{
	TreeNode *current;//위치를 가리키는 노드
	bool found =false;//발견 유무 변수
	current=root;//root부터 시작
	while(current != NULL && !found)//root가 null이 아니고 아직 못찾았으면 계속 반복
	{
		if(current->info.book_num==id.book_num)//현재 위치의 도서 번호와  입력 받은 도서 번호가 같으면
			found=true;//찾았다
		else if(current->info.book_num>id.book_num)//입력받은 도서 번호보다 현재 위치의 도서번호가 더 크면
			current = current->leftChild;//왼쪽 자식 노드로 이동
		else
			current = current->rightChild;//오른쪽 자식 노드로 이동
	}
	current->info.book_amount=current->info.book_amount+id.book_amount;//현재 위치의 책의 권수를 입력받은 수 만큼 늘려서 저장
}
void BSTree::Subquan(ItemType id)//책의 권수를 줄이는 함수
{
	TreeNode *current;//위치를 가리키는 노드
	bool found =false;//발견 유무 변수
	current=root;//root부터 시작
	while(current != NULL && !found)//root가 null이 아니고 아직 못찾았으면 계속 반복
	{
		if(current->info.book_num==id.book_num)//현재 위치의 도서 번호와  입력 받은 도서 번호가 같으면
			found=true;//찾았다
		else if(current->info.book_num>id.book_num)//입력받은 도서 번호보다 현재 위치의 도서번호가 더 크면
			current = current->leftChild;//왼쪽 자식 노드로 이동
		else
			current = current->rightChild;//오른쪽 자식 노드로 이동
	}
	current->info.book_amount=current->info.book_amount-id.book_amount;//현재 위치의 책의 권수를 입력받은 수 만큼 빼서 저장
}
ItemType BSTree::getinfo(ItemType id)
{
	TreeNode *current;//위치를 가리키는 포인트 노드
	bool found =false;//발견 유무 변수

	current=root;//root부터 시작
	while(current != NULL && !found)//root가 null이 아니고 아직 못찾았으면 계속 반복
	{
		if(current->info.book_num==id.book_num)//현재 위치의 도서 번호와  입력 받은 도서 번호가 같으면
			found=true;//찾았다
		else if(current->info.book_num>id.book_num)//입력받은 도서 번호보다 현재 위치의 도서번호가 더 크면
			current = current->leftChild;//왼쪽 자식 노드로 이동
		else
			current = current->rightChild;//오른쪽 자식 노드로 이동
	}
	return current->info;//찾은 값을 반환
}
int main ()
{
	BSTree L;//도서관에 있는 책트리
	BSTree S;//판매한 책 트리
	string command;//명령어

	 while (1)//무한 반복
	  {
	     cin >> command;//명령어 입력
	     if (command == "N") // 신규도서 입고
	     {
	    	 ItemType T;//입력값 받아줄 book구조체

	        cin>>T.book_num>>T.book_name>>T.book_charge>>T.book_amount;//구조체 정보 입력
	        if(L.checkinfo(T) == 1)//입력값이 이미 있으면
	        	cout<<"error: 1"<<endl;//에러 1 출력
	        else//아니면
	        	L.insert(T);//L list에 대입
	     }
	     else if (command == "R") // 재고도서 목록에 있는 도서 입고
	     {
	    	 ItemType T;//입력값 받아줄 book구조체

	    	 cin>>T.book_num>>T.book_amount;//구조체 정보 입력

	    	 if(L.checkinfo(T)==0)//입력값이 없으면
	    		 cout<<"error: 2"<<endl;//에러 2 출력
	    	 else//아니면
	    		 L.Plusquan(T);//입력값의 재고 수량 증가
	     }
	     else if (command == "S") // 재고도서 목록에 있는 도서를 판매함
	     {
	    	 ItemType T,K;//입력값 받아줄 book구조체, 임시 저장할 book 구조체

	    	 cin>>T.book_num>>T.book_amount;//구조체 정보 입력

	    	 int A = T.book_amount;//입력된 판매량 변수에 임시 저장
	    	 if(L.checkinfo(T)==0)//입력값이 list에 없으면
	    		 cout<<"error: 2"<<endl;//에러 2 출력
	    	 else if(L.getinfo(T).book_amount < T.book_amount)//재고보다 판매량이 더 많으면
	    		 cout<<"error: 3"<<endl;//에러 3 출력
	    	 else
	    	{
	    		 L.Subquan(T);//재고량 감소
	    		 K = L.getinfo(T);//입력값을 K에 대입
	    		 K.book_amount= A;//판매량을 K의 수량에 대입

	    		 if(S.checkinfo(K)==0)//K가 S list에 없으면
	    			 S.insert(K);//S list에 K삽입
	    		 else//아니면
	    			 S.Plusquan(K);//수량 증가
	     	 }
	     }
		else if (command == "D") // 도서 폐기 (재고도서 목록에서 완전히 삭제함)
		{
			ItemType T;//입력값 받아줄 book구조체

			cin>>T.book_num;//도서 번호 입력

			if(L.checkinfo(T)==0)//입력값이 L list에 없으면
				cout<<"error: 2"<<endl;//에러 2 출력
			else
				L.remove(T);//L list에서 제거
		}
		else if (command == "I") // 도서의 재고 상태 조회
		{
			ItemType T;//입력값 받아줄 book구조체

			cin>>T.book_num;//도서의 번호 입력
			if(L.checkinfo(T)==0)//L list에 입력 도서가 없으면
				cout<<"error: 2"<<endl;//에러 2 출력
			else
				cout<<L.getinfo(T).book_num<<" "<<L.getinfo(T).book_name<<" "<<L.getinfo(T).book_charge<<" "<<L.getinfo(T).book_amount<<endl;//재고상태 출력
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
