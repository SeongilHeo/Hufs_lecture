/*
 * MAZE.cpp
 *
 *  Created on: 2017. 5. 29.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

int count=0;//���� ���� count �������� ����
class Point//��Ŀ� ���� Ŭ����
{
public:
	int getRow();//�� ������ �Լ�
	int getCol();//�� ������ �Լ�
	int row;//��
	int col;//��
};
class Maze//�̷� Ŭ����
{
public:
	Maze();//������
	void createMap();//�̷� ����� �Լ�
	void printMap();//�̷� ����ϴ� �Լ�
	void countDestination(Point source);//������ ���� �Լ�
	bool pathExistRecur(Point currentPosition);//���� �մ� ���� Ȯ���ϴ� �Լ�
private:
	int r; //the number of rows
	int c; //the number of cols
	int **map;//�̷κ���
	bool **visited;//�湮���� ���� ����

};

	Maze::Maze()//������
	{
		r=0;//�� �ʱ�ȭ
		c=0;//�� �ʱ�ȭ
		map=0;//
		visited = 0;
	}
	void Maze:: createMap()//�̷� ���� �Լ�
	{
		cin>>r>>c;//�� �� ���� �Է�
		map = new int* [r];//����Ʈ �迭 ���� �Ҵ� �Ͽ� �̷ο� ����
		visited = new bool*[r];//����Ʈ �迭 ���� �Ҵ� �Ͽ� visited�� ����
		for (int i = 0; i < r; i++)//map�� visited�� �� ���� ���� ���� �Ҵ�
		{
			map[i] = new int[c];
			visited[i] = new bool[c];
		}

		for (int row = 0; row < r; row++)//�� ��ŭ �ݺ�
		 {
			for (int col = 0; col < c; col++)//�� ��ŭ �ݺ�
			{
				cin>>map[row][col];//�࿭�� �� �Է�
			}
		}
	}
	void Maze:: printMap()//�̷� ����Լ�
	{
		for (int row = 0; row < r; row++)//�ุŭ �ݺ�
		{
			for (int col = 0; col < c; col++)//����ŭ �ݺ�
			{
				cout<<map[row][col]<<" ";//�࿭ �� ���
			}
			cout<<endl;//�ٹٲ� ���
		}
	}
	void Maze:: countDestination(Point source)//�湮���� �� Ȯ���Լ�
	{
		for (int row = 0; row < r; row++)//�ุŭ �ݺ�
		{
			for (int col = 0; col < c; col++)//����ŭ �ݺ�
			{
				visited[row][col] = false;//�湮����� ��� false�� �ʱ�ȭ
			}
		}
		if(map[source.row][source.col]==0)//�Է¹��� �������� ���� 0 �̸�
		{
			count++;//���� ����
			pathExistRecur(source);//���������� �̵������Ǵ��Լ�ȣ��
			cout<<count;//���� ���
			return;
		}
		else//�������� 1�̾ƴϸ�
		{
			cout<<count;//���� ���
			return;//����
		}
	}
	bool Maze::pathExistRecur(Point currentPosition)//�̵� �����Ǵ� �Լ�
	{
		Point nextPosition;//���� ��ġ ����Ʈ

		visited[currentPosition.row][currentPosition.col] = true;//�Է¹��� ��ġ �湮��� üũ
		if (currentPosition.col+1 <= c-1)//�����ʿ� ������ �ְ�
		{
			if (map[currentPosition.row][currentPosition.col+1]==0 && visited[currentPosition.row][currentPosition.col+1] ==false)//������ ���� 0�̰� �湮�� ���� ������
			{
				count++;//���� ����
				nextPosition.row = currentPosition.row;//������ġ�� ������ġ�� ����
				nextPosition.col = currentPosition.col+1;
				if (pathExistRecur(nextPosition)==1)//������ġ�� ���
				{
					return true;
				}
			}
		}
		if (currentPosition.row-1 >= 0)//���� ������ �ְ�
		{
			if (map[currentPosition.row-1][currentPosition.col]==0 && visited[currentPosition.row-1][currentPosition.col] ==false)//���� ���� 0�̰� �湮������ ������
			{
				count++;//���� ����
				nextPosition.row = currentPosition.row-1;//�̵���Ų ��ġ�� ������ġ�� ����
				nextPosition.col = currentPosition.col;
				if (pathExistRecur(nextPosition)==1)//���� ��ġ�� ���
				{
					return true;
				}
			}
		}
		if(currentPosition.col-1 >= 0)//���� ������ �ְ�
		{
			if (map[currentPosition.row][currentPosition.col-1]==0 && visited[currentPosition.row][currentPosition.col-1] ==false)//���� ���� 0�̰� �湮������ ������
			{
				count++;//���� ����
				nextPosition.row = currentPosition.row;//�̵���Ų ��ġ�� ������ġ�� ����
				nextPosition.col = currentPosition.col-1;
				if (pathExistRecur(nextPosition)==1)//������ġ�� ���
				{
					return true;
				}
			}
		}
		if(currentPosition.row+1 <= r-1)//�Ʒ��� ������ �ְ�
		{
			if (map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col] ==false)//�Ʒ��� ���� 0�̰� �湮������ ���̸�
			{
				count++;//���� ����
				nextPosition.row = currentPosition.row+1;//�̵���Ų ��ġ�� ������ġ�� ����
				nextPosition.col = currentPosition.col;
				if (pathExistRecur(nextPosition)==1)//������ġ�� ���
				{
					return true;
				}
			}
		}
		return false;//������ ������ false��ȯ
	}
int main()
{
	Maze M;//�̷� m ����
	Point source;//������ ����
	M.createMap();//�̷� ����
	cin>>source.row>>source.col;//������ �Է�
	M.countDestination(source);//������ �湮���� �� üũ �Լ�ȣ��

	return 0;
}

