/*
 * fourth.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;
void compare(string a,string b)//비교함수
{
	if(a.substr(0,1) != b.substr(0,1))//첫번째 자리수가 다를때
	{
		if(a> b)//첫번째 자리수가 사전식으로 a가 더 크면 1
			cout<< 1;//1출력
		else//아니면 -1
			cout<< -1;//-1출력
	}
	else//첫번째 자리수가 같을때
	{
		if(a.length() == 1)//길이가 1일때는 같다
			cout<< 0;//0출력
		else
		{
			a=a.substr(1);//a를 두번쩨 자리 수 부터 끝까지로 변경
			b=b.substr(1);//b를 두번째 자리 수 부터 끝까지로 변경
			compare(a,b);//재귀함수 이용하여 다시 두수를 비교
		}
	}
}
int main ()
{
	string a,b;//문자열 a,b 선언

	cin>>a>>b;//문자열 a,b 입력

	if(a.length()>b.length())//두수의 길이중 a가 길면
	{
		cout<< 1;//1출력
	}
	else if(a.length()<b.length())//b가 더 길면
	{
		cout<< -1;//-1 출력
	}
	else//길이가 같으면
		 compare(a,b);//compare함수 호출
	return 0;//프로그램 종료
}

