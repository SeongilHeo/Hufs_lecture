/*
 * 1006.cpp
 *
 *  Created on: 2016. 10. 6.
 *      Author: tjddl
 */
#include <iostream>

using namespace std;

void shifta(int *, int *, int *);//4가지 함수 원형 정의
void shiftb(int &, int &, int &);
void circularShift(int &, int &, int &);
void addTwoVector(const int *, const int *, int *, int);

int main ()
{
	int x=1, y=2, z=3;//exercise 1,2,3에 사용할 변수 설정

	int X[] = {1, 2, 3, 4};//exercise 4에 사용할 배열 설정
	int Y[] = {2, 3, 4, 5};

	int *Z;

	cout<<"Exercise1\n";//exercise1에 결과 출력 시작

	shifta(&x, &y, &z);//함수 호출
	cout<<x<<" " <<y<<" " <<z<<"\n";//e1(exercise1) 첫번째 결과 값 출력

	shifta(&x, &y, &z);
	cout<<x<<" " <<y<<" " <<z<<"\n";//e1 둘째 결과 값 출력

	x=1, y=2, z=3;//e2를 위한 x,y,z값 재설정

	cout<<"Exercise2\n";//e2 결과 출력 시작

	shiftb(x, y, z);//함수 호출
	cout<<x<<" " <<y<<" " <<z<<"\n";//e2 첫번째 결과 값 출력

	shiftb(x, y, z);
	cout<<x<<" " <<y<<" " <<z<<"\n";//e2 둘째 결과 값 출력

	x=1, y=2, z=3;//e3를 위한 x,y,z값 재설정

	cout<<"Exercise3\n";//e3 결과 출력 시작

	circularShift(x, y, z);//함수 호출
	cout<<x<<" " <<y<<" " <<z<<"\n";//e3 첫번째 결과 값 출력

	circularShift(x, y, z);
	cout<<x<<" " <<y<<" " <<z<<"\n";//e3 둘째 결과 값 출력

	cout<<"Exercise4\n";//e4 결과 출력 시작

	Z = new int[2];// Z값 초기화

	addTwoVector(X,Y,Z,4);//함수 호출
	cout<<"C = {"<<Z[0]<<","<<Z[1]<<","<<Z[2]<<","<<Z[3]<<"}\n";//e4 결과값 출력

	return 0;
}

void shifta(int *a, int *b, int *c)//e1함수
{
	*c = *b;//a, b, c 변수 변경
	*b = *a;
	*a = 0;
}
void shiftb(int &a, int &b, int &c)//e2함수
{
	c = b;//a,b,c 변수 변경
	b = a;
	a = 0;
}
void circularShift(int &a, int &b, int &c)//e3함수
{
	int temp;//임시저장을 위한 변수 설정

	temp = a;//a,b,c변수 변경
	a = c;
	c = b;
	b = temp;
}
void addTwoVector(const int *a, const int *b, int *c, int N)//e4함수
{
	int i;//for문을 위한 변수 설정

	if(c != NULL)//c배열 확인후 초기화
		delete [] c;

	c = new int [N];//c크기 설정

	for(i =0; i < N; i++)//c배열 연산 후 생성
	{
		c[i]= a[i] + b[i];
	}

}
