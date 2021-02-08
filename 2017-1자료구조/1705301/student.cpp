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

struct TreeNode//����ü ���
{
	ItemType info;//����� ������ �ʵ�
	TreeNode *leftChild;//���� �ڽ� ���
	TreeNode *rightChild;//������ �ڽ� ���
};
class BSTree//����Ʈ�� Ŭ����
{
public:
	BSTree();//������
	~BSTree();//�Ҹ���
	void insert(ItemType);//�����Լ�
	void remove(ItemType);//�����Լ�
	int size()const;//����Ʈ�� ���� ���� �Լ�
	void print();//����Լ�
private:
	TreeNode* root;//root ���
	int count;//��� �� ����
};
void InsertItem(TreeNode*& tree,ItemType id);//�����Լ�
void RemoveItem(TreeNode*& tree, ItemType id);//�����Լ�
void inorder(TreeNode*& tree);//������ȯ �Լ�
BSTree::BSTree()//������
{
	root=NULL;//root�� NULL �ʱ�ȭ
	count=0;//count 0 �ʱ�ȭ
}
BSTree::~BSTree(){}//�Ҹ���
void BSTree::insert(ItemType id)//�����Լ�
{
	count++;//count����
	InsertItem(root, id);//�����Լ� ȣ��
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
		tree = new TreeNode;//���ο� ��带 �����Ҵ��ؼ� tree�� ����
		tree->leftChild = NULL;//���� �ڽĳ�带 null�� �ʱ�ȭ
		tree->rightChild = NULL;//������ �ڽ� ��带 null�� �ʱ�ȭ
		tree->info = id;//tree�� ������ ���� �Է¹��� ������ ����
 }*/
void InsertItem(TreeNode*& tree,ItemType id)//�����Լ�
{
	if(tree== NULL)//�Է� ���� tree�� ��� ������
	{
		tree = new TreeNode;//���ο� ��带 �����Ҵ��ؼ� tree�� ����
		tree->leftChild = NULL;//���� �ڽĳ�带 null�� �ʱ�ȭ
		tree->rightChild = NULL;//������ �ڽ� ��带 null�� �ʱ�ȭ
		tree->info = id;//tree�� ������ ���� �Է¹��� ������ ����
	}
	else if(id < tree->info)//tree�� �����Ͱ�  �Է� ���� �����ͺ��� ũ��
		InsertItem(tree->leftChild, id);//���� �ڽĳ��� ���
	else//tree�� �����Ͱ�  �Է� ���� �����ͺ��� ������
		InsertItem(tree->rightChild,id);//������ �ڽĳ��� ���
}
void BSTree::remove(ItemType id)//�����Լ�
{
	count--;//count�� ����
	RemoveItem(root,id);//���� �Լ� ȣ��
}
void RemoveItem(TreeNode*& tree, ItemType id)//�����Լ�
{
	if(id< tree->info)//tree�� �����Ͱ�  �Է� ���� �����ͺ��� ũ��
		RemoveItem(tree->leftChild, id);//���� �ڽĳ��� ���
	else if(id>tree->info)//tree�� �����Ͱ�  �Է� ���� �����ͺ��� ������
		RemoveItem(tree->rightChild,id);//������ �ڽĳ��� ���
	else//tree�� �����Ͱ�  �Է� ���� �����Ϳ� ������
	{
		TreeNode* tempPtr;//�ӽ� ����Ʈ ��� ����
		if(tree->leftChild==NULL)//���� �ڽ��� ���������
		{
			tempPtr=tree;//�Է¹��� tree��带 �ӽ� ����Ʈ ��忡 ����
			tree = tree->rightChild;//tree���� ������ �ڽ� ���� ����
			delete tempPtr;//�ӽ� ����Ʈ ��� ����
		}
		else if(tree->rightChild==NULL)//���� �ڽ��� ������� �ʰ� ������ �ڽ��� ���������
		{
			tempPtr=tree;//�ӽ� ��忡 tree����
			tree=tree->leftChild;//tree���� ���� �ڽĳ��� ����
			delete tempPtr;//�ӽ� ��� ����
		}
		else//���� �ڽĳ��� ������ �ڽĳ�� �Ѵ� ���� �� ���
		{
			tempPtr=tree->rightChild;//�ӽ� ��忡 tree������ �ڽ��� ����
			while(tempPtr->leftChild !=NULL)//�ӽ� ����� ���� �ڽĳ�尡 null�϶� ����
				tempPtr = tempPtr->leftChild;//�ӽó�带 ���� �ڽ� ���� �̵�
			tree->info = tempPtr->info;//�ӽ� ����� ������ ���� Ʈ���� ������ ���� ����
			RemoveItem(tree->rightChild, tree->info);//tree�� ������ �ڽĳ�� ����
		}
	}
}
int BSTree::size()const//����� ���� �Լ�
{
	return count;//count�� ��ȯ
}
void BSTree::print()//��� �Լ�
{
	inorder(root);//������ȯ �Լ� ȣ��
}
void inorder(TreeNode*& tree)//���� ��ȯ �Լ�
{
	if(tree!=NULL)//tree�� NULL�� �ƴϸ�
	{
		inorder(tree->leftChild);//���� �ڽ� ��带 ���
		cout<<tree->info<<" ";//���
		inorder(tree->rightChild);//������ �ڽ� ��带 ���
	}
}

int main ()
{
	BSTree L;//������ ����Ʈ��
	ItemType command;//��ɾ�
	ItemType st_id;//�л� ��ȣ
	while(1)
	{
		cin>>command;//��ɾ� �Է�
		if(command == "N")//N�̸� �й��� id�� �л��� ������û�� ��
		{
			cin >> st_id;//id�Է�
			L.insert(st_id);//�Է¹��� id�� �Է��Լ� ȣ���Ͽ� �Է�
		}
		else if(command=="C")//�й��� id�� �л��� ������û�� �����
		{
			cin>>st_id;//id �Է¹���
			L.remove(st_id);//�Է¹��� id�� �����Լ� ȣ�� �Ͽ� ����
		}
		else if(command=="S")// ���� �л����� ���
			cout<<L.size()<<endl;//size�Լ� ȣ���� ���
		else if(command=="P")// ���� �л����� �й�����(��������)��� ���
		{
			L.print();//����Լ� ȣ��
			cout<<endl;//�ٹٲ�
		}
		else if(command=="Q")// ������
			break;
	}
	return 0;
}
