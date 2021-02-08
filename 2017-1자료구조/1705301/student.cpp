/*
 * book.cpp
 *
 *  Created on: 2017. 5. 30.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;

typedef string ItemType;

struct TreeNode//구조체 노드
{
	ItemType info;//노드의 데이터 필드
	TreeNode *leftChild;//왼쪽 자식 노드
	TreeNode *rightChild;//오른쪽 자식 노드
};
class BSTree//이진트리 클래스
{
public:
	BSTree();//생성자
	~BSTree();//소멸자
	void insert(ItemType);//삽입함수
	void remove(ItemType);//제거함수
	int size()const;//이진트르 노드수 갯수 함수
	void print();//출력함수
private:
	TreeNode* root;//root 노드
	int count;//노드 수 변수
};
void InsertItem(TreeNode*& tree,ItemType id);//삽입함수
void RemoveItem(TreeNode*& tree, ItemType id);//제거함수
void inorder(TreeNode*& tree);//중위순환 함수
BSTree::BSTree()//생성자
{
	root=NULL;//root값 NULL 초기화
	count=0;//count 0 초기화
}
BSTree::~BSTree(){}//소멸자
void BSTree::insert(ItemType id)//삽입함수
{
	count++;//count증가
	InsertItem(root, id);//삽입함수 호출
}
 /*void InsertItem(TreeNode*& tree, ItemType id)
 {
	 while(tree!=NULL)
	 {
		 if(id < tree-> info)
			 tree=tree->leftChild;
		 else if(id > tree->info)
			 tree=tree->rightChild;
	 }
		tree = new TreeNode;//새로운 노드를 동적할당해서 tree에 저장
		tree->leftChild = NULL;//왼쪽 자식노드를 null로 초기화
		tree->rightChild = NULL;//오른쪽 자식 노드를 null로 초기화
		tree->info = id;//tree의 데이터 값에 입력받은 데이터 저장
 }*/
void InsertItem(TreeNode*& tree,ItemType id)//삽입함수
{
	if(tree== NULL)//입력 받은 tree가 비어 있으면
	{
		tree = new TreeNode;//새로운 노드를 동적할당해서 tree에 저장
		tree->leftChild = NULL;//왼쪽 자식노드를 null로 초기화
		tree->rightChild = NULL;//오른쪽 자식 노드를 null로 초기화
		tree->info = id;//tree의 데이터 값에 입력받은 데이터 저장
	}
	else if(id < tree->info)//tree의 데이터가  입력 받은 데이터보다 크면
		InsertItem(tree->leftChild, id);//왼쪽 자식노드로 재귀
	else//tree의 데이터가  입력 받은 데이터보다 작으면
		InsertItem(tree->rightChild,id);//오른쪽 자식노드로 재귀
}
void BSTree::remove(ItemType id)//제거함수
{
	count--;//count값 감소
	RemoveItem(root,id);//제거 함수 호출
}
void RemoveItem(TreeNode*& tree, ItemType id)//제거함수
{
	if(id< tree->info)//tree의 데이터가  입력 받은 데이터보다 크면
		RemoveItem(tree->leftChild, id);//왼쪽 자식노드로 재귀
	else if(id>tree->info)//tree의 데이터가  입력 받은 데이터보다 작으면
		RemoveItem(tree->rightChild,id);//오른쪽 자식노드로 재귀
	else//tree의 데이터가  입력 받은 데이터와 같으면
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
int BSTree::size()const//노드의 개수 함수
{
	return count;//count값 반환
}
void BSTree::print()//출력 함수
{
	inorder(root);//중위순환 함수 호출
}
void inorder(TreeNode*& tree)//중위 순환 함수
{
	if(tree!=NULL)//tree가 NULL이 아니면
	{
		inorder(tree->leftChild);//왼쪽 자식 노드를 재귀
		cout<<tree->info<<" ";//출력
		inorder(tree->rightChild);//오른쪽 자식 노드를 재귀
	}
}

int main ()
{
	BSTree L;//데이터 이진트리
	ItemType command;//명령어
	ItemType st_id;//학생 번호
	while(1)
	{
		cin>>command;//명령어 입력
		if(command == "N")//N이면 학번이 id인 학생이 수강신청을 함
		{
			cin >> st_id;//id입력
			L.insert(st_id);//입력받은 id를 입력함수 호출하여 입력
		}
		else if(command=="C")//학번이 id인 학생이 수강신청을 취소함
		{
			cin>>st_id;//id 입력받음
			L.remove(st_id);//입력받은 id를 제거함수 호출 하여 제거
		}
		else if(command=="S")// 수강 학생수를 출력
			cout<<L.size()<<endl;//size함수 호출후 출력
		else if(command=="P")// 수강 학생들을 학번순서(오름차순)대로 출력
		{
			L.print();//출력함수 호출
			cout<<endl;//줄바꿈
		}
		else if(command=="Q")// 끝내기
			break;
	}
	return 0;
}
