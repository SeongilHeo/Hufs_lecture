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
   int month;//��� ��
   int kwh;//��뷮

   cin>>month;//��� �� �Է�
   cin>>kwh;//��뷮 �Է�

   float AddedTax;//�ΰ���ġ��
   float BasedCharge;//��ݿ��
   int TotalCharge;//û����ݰ�

   AddedTax=electricCharge(month, kwh)*0.1;//�ΰ���ġ�� ���

   AddedTax=(int)(AddedTax+0.5);//�ΰ���ġ�� ������ �̸� �ݿø�



   BasedCharge=electricCharge(month, kwh)*0.037;//��ݿ�� ���
   BasedCharge=(((int)BasedCharge)/10)*10;//��ݿ�� 10�� �̸� ����

   TotalCharge=electricCharge(month, kwh)+BasedCharge+AddedTax;//û����ݰ� ���
   TotalCharge=(TotalCharge/10)*10;//û����� 10���̸� ����

   cout<<TotalCharge;//û����� ���

   return 0;
}

int electricCharge(int month, int kwh)
{
   int BasicCharge;//�⺻���
   float UsedCharge;//��뷮 ���

      if(kwh<=200)//200kWh ���� ����
      {
         BasicCharge=910;
         UsedCharge=93.3*kwh;
      }
      else if(kwh>=201 && kwh<=400)//201~400kWh ����
      {
         BasicCharge=1600;
         UsedCharge=(187.9*(kwh-200))+(93.3*200);
      }
      else//400kWh �ʰ� ����
      {
         BasicCharge=7300;
         if(kwh>1000)//�����������
         {
        	 if((month==7)||(month==8)||(month==12)||(month==1)||(month==2))//����,�ϰ� �������� ���
        		 UsedCharge=(709.5*(kwh-1000))+(93.3*200)+(187.9*200)+(280.6*600);
        	 else
        		 UsedCharge=(280.6*(kwh-400))+(93.3*200)+(187.9*200);
         }
         else
        	 UsedCharge=(280.6*(kwh-400))+(93.3*200)+(187.9*200);
      }

      UsedCharge=(int)UsedCharge;//��뷮 ��� ������ �̸� ����

      return BasicCharge+(int)UsedCharge;//�����ݰ� ��� �� ��ȯ
}
