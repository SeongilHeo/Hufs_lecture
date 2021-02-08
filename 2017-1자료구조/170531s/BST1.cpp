/*
 * BST1.cpp
 *
 *  Created on: 2017. 5. 31.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

typedef int ItemType;

struct TreeNode//구조체 노드
{
	ItemType info;//노드의 데이터 필드
	TreeNode *leftChild;
	TreeNode *rightChild;//다음 노드를 가리키는 포인터 변수
};
class BSTree
{
public:
	BSTree();
	~BSTree();
	void insert(ItemType);
	void remove(ItemType);
	void printAll();
	int getHeight();
private:
	TreeNode* root;
	int size;
};
BSTree::BSTree()
{
	root=NULL;
	size=0;
}
void InsertItem(TreeNode*& tree, ItemType data )
{
	if(tree== NULL)
	{
		tree = new TreeNode;
		tree->leftChild = NULL;
		tree->rightChild = NULL;
		tree->info = data;
	}
	else if(data < tree->info)
		InsertItem(tree->leftChild, data);
	else
		InsertItem(tree->rightChild,data);
}
void BSTree::insert(ItemType data)
{
	InsertItem(root,data);
}
void BSTree::printAll()
{
	print(root);
}
void print(TreeNode*& tree)
{
	if(tree != NULL)
	{
		print(tree->leftChild);
		cout<<tree->info;
		print(tree->rightChild);
	}
}
/*void BSTree::remove(ItemType data)
{
	remove(root, data);
}
void remove(TreeNode*& tree, ItemType data)
{
	if(tree->info > data)
		remove(tree->leftChild, data);
	else if(tree ->info < data)
		remove(tree->rightChild, data);
	else
	{

	}

}*/
int BSTree::getHeight()
{
	return height(root);
}
int height(TreeNode* tree)
{
	int HL=0,HR=0;
	if(tree==NULL)
		return 0;
	else
	{
		int height(tree->leftChild);
		int height(tree->rightChild);
	}
	return HL>HR ? HL+1 : HR+1;
}

/*void BSTree::RemoveItem(TreeNode*& tree, ItemType id)
{
	if(id< tree->info)
		RemoveItem(tree->leftChild, id);
	else if(id>tree->info)
		RemoveItem(tree->rightChild,id);
	else
	{
		TreeNode* tempPtr;
		if(tree->leftChild==NULL)
		{
			tempPtr=tree;
			tree = tree->rightChild;
			delete tempPtr;
		}
		else if(tree->rightChild==NULL)
		{
			tempPtr=tree;
			tree=tree->leftChild;
			delete tempPtr;
		}
		else
		{
			tempPtr=tree->rightChild;
			while(tempPtr->leftChild !=NULL)
				tempPtr = tempPtr->leftChild;
			tree->info = tempPtr->info;
			RemoveItem(tree->rightChild, tree->info);
		}
	}
}*/
int main()
{
	BSTree B;

	insert()
}
