/*
 * third.cpp
 *
 *  Created on: 2017. 5. 18.
 *      Author: tjddl
 */
#include<iostream>
#include<string>
using namespace std;

int sumdigit(string n)//각자리수를 더하는 함수
{
	int x;//반환할 x값 선언

	if(n.length()==1)//한자리 수일때
	{
		switch(n.at(0))//switch이용하여 그 수를 경우에 따라 x값 정하기
		{
			case 48://아스키 코드 48일 때
				x=0;//x=0
				break;
			case 49://아스키 코드 49일 때
				x=1;//x=1
				break;
			case 50://아스키 코드 50일 때
				x=2;//x=2
				break;
			case 51://아스키 코드 51일 때
				x=3;//x=3
				break;
			case 52://아스키 코드 52일 때
				x=4;//x=4
				break;
			case 53://아스키 코드 53일 때
				x=5;//x=5
				break;
			case 54://아스키 코드 54일 때
				x=6;//x=6
				break;
			case 55://아스키 코드 55일 때
				x=7;//x=7
				break;
			case 56://아스키 코드 56일 때
				x=8;//x=8
				break;
			case 57://아스키 코드 57일 때
				x=9;//x=9
				break;
		}
		return x;//x를 반환
	}
	else//한자리수가 아닐땓
	{
		int x1;//반환할 값
		switch(n.at(0))//첫번째 수는 switch문을 이용하여 숫자로 변환
		{
		case 48://아스키 코드 48일 때
				x1=0;//x=0
				break;
			case 49://아스키 코드 49일 때
				x1=1;//x=1
				break;
			case 50://아스키 코드 50일 때
				x1=2;//x=2
				break;
			case 51://아스키 코드 51일 때
				x1=3;//x=3
				break;
			case 52://아스키 코드 52일 때
				x1=4;//x=4
				break;
			case 53://아스키 코드 53일 때
				x1=5;//x=5
				break;
			case 54://아스키 코드 54일 때
				x1=6;//x=6
				break;
			case 55://아스키 코드 55일 때
				x1=7;//x=7
				break;
			case 56://아스키 코드 56일 때
				x1=8;//x=8
				break;
			case 57://아스키 코드 57일 때
				x1=9;//x=9
				break;
		}

		x=sumdigit(n.substr(1))+x1;//첫번째 자리수는 더하고 두번째 자리 부터는 다시 재귀 함수 이용
		return x;//x값 반환
	}

}

int main()
{
	string num;//문자열 num선언
	cin>>num;//num 입력

	cout<<sumdigit(num);//sumdigit함수 호출후 출력

	return 0;
}



