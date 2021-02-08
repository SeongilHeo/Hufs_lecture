/*
 * 1006.cpp
 *
 *  Created on: 2016. 10. 6.
 *      Author: tjddl
 */
#include <iostream>

using namespace std;

void shifta(int *, int *, int *);//4���� �Լ� ���� ����
void shiftb(int &, int &, int &);
void circularShift(int &, int &, int &);
void addTwoVector(const int *, const int *, int *, int);

int main ()
{
	int x=1, y=2, z=3;//exercise 1,2,3�� ����� ���� ����

	int X[] = {1, 2, 3, 4};//exercise 4�� ����� �迭 ����
	int Y[] = {2, 3, 4, 5};

	int *Z;

	cout<<"Exercise1\n";//exercise1�� ��� ��� ����

	shifta(&x, &y, &z);//�Լ� ȣ��
	cout<<x<<" " <<y<<" " <<z<<"\n";//e1(exercise1) ù��° ��� �� ���

	shifta(&x, &y, &z);
	cout<<x<<" " <<y<<" " <<z<<"\n";//e1 ��° ��� �� ���

	x=1, y=2, z=3;//e2�� ���� x,y,z�� �缳��

	cout<<"Exercise2\n";//e2 ��� ��� ����

	shiftb(x, y, z);//�Լ� ȣ��
	cout<<x<<" " <<y<<" " <<z<<"\n";//e2 ù��° ��� �� ���

	shiftb(x, y, z);
	cout<<x<<" " <<y<<" " <<z<<"\n";//e2 ��° ��� �� ���

	x=1, y=2, z=3;//e3�� ���� x,y,z�� �缳��

	cout<<"Exercise3\n";//e3 ��� ��� ����

	circularShift(x, y, z);//�Լ� ȣ��
	cout<<x<<" " <<y<<" " <<z<<"\n";//e3 ù��° ��� �� ���

	circularShift(x, y, z);
	cout<<x<<" " <<y<<" " <<z<<"\n";//e3 ��° ��� �� ���

	cout<<"Exercise4\n";//e4 ��� ��� ����

	Z = new int[2];// Z�� �ʱ�ȭ

	addTwoVector(X,Y,Z,4);//�Լ� ȣ��
	cout<<"C = {"<<Z[0]<<","<<Z[1]<<","<<Z[2]<<","<<Z[3]<<"}\n";//e4 ����� ���

	return 0;
}

void shifta(int *a, int *b, int *c)//e1�Լ�
{
	*c = *b;//a, b, c ���� ����
	*b = *a;
	*a = 0;
}
void shiftb(int &a, int &b, int &c)//e2�Լ�
{
	c = b;//a,b,c ���� ����
	b = a;
	a = 0;
}
void circularShift(int &a, int &b, int &c)//e3�Լ�
{
	int temp;//�ӽ������� ���� ���� ����

	temp = a;//a,b,c���� ����
	a = c;
	c = b;
	b = temp;
}
void addTwoVector(const int *a, const int *b, int *c, int N)//e4�Լ�
{
	int i;//for���� ���� ���� ����

	if(c != NULL)//c�迭 Ȯ���� �ʱ�ȭ
		delete [] c;

	c = new int [N];//cũ�� ����

	for(i =0; i < N; i++)//c�迭 ���� �� ����
	{
		c[i]= a[i] + b[i];
	}

}
