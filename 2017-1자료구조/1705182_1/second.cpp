/*
 * second.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

int sumdigit(int n)//자릿수 더하는 함수
{
	int x;//반환할 x값 선언

	if(n/10 == 0)//한자리 수일때
	{
		return n;//자기자신을 반환
	}
	else//한자리수가 아닐때
	{
		x= sumdigit(n/10)+n%10;//10으로 나눈 몫 부분은 다시 재귀함수 이용하고 나머지 부분을 더한다.
		return x;//더해진 값을 반환
	}
}

int main()
{
	int num;//입력받을 숫자 선언

	cin>>num;//숫자 입력

	cout<<sumdigit(num)<<endl;//sumdigit함수 호출하여 출력

	return 0;//프로그램 종료
}

