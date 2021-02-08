/*
 * 33.cpp
 *
 *  Created on: 2017. 3. 29.
 *      Author: tjddl
 */
#include <iostream>
#include <fstream>
using namespace std;

int main ()
{

   ifstream fin;         // 파일 입력
   fin.open("fin.cpp");  // 입력 파일이름 지정

   char ch;
   int count =0;

   while(fin.get(ch)) // 키보드로 입력된 문자 하나를 ch에 저장
  //  while(fin.get()) //open된 파일 filename으로부터 입력된 문자 하나를 ch에 저장
   {
    	if(ch>='a' && ch<='z')
    		count++;
    	cout<<ch;
   }
   cout << count;
}
