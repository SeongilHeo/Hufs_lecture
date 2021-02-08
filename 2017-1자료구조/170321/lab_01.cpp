/*
 * lab_01.cpp
 *
 *  Created on: 2017. 3. 21.
 *      Author: tjddl
 */
#include<iostream>
using namespace std;

int electricCharge(int month, int kwh);

int main()
{
   int month;//사용 월
   int kwh;//사용량

   cin>>month;//사용 월 입력
   cin>>kwh;//사용량 입력

   float AddedTax;//부가가치세
   float BasedCharge;//기반요금
   int TotalCharge;//청구요금계

   AddedTax=electricCharge(month, kwh)*0.1;//부가가치세 계산

   AddedTax=(int)(AddedTax+0.5);//부가가치세 원단위 미만 반올림



   BasedCharge=electricCharge(month, kwh)*0.037;//기반요금 계산
   BasedCharge=(((int)BasedCharge)/10)*10;//기반요금 10원 미만 절사

   TotalCharge=electricCharge(month, kwh)+BasedCharge+AddedTax;//청구요금계 계산
   TotalCharge=(TotalCharge/10)*10;//청구요금 10원미만 절사

   cout<<TotalCharge;//청구요금 출력

   return 0;
}

int electricCharge(int month, int kwh)
{
   int BasicCharge;//기본요금
   float UsedCharge;//사용량 요금

      if(kwh<=200)//200kWh 이하 사용시
      {
         BasicCharge=910;
         UsedCharge=93.3*kwh;
      }
      else if(kwh>=201 && kwh<=400)//201~400kWh 사용시
      {
         BasicCharge=1600;
         UsedCharge=(187.9*(kwh-200))+(93.3*200);
      }
      else//400kWh 초과 사용시
      {
         BasicCharge=7300;
         if(kwh>1000)//슈퍼유저요금
         {
        	 if((month==7)||(month==8)||(month==12)||(month==1)||(month==2))//동계,하계 슈퍼유저 요금
        		 UsedCharge=(709.5*(kwh-1000))+(93.3*200)+(187.9*200)+(280.6*600);
        	 else
        		 UsedCharge=(280.6*(kwh-400))+(93.3*200)+(187.9*200);
         }
         else
        	 UsedCharge=(280.6*(kwh-400))+(93.3*200)+(187.9*200);
      }

      UsedCharge=(int)UsedCharge;//사용량 요금 원단위 미만 절사

      return BasicCharge+(int)UsedCharge;//전기요금계 계산 및 반환
}
