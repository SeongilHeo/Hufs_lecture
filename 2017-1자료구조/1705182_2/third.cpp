/*
 * third.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;

int sumdigit(string n)//���ڸ����� ���ϴ� �Լ�
{
	int x;//��ȯ�� x�� ����

	if(n.length()==1)//���ڸ� ���϶�
	{
		switch(n.at(0))//switch�̿��Ͽ� �� ���� ��쿡 ���� x�� ���ϱ�
		{
			case 48://�ƽ�Ű �ڵ� 48�� ��
				x=0;//x=0
				break;
			case 49://�ƽ�Ű �ڵ� 49�� ��
				x=1;//x=1
				break;
			case 50://�ƽ�Ű �ڵ� 50�� ��
				x=2;//x=2
				break;
			case 51://�ƽ�Ű �ڵ� 51�� ��
				x=3;//x=3
				break;
			case 52://�ƽ�Ű �ڵ� 52�� ��
				x=4;//x=4
				break;
			case 53://�ƽ�Ű �ڵ� 53�� ��
				x=5;//x=5
				break;
			case 54://�ƽ�Ű �ڵ� 54�� ��
				x=6;//x=6
				break;
			case 55://�ƽ�Ű �ڵ� 55�� ��
				x=7;//x=7
				break;
			case 56://�ƽ�Ű �ڵ� 56�� ��
				x=8;//x=8
				break;
			case 57://�ƽ�Ű �ڵ� 57�� ��
				x=9;//x=9
				break;
		}
		return x;//x�� ��ȯ
	}
	else//���ڸ����� �ƴҋi
	{
		int x1;//��ȯ�� ��
		switch(n.at(0))//ù��° ���� switch���� �̿��Ͽ� ���ڷ� ��ȯ
		{
		case 48://�ƽ�Ű �ڵ� 48�� ��
				x1=0;//x=0
				break;
			case 49://�ƽ�Ű �ڵ� 49�� ��
				x1=1;//x=1
				break;
			case 50://�ƽ�Ű �ڵ� 50�� ��
				x1=2;//x=2
				break;
			case 51://�ƽ�Ű �ڵ� 51�� ��
				x1=3;//x=3
				break;
			case 52://�ƽ�Ű �ڵ� 52�� ��
				x1=4;//x=4
				break;
			case 53://�ƽ�Ű �ڵ� 53�� ��
				x1=5;//x=5
				break;
			case 54://�ƽ�Ű �ڵ� 54�� ��
				x1=6;//x=6
				break;
			case 55://�ƽ�Ű �ڵ� 55�� ��
				x1=7;//x=7
				break;
			case 56://�ƽ�Ű �ڵ� 56�� ��
				x1=8;//x=8
				break;
			case 57://�ƽ�Ű �ڵ� 57�� ��
				x1=9;//x=9
				break;
		}

		x=sumdigit(n.substr(1))+x1;//ù��° �ڸ����� ���ϰ� �ι�° �ڸ� ���ʹ� �ٽ� ��� �Լ� �̿�
		return x;//x�� ��ȯ
	}

}

int main()
{
	string num;//���ڿ� num����
	cin>>num;//num �Է�

	cout<<sumdigit(num);//sumdigit�Լ� ȣ���� ���

	return 0;
}



