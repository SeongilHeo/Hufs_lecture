/*
 * second.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

int sumdigit(int n)//�ڸ��� ���ϴ� �Լ�
{
	int x;//��ȯ�� x�� ����

	if(n/10 == 0)//���ڸ� ���϶�
	{
		return n;//�ڱ��ڽ��� ��ȯ
	}
	else//���ڸ����� �ƴҶ�
	{
		x= sumdigit(n/10)+n%10;//10���� ���� �� �κ��� �ٽ� ����Լ� �̿��ϰ� ������ �κ��� ���Ѵ�.
		return x;//������ ���� ��ȯ
	}
}

int main()
{
	int num;//�Է¹��� ���� ����

	cin>>num;//���� �Է�

	cout<<sumdigit(num)<<endl;//sumdigit�Լ� ȣ���Ͽ� ���

	return 0;//���α׷� ����
}

