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

   ifstream fin;         // ���� �Է�
   fin.open("fin.cpp");  // �Է� �����̸� ����

   char ch;
   int count =0;

   while(fin.get(ch)) // Ű����� �Էµ� ���� �ϳ��� ch�� ����
  //  while(fin.get()) //open�� ���� filename���κ��� �Էµ� ���� �ϳ��� ch�� ����
   {
    	if(ch>='a' && ch<='z')
    		count++;
    	cout<<ch;
   }
   cout << count;
}
