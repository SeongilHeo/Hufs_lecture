/*
 * Maze.cpp
 *
 *  Created on: 2017. 5. 24.
 *      Author: tjddl
 */
#include<iostream>
#include"Maze.h"
using namespace std;

Maze::Maze()
{
	m=0;
	n=0;
	map=0;
	visited = 0;
}
void Maze::createMap()
{
	cin>>m>>n;
	map = new int* [m];
	visited = new bool*[m];
	for (int i = 0; i < m; i++)
	{
		map[i] = new int[n];
		visited[i] = new bool[n];
	}

	for (int row = 0; row < m; row++)
	 {
		for (int col = 0; col < n; col++)
		{
			cin>>map[row][col];
		}
	}
}
bool Maze::pathExist(Point source, Point dest)
{
	for (int row = 0; row < m; row++)
	{
		for (int col = 0; col < n; col++)
		{
			visited[row][col] = false;
		}
	}
	if (map[source.row][source.col]==1 || map[dest.row][dest.col] ==1)
	{
		return false;
	}
	else
		return pathExistRecur(source, dest);
}
bool Maze::pathExistRecur(Point currentPosition, Point dest)
{
	cout<<currentPosition.row <<" "<<currentPosition.col <<endl;
	visited[currentPosition.row][currentPosition.col] = true;
	Point nextPosition;
	if(currentPosition.row == dest.row && currentPosition.col==dest.col)
		return true;

	if (currentPosition.col+1 <= n-1)//오른쪽
	{
		if (map[currentPosition.row][currentPosition.col+1]==0 && visited[currentPosition.row][currentPosition.col+1] ==false)
		{
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col+1;
			if (pathExistRecur(nextPosition, dest))
			{
				return true;
			}
		}
	}
	if (currentPosition.row-1 >= 0)//위쪽
	{
		if (map[currentPosition.row-1][currentPosition.col]==0 && visited[currentPosition.row-1][currentPosition.col] ==false)
		{
			nextPosition.row = currentPosition.row-1;
			nextPosition.col = currentPosition.col;
			if (pathExistRecur(nextPosition, dest))
			{
				return true;
			}
		}
	}
	if(currentPosition.col-1 >= 0)//왼쪽
	{
		if (map[currentPosition.row][currentPosition.col-1]==0 && visited[currentPosition.row][currentPosition.col-1] ==false)
		{
			nextPosition.row = currentPosition.row;
			nextPosition.col = currentPosition.col-1;
		}
	}
	if(currentPosition.row+1 <= m-1)//아래쪽
	{
		if (map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col] ==false)
		{
			nextPosition.row = currentPosition.row+1;
			nextPosition.col = currentPosition.col;
			if (pathExistRecur(nextPosition, dest))
			{
				return true;
			}
		}
	}
	return false;
}

