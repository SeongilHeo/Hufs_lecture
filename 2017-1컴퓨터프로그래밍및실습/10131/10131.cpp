/*
 * 10131.cpp
 *
 *  Created on: 2016. 10. 13.
 *      Author: tjddl
 */
#include <iostream>

using namespace std;
/*
const int ROWS=3;
const int COLS=3;

int main()
{
	int A[ROWS][COLS] = { { 2,3,0 }, { 8,9,1 }, { 7,0,5 } };
	int B[ROWS][COLS] = { { 1,0,0 }, { 1,0,0 }, { 1,0,0 } };
	int C[ROWS][COLS];

	int r,c;

	for(r = 0; r < ROWS; r++)
		for(c = 0; c < COLS; c++)
			C[r][c] = A[r][c] + B[r][c];

	for(r = 0;r < ROWS; r++)
	{
		for(c = 0;c < COLS; c++)
			cout << C[r][c] << " ";
		cout << endl;
	}
	return 0;
}*/
int main()
{
	int s[3][3][3];
	int x,y,z;
	int i=1;

	int a,b;

	for(z=0;z<3;z++)
		for(y=0;y<3;y++)
			for(x=0;x<3;x++)
				s[z][y][x] = i++;

	for(a=0; a<3; a++)
	{
		for(b=0; b<3; b++)
			cout<<s[0][a][b]<<" ";
		cout<<endl;
	}

	cout<<endl;

	for(a=0; a<3; a++)
	{
		for(b=0; b<3; b++)
			cout<<s[1][a][b]<<" ";
		cout<<endl;
	}

	cout<<endl;

	for(a=0; a<3; a++)
	{
		for(b=0; b<3; b++)
			cout<<s[2][a][b]<<" ";
		cout<<endl;
	}


	return 0;
}
