/*
 * fourth.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;
void compare(string a,string b)//���Լ�
{
	if(a.substr(0,1) != b.substr(0,1))//ù��° �ڸ����� �ٸ���
	{
		if(a> b)//ù��° �ڸ����� ���������� a�� �� ũ�� 1
			cout<< 1;//1���
		else//�ƴϸ� -1
			cout<< -1;//-1���
	}
	else//ù��° �ڸ����� ������
	{
		if(a.length() == 1)//���̰� 1�϶��� ����
			cout<< 0;//0���
		else
		{
			a=a.substr(1);//a�� �ι��� �ڸ� �� ���� �������� ����
			b=b.substr(1);//b�� �ι�° �ڸ� �� ���� �������� ����
			compare(a,b);//����Լ� �̿��Ͽ� �ٽ� �μ��� ��
		}
	}
}
int main ()
{
	string a,b;//���ڿ� a,b ����

	cin>>a>>b;//���ڿ� a,b �Է�

	if(a.length()>b.length())//�μ��� ������ a�� ���
	{
		cout<< 1;//1���
	}
	else if(a.length()<b.length())//b�� �� ���
	{
		cout<< -1;//-1 ���
	}
	else//���̰� ������
		 compare(a,b);//compare�Լ� ȣ��
	return 0;//���α׷� ����
}

