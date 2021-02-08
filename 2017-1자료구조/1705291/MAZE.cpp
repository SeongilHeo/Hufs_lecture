/*
 * MAZE.cpp
 *
 *  Created on: 2017. 5. 29.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

int count=0;//전역 변수 count 도착점의 개수
class Point//행렬에 대한 클래스
{
public:
	int getRow();//행 얻어오는 함수
	int getCol();//열 얻어오는 함수
	int row;//행
	int col;//열
};
class Maze//미로 클래스
{
public:
	Maze();//생성자
	void createMap();//미로 만드는 함수
	void printMap();//미로 출력하는 함수
	void countDestination(Point source);//도착지 새는 함수
	bool pathExistRecur(Point currentPosition);//갈수 잇는 길을 확인하는 함수
private:
	int r; //the number of rows
	int c; //the number of cols
	int **map;//미로변수
	bool **visited;//방문경험 유무 변수

};

	Maze::Maze()//생성자
	{
		r=0;//행 초기화
		c=0;//열 초기화
		map=0;//
		visited = 0;
	}
	void Maze:: createMap()//미로 생성 함수
	{
		cin>>r>>c;//행 렬 갯수 입력
		map = new int* [r];//포인트 배열 동적 할당 하여 미로에 저장
		visited = new bool*[r];//포인트 배열 동적 할당 하여 visited에 저장
		for (int i = 0; i < r; i++)//map과 visited의 행 마다 열을 동적 할당
		{
			map[i] = new int[c];
			visited[i] = new bool[c];
		}

		for (int row = 0; row < r; row++)//행 만큼 반복
		 {
			for (int col = 0; col < c; col++)//열 만큼 반복
			{
				cin>>map[row][col];//행열을 값 입력
			}
		}
	}
	void Maze:: printMap()//미로 출력함수
	{
		for (int row = 0; row < r; row++)//행만큼 반복
		{
			for (int col = 0; col < c; col++)//열만큼 반복
			{
				cout<<map[row][col]<<" ";//행열 값 출력
			}
			cout<<endl;//줄바꿈 출력
		}
	}
	void Maze:: countDestination(Point source)//방문가능 곳 확인함수
	{
		for (int row = 0; row < r; row++)//행만큼 반복
		{
			for (int col = 0; col < c; col++)//열만큼 반복
			{
				visited[row][col] = false;//방문기록을 모두 false로 초기화
			}
		}
		if(map[source.row][source.col]==0)//입력받은 시작점의 값이 0 이면
		{
			count++;//갯수 증가
			pathExistRecur(source);//시작점에서 이동가능판단함수호출
			cout<<count;//갯수 출력
			return;
		}
		else//시작점이 1이아니면
		{
			cout<<count;//갯수 출력
			return;//종료
		}
	}
	bool Maze::pathExistRecur(Point currentPosition)//이동 가능판단 함수
	{
		Point nextPosition;//다음 위치 포인트

		visited[currentPosition.row][currentPosition.col] = true;//입력받은 위치 방문기록 체크
		if (currentPosition.col+1 <= c-1)//오른쪽에 여백이 있고
		{
			if (map[currentPosition.row][currentPosition.col+1]==0 && visited[currentPosition.row][currentPosition.col+1] ==false)//오른쪽 값이 0이고 방문한 적이 없으면
			{
				count++;//갯수 증가
				nextPosition.row = currentPosition.row;//현재위치를 다음위치로 변경
				nextPosition.col = currentPosition.col+1;
				if (pathExistRecur(nextPosition)==1)//다음위치로 재귀
				{
					return true;
				}
			}
		}
		if (currentPosition.row-1 >= 0)//위쪽 여백이 있고
		{
			if (map[currentPosition.row-1][currentPosition.col]==0 && visited[currentPosition.row-1][currentPosition.col] ==false)//위쪽 값이 0이고 방문경험이 없으면
			{
				count++;//갯수 증가
				nextPosition.row = currentPosition.row-1;//이동시킨 위치를 다음위치에 저장
				nextPosition.col = currentPosition.col;
				if (pathExistRecur(nextPosition)==1)//다음 위치로 재귀
				{
					return true;
				}
			}
		}
		if(currentPosition.col-1 >= 0)//왼쪽 여백이 있고
		{
			if (map[currentPosition.row][currentPosition.col-1]==0 && visited[currentPosition.row][currentPosition.col-1] ==false)//왼쪽 값이 0이고 방문경험이 없으면
			{
				count++;//갯수 증가
				nextPosition.row = currentPosition.row;//이동시킨 위치를 다음위치에 저장
				nextPosition.col = currentPosition.col-1;
				if (pathExistRecur(nextPosition)==1)//다음위치로 재귀
				{
					return true;
				}
			}
		}
		if(currentPosition.row+1 <= r-1)//아래쪽 여백이 있고
		{
			if (map[currentPosition.row+1][currentPosition.col]==0 && visited[currentPosition.row+1][currentPosition.col] ==false)//아래쪽 값이 0이고 방문경험이 없이면
			{
				count++;//갯수 증가
				nextPosition.row = currentPosition.row+1;//이동시킨 위치를 다음위치로 저장
				nextPosition.col = currentPosition.col;
				if (pathExistRecur(nextPosition)==1)//다음위치로 재귀
				{
					return true;
				}
			}
		}
		return false;//갈때가 없으면 false반환
	}
int main()
{
	Maze M;//미로 m 생성
	Point source;//시작점 변수
	M.createMap();//미로 생성
	cin>>source.row>>source.col;//시작점 입력
	M.countDestination(source);//시작점 방문가능 곳 체크 함수호출

	return 0;
}

