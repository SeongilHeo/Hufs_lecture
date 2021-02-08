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
	string book_num;//������ȣ
	string book_name;//�����̸�
	int book_charge;//��������
	int book_amount;//��������
};
struct TreeNode//����ü ���
{
	ItemType info;//����� ������ �ʵ�
	TreeNode *leftChild;
	TreeNode *rightChild;//���� ��带 ����Ű�� ������ ����
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
	bool checkinfo(ItemType);//������ Ȯ���ϴ� �Լ�
	void Plusquan(ItemType);//���� ���� ������Ű�� �Լ�
	void Subquan(ItemType);//���� �� ���� ��Ű�� �Լ�
	ItemType getinfo(ItemType);
private:
	TreeNode* root;//root ���
	int count;//��� �� ����
};
BSTree::BSTree()//������
{
	root=NULL;//root�� NULL �ʱ�ȭ
	count=0;//count 0 �ʱ�ȭ
}
BSTree::~BSTree(){}//�Ҹ���
void InsertItem(TreeNode*& tree,ItemType id)//�����Լ�
{
	if(tree== NULL)//�Է� ���� tree�� ��� ������
	{
		tree = new TreeNode;//���ο� ��带 �����Ҵ��ؼ� tree�� ����
		tree->leftChild = NULL;//���� �ڽĳ�带 null�� �ʱ�ȭ
		tree->rightChild = NULL;//������ �ڽ� ��带 null�� �ʱ�ȭ
		tree->info = id;//tree�� ������ ���� �Է¹��� ������ ����
	}
	else if(id.book_num < tree->info.book_num)//tree�� ���� ��ȣ��  �Է� ���� ���� ��ȣ���� ũ��
		InsertItem(tree->leftChild, id);//���� �ڽĳ��� ���
	else//tree�� ���� ��ȣ��  �Է� ���� ���� ��ȣ���� ������
		InsertItem(tree->rightChild,id);//������ �ڽĳ��� ���
}
void BSTree::insert(ItemType id)//�����Լ�
{
	count++;//count����
	InsertItem(root, id);//�����Լ� ȣ��
}
void RemoveItem(TreeNode*& tree, ItemType id)//�����Լ�
{
	if(id.book_num< tree->info.book_num)//tree�� ���� ��ȣ��  �Է� ���� ���� ��ȣ���� ũ��
		RemoveItem(tree->leftChild, id);//���� �ڽĳ��� ���
	else if(id.book_num>tree->info.book_num)//tree�� ���� ��ȣ��  �Է� ���� ���� ��ȣ���� ������
		RemoveItem(tree->rightChild,id);//������ �ڽĳ��� ���
	else//tree�� ���� ��ȣ��  �Է� ���� ���� ��ȣ�� ������
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
void BSTree::remove(ItemType id)//�����Լ�
{
	count--;//count�� ����
	RemoveItem(root,id);//���� �Լ� ȣ��
}
int BSTree::size()const//����� ���� �Լ�
{
	return count;//count�� ��ȯ
}
void inorder(TreeNode*& tree)//���� ��ȯ �Լ�
{
	if(tree!=NULL)//tree�� NULL�� �ƴϸ�
	{
		inorder(tree->leftChild);//���� �ڽ� ��带 ���
		cout<<tree->info.book_num<<" "<<tree->info.book_name<<" "<<tree->info.book_charge<<" "<<tree->info.book_amount<<endl;//������ �� ���
		inorder(tree->rightChild);//������ �ڽ� ��带 ���
	}
}
void BSTree::print()//��� �Լ�
{
	inorder(root);//������ȯ �Լ� ȣ��
}
bool BSTree::checkinfo(ItemType id)
{
	TreeNode *current;//��ġ�� ����Ű�� ���
	bool found =false;//�߰� ���� ����

	if(root==NULL)//root�� null�̸�
		return found;//�ʱ� found false�� ��ȯ
	else//�ƴϸ�
	{
		current=root;//root���� ����
		while(current != NULL && !found)//root�� null�� �ƴϰ� ���� ��ã������ ��� �ݺ�
		{
			if(current->info.book_num==id.book_num)//���� ��ġ�� ���� ��ȣ��  �Է� ���� ���� ��ȣ�� ������
				found=true;//ã�Ҵ�
			else if(current->info.book_num>id.book_num)//�Է¹��� ���� ��ȣ���� ���� ��ġ�� ������ȣ�� �� ũ��
				current = current->leftChild;//���� �ڽ� ���� �̵�
			else
				current = current->rightChild;//������ �ڽ� ���� �̵�
		}
	}
	return found;//found���� ��ȯ
}
void BSTree::Plusquan(ItemType id)//å�� �Ǽ��� �ø��� �Լ�
{
	TreeNode *current;//��ġ�� ����Ű�� ���
	bool found =false;//�߰� ���� ����
	current=root;//root���� ����
	while(current != NULL && !found)//root�� null�� �ƴϰ� ���� ��ã������ ��� �ݺ�
	{
		if(current->info.book_num==id.book_num)//���� ��ġ�� ���� ��ȣ��  �Է� ���� ���� ��ȣ�� ������
			found=true;//ã�Ҵ�
		else if(current->info.book_num>id.book_num)//�Է¹��� ���� ��ȣ���� ���� ��ġ�� ������ȣ�� �� ũ��
			current = current->leftChild;//���� �ڽ� ���� �̵�
		else
			current = current->rightChild;//������ �ڽ� ���� �̵�
	}
	current->info.book_amount=current->info.book_amount+id.book_amount;//���� ��ġ�� å�� �Ǽ��� �Է¹��� �� ��ŭ �÷��� ����
}
void BSTree::Subquan(ItemType id)//å�� �Ǽ��� ���̴� �Լ�
{
	TreeNode *current;//��ġ�� ����Ű�� ���
	bool found =false;//�߰� ���� ����
	current=root;//root���� ����
	while(current != NULL && !found)//root�� null�� �ƴϰ� ���� ��ã������ ��� �ݺ�
	{
		if(current->info.book_num==id.book_num)//���� ��ġ�� ���� ��ȣ��  �Է� ���� ���� ��ȣ�� ������
			found=true;//ã�Ҵ�
		else if(current->info.book_num>id.book_num)//�Է¹��� ���� ��ȣ���� ���� ��ġ�� ������ȣ�� �� ũ��
			current = current->leftChild;//���� �ڽ� ���� �̵�
		else
			current = current->rightChild;//������ �ڽ� ���� �̵�
	}
	current->info.book_amount=current->info.book_amount-id.book_amount;//���� ��ġ�� å�� �Ǽ��� �Է¹��� �� ��ŭ ���� ����
}
ItemType BSTree::getinfo(ItemType id)
{
	TreeNode *current;//��ġ�� ����Ű�� ����Ʈ ���
	bool found =false;//�߰� ���� ����

	current=root;//root���� ����
	while(current != NULL && !found)//root�� null�� �ƴϰ� ���� ��ã������ ��� �ݺ�
	{
		if(current->info.book_num==id.book_num)//���� ��ġ�� ���� ��ȣ��  �Է� ���� ���� ��ȣ�� ������
			found=true;//ã�Ҵ�
		else if(current->info.book_num>id.book_num)//�Է¹��� ���� ��ȣ���� ���� ��ġ�� ������ȣ�� �� ũ��
			current = current->leftChild;//���� �ڽ� ���� �̵�
		else
			current = current->rightChild;//������ �ڽ� ���� �̵�
	}
	return current->info;//ã�� ���� ��ȯ
}
int main ()
{
	BSTree L;//�������� �ִ� åƮ��
	BSTree S;//�Ǹ��� å Ʈ��
	string command;//��ɾ�

	 while (1)//���� �ݺ�
	  {
	     cin >> command;//��ɾ� �Է�
	     if (command == "N") // �űԵ��� �԰�
	     {
	    	 ItemType T;//�Է°� �޾��� book����ü

	        cin>>T.book_num>>T.book_name>>T.book_charge>>T.book_amount;//����ü ���� �Է�
	        if(L.checkinfo(T) == 1)//�Է°��� �̹� ������
	        	cout<<"error: 1"<<endl;//���� 1 ���
	        else//�ƴϸ�
	        	L.insert(T);//L list�� ����
	     }
	     else if (command == "R") // ����� ��Ͽ� �ִ� ���� �԰�
	     {
	    	 ItemType T;//�Է°� �޾��� book����ü

	    	 cin>>T.book_num>>T.book_amount;//����ü ���� �Է�

	    	 if(L.checkinfo(T)==0)//�Է°��� ������
	    		 cout<<"error: 2"<<endl;//���� 2 ���
	    	 else//�ƴϸ�
	    		 L.Plusquan(T);//�Է°��� ��� ���� ����
	     }
	     else if (command == "S") // ����� ��Ͽ� �ִ� ������ �Ǹ���
	     {
	    	 ItemType T,K;//�Է°� �޾��� book����ü, �ӽ� ������ book ����ü

	    	 cin>>T.book_num>>T.book_amount;//����ü ���� �Է�

	    	 int A = T.book_amount;//�Էµ� �Ǹŷ� ������ �ӽ� ����
	    	 if(L.checkinfo(T)==0)//�Է°��� list�� ������
	    		 cout<<"error: 2"<<endl;//���� 2 ���
	    	 else if(L.getinfo(T).book_amount < T.book_amount)//����� �Ǹŷ��� �� ������
	    		 cout<<"error: 3"<<endl;//���� 3 ���
	    	 else
	    	{
	    		 L.Subquan(T);//��� ����
	    		 K = L.getinfo(T);//�Է°��� K�� ����
	    		 K.book_amount= A;//�Ǹŷ��� K�� ������ ����

	    		 if(S.checkinfo(K)==0)//K�� S list�� ������
	    			 S.insert(K);//S list�� K����
	    		 else//�ƴϸ�
	    			 S.Plusquan(K);//���� ����
	     	 }
	     }
		else if (command == "D") // ���� ��� (����� ��Ͽ��� ������ ������)
		{
			ItemType T;//�Է°� �޾��� book����ü

			cin>>T.book_num;//���� ��ȣ �Է�

			if(L.checkinfo(T)==0)//�Է°��� L list�� ������
				cout<<"error: 2"<<endl;//���� 2 ���
			else
				L.remove(T);//L list���� ����
		}
		else if (command == "I") // ������ ��� ���� ��ȸ
		{
			ItemType T;//�Է°� �޾��� book����ü

			cin>>T.book_num;//������ ��ȣ �Է�
			if(L.checkinfo(T)==0)//L list�� �Է� ������ ������
				cout<<"error: 2"<<endl;//���� 2 ���
			else
				cout<<L.getinfo(T).book_num<<" "<<L.getinfo(T).book_name<<" "<<L.getinfo(T).book_charge<<" "<<L.getinfo(T).book_amount<<endl;//������ ���
		}
		else if (command == "P")// ������� ��Ͽ� �ִ� ��� ������ ������(������ȣ, �����̸�, ����, ������)�� ������ȣ ������������ ���
			L.print();
		else if (command == "L")// �Ǹ��� ��� ������ �Ǹ�����(������ȣ, �����̸�, ����, �Ǹż���)�� ������ȣ ������������ ���
			S.print();
	     else if (command == "Q")// ���α׷��� ������
	       break;
	     else
	    	 break;
	  }
	return 0;
}
