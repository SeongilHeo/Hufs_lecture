/*
 * memory_register.c
 *
 *  Created on: 2020. 6. 8.
 *      Author: tjddl
 */
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "MIPS.h"
static unsigned char progMEM[0x100000],dataMEM[0x100000],stackMEM[0x100000]; //모두 size는 1MiB로 해줌
static unsigned int reg[32]={0,};
static unsigned int PC,HI,LO;  //일반 레지스터 1개, PC, HI레지스터1개 ,LO레지스터 1개
unsigned int RegAccess( int A, unsigned int V, unsigned int nRW){
   // A: memory Address ,V:write value, nRW: 0->Read,1->Write
   if(nRW==0)//read
      return reg[A];
   else if(nRW==1)//write
      return reg[A]=V;
   else{
      printf("nRW01\n");
      fflush(stdout);
   }
   return 0;
}
unsigned int MemAccess(unsigned int A,unsigned int V, int nRW,int S){
   /* A: memory Address ,V:write value, nRW: 0->Read,1->Write,S(size): 0->Byte,1->Half word, 2->Word */
   unsigned int sel,offset; //메모리 접근 변수
   unsigned char *pM =NULL;       //메모리 포인터
   unsigned int R;//반환 값
   sel=A >>20;  //메모리 시작점
   offset =A &0xFFFFF;//메모리 주소

   if(sel==0x004)      //program memory
      pM=progMEM;
   else if(sel==0x100) //data memory
      pM=dataMEM;
   else if(sel==0x7ff) //stack memory
      pM=stackMEM;
   else
   {
      printf("No memory\n");
      return 1;
   }

   if(nRW==0)//read
   {
      if(S==0){ //byte
         R = pM[offset];
      }
      else if(S==1){ //half word
         R = pM[offset]*pow(2,8)+ pM[offset+1];
      }
      else if(S==2){ //word
         R = pM[offset]*pow(2,24)+ pM[offset+1]*pow(2,16) + pM[offset+2]*pow(2,8) +pM[offset+3];
      }
      else{
         printf("Wrong size\n");
         fflush(stdout);
         return 1;
      }
      return R;
   }
   else if(nRW==1)//write
   {
      int *numPtr = malloc(sizeof(int));    // 4바이트만큼 메모리 할당
      *numPtr = V;//입력값
      if(S==0){ //byte
         pM[offset]= *numPtr;
      }
      else if(S==1){ //half word
         pM[offset] = *((char *)numPtr);
         pM[offset+1] = *((char *)numPtr+1);
      }
      else if(S==2){ //word
         pM[offset] =   *((char *)numPtr+3);
         pM[offset+1] = *((char *)numPtr+2);
         pM[offset+2] = *((char *)numPtr+1);
         pM[offset+3] = *(char *)numPtr;
      }
      else{
         printf("Wrong size\n");
         fflush(stdout);
         return 1;
      }
      return 0;
   }
   else{
      printf("nRW 01 else\n");
      fflush(stdout);
   }//don't care??
   return 0;
}
//레지스터 접근 함수l
//view register
void viewRegister(void){
   char *r[32] = {"r0","at","v0","v1","a0","a1","a2","a3","t0","t1","t2","t3","t4","t5","t6","t7","s0","s1","s2","s3","s4","s5","s6","s7","t8","t9","k0","k1","gp","sp","fp","ra"};
   printf("----[REGISTER]----\n");
   printf("PC : %08X\n",PC);
   printf("HI : %08X\n",HI);
   printf("LO : %08X\n",LO);
   fflush(stdout);
   for(int i=0;i<32;i++)
      printf("R%02d [%s] = %X\n",i,r[i],reg[i]);
   fflush(stdout);
   printf("\n");
}
//view memory
void viewMemory(unsigned int start, unsigned int end){
   unsigned int sel, offset, e_offset;
   unsigned char *pM;
   sel = start >>20; // 앞의 12비트
   offset = start & 0xFFFFF;
   e_offset = end & 0xFFFFF;

   if(sel == 0x004)
   {
      pM = progMEM;
      printf("-----------Program Memory space-----------\n");
      fflush(stdout);
   }
   else if(sel == 0x100)
   {
      printf("-----------Data Memory space-----------");
      fflush(stdout);
      pM = dataMEM;
   }
   else if(sel == 0x7FF)
   {
      printf("-----------Stack Memory space-----------");
      fflush(stdout);
      pM = stackMEM;
   }
   else{
      printf("No memory\n");
      fflush(stdout);
      return;
   }
   for(int i=offset;i<(e_offset+4);i++){
      if(((i % 4)==0)|| i == offset){
         printf("\n");
         printf("[%X] ",(sel<<20)+i);
      }

      printf("%02x",pM[i]);
   }
   fflush(stdout);
   printf("\n");
}

