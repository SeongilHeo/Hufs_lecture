/*
 * lab_03.cpp
 *
 *  Created on: 2017. 3. 22.
 *      Author: tjddl
 */
#include<iostream>
#include<cstring>
using namespace std;

struct Student {
  int id;  // 학번
  int score;  // 점수
  int abscentDays;  // 결석일수
  int totalScore;  // 총 점수
  char grade[3];  // 학점
};
void swap(int &X,int &Y)//변수의 주소값을 교체하는 함수
{
	int temp;
	temp=X;
	X=Y;
	Y=temp;
}
int main()
{
	int n;//학생수

	cin>>n;//학생수 입력

	struct Student S[n];//학생들 구조체 배열

	for(int i=0; i<n; i++)//id,점수,결석일수 입력
		cin>>S[i].id>>S[i].score>>S[i].abscentDays;
	for(int j=0; j<n; j++)//총점을 계산
		S[j].totalScore=S[j].score-(2*S[j].abscentDays);

	 int ap = (int)(n*0.1+0.5);//a+ 수
	 int az = (int)(n*0.25);//a+,a0 수
	 int bp = (int)(n*0.4+0.5);//a+,a0,b+ 수
	 int bz = (int)(n*0.6);//a+,a0,b+,b0수
	 int cp = (int)(n*0.8+0.5);//c+까지수
	 int cz = (int)(n*0.9);//c0까지수
	 int dp = (int)(n*0.95);//d+까지수

	 for(int s=0; s<n-1; s++)//점수순서에 따라 구조체 배열 재배열
	 {
		 for(int r=s+1; r<n ; r++)
		 {
			 if(S[s].totalScore <S[r].totalScore)
			 {
				 swap(S[s],S[r]);
			 }
		 }
	 }
	 for(int t=0; (t>=0)&&(t < ap); t++)//index 0부터 A+까지에 A+등급 입력
		 strcpy(S[t].grade,"A+");
	 for(int l=ap; (l>=ap)&&(l < az) ; l++)//index A+부터 A0까지에 A0등급 입력
		strcpy(S[l].grade,"A0");
	for(int m=az;  (m>=az)&&(m < bp); m++)//index A0부터 B+까지에 B+등급 입력
		strcpy(S[m].grade,"B+");
	 for(int o=bp; (o>=bp)&&(o < bz); o++)//index B+부터 B0까지에 B0등급 입력
		 strcpy(S[o].grade,"B0");
	 for(int p=bz; (p>=bz)&&(p < cp); p++)//index B0부터 C+까지에 C+등급 입력
		 strcpy(S[p].grade,"C+");
	 for(int q=cp; (q>=cp)&&(q < cz); q++)//index C+부터 C0까지에 C0등급 입력
		 strcpy(S[q].grade,"C0");
	 for(int r=cz; (r>=cz)&&(r < dp); r++)//index C0부터 D+까지에 D+등급 입력
		 strcpy(S[r].grade,"D+");
	 for(int s=dp; (s>=dp)&&(s < n); s++)//index D0부터 n까지에 D0등급 입력
		 strcpy(S[s].grade,"D0");
	 for(int u=0;u<n-1 ;u++)//등수가 같을 경우 같은 등급을 받는 조건성립
	 {
		 if(S[u].totalScore==S[u+1].totalScore)
			 strcpy(S[u+1].grade,S[u].grade);
	 }
	 for(int k=0; k<n; k++)//결석일수가 16초과시 F학접 입력
 	 	 {
		 	 if(S[k].abscentDays>16)
	 	 		 strcpy(S[k].grade,"F");
	 	 }

	for(int j=0; j<n ;j++)//학번, 점수, 등급 출력
		cout<<S[j].id<<" "<<S[j].totalScore<<"  "<<S[j].grade<<endl;
	return 0;
}
