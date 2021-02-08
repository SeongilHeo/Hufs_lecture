/*
 * Maze.h
 *
 *  Created on: 2017. 5. 24.
 *      Author: tjddl
 */

#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>
using namespace std;

class Point
{
public:
	int getRow();
	int getCol();
	int row;
	int col;

private:

};
class Maze
{
public:
	Maze();
	void createMap();
	bool pathExist(Point source, Point destination);
	bool pathExistRecur(Point currentPosition, Point dest);

private:
	int m; //the number of rows
	int n; //the number of cols
	int **map;
	bool **visited;
};


#endif /* MAZE_H_ */
