/*
 * show_instructions.c
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

unsigned int MemAccess(unsigned int A,unsigned int V, int nRW,int S);
void show_instruction(unsigned int opcode);
int main(){
   char command[2];      //명령어
   FILE *fp=NULL;
   unsigned char MEM[100];//파일에서 읽어온 값 배열로 저장 8bit씩 저장
   unsigned int ins, data;// 읽어올 데이터 &명령어
   int Ins_count;           //명령어 개수
   int data_count;          //데이터 개수
   char filename[50]; // 입력 파일이름
   unsigned int b_point;
   unsigned int jump_addr;
   unsigned int start, end;
   unsigned int r_num, m_loc, value;



   while(1){
      printf("Input command: ");
      fflush(stdout);
      scanf(" %s",command);
      getchar();
      if(!strcmp(command,"l")){
         printf("Input filename: ");
         fflush(stdout);
         scanf("%s",filename);
         getchar();

         if((fp = fopen(filename,"rb"))==NULL)
         {
            printf(("Cannot open file\n"));
            fflush(stdout);
            continue;
         }

         int i=0;
         int num;

         while(!feof(fp)){
            num=fgetc(fp); //8bit씩 읽어온다. //배열에 명령어 정보 저장
            MEM[i]=num;
            i++;
         }
        fclose(fp);
        Ins_count = MEM[0]*pow(2,24) + MEM[1]*pow(2,16) + MEM[2]*pow(2,8) + MEM[3]; //명령어의 개수 저장
        data_count = MEM [4]*pow(2,24) + MEM[5]*pow(2,16) + MEM[6]*pow(2,8) + MEM[7];//데이터의 개수 저장
         //명령어 정보 시작점
         for(int j=2; j<= Ins_count+1 ; j++ ){       //명령어의 개수 만큼 읽을때 까지 진행
            ins = MEM[j*4]*pow(2,24) + MEM[j*4+1]*pow(2,16) + MEM[j*4+2]*pow(2,8) + MEM[j*4+3];
            MemAccess(0x00400000+((j-2)*4),ins,1,2);
         }

         //데이터 값들 시작점
         for(int k=Ins_count+2; k<= data_count+Ins_count+1 ; k++ ){
            data = MEM[k*4]*pow(2,24) + MEM[k*4+1]*pow(2,16) + MEM[k*4+2]*pow(2,8) + MEM[k*4+3];
            MemAccess(0x10000000+((k-(Ins_count+2))*4),data,1,2);
         }
         PC = 0x00400000; //setpc
         RegAccess(29, 0x80000000,1);
         printf("Complete file load\n");
         fflush(stdout);
      }
      else if(!strcmp(command,"j")){
         printf("Input <program start point>: ");
         fflush(stdout);
         scanf(" %x",&jump_addr);
         getchar();
         PC = jump_addr;
      }
      else if(!strcmp(command,"g")){
         printf("go to break point or end\n");
         fflush(stdout);
         while(1){
            if(1 == step() || b_point == PC)//syscall 10일경우
               break;
         }
      }
      else if(!strcmp(command,"s")){
         if(step()==1)
            printf("syscall 10, terminate program\n");
         printf("one step\n");
         fflush(stdout);
      }
      else if(!strcmp(command,"m")){
         printf("Input <start> <end>: ");
         fflush(stdout);
         scanf(" %x %x", &start, &end);
         getchar();
         viewMemory(start,end);
      }
      else if(!strcmp(command,"r")){
         viewRegister();
      }
      else if(!strcmp(command,"sr")){
         printf("Input <register number> <value>: ");
         fflush(stdout);
         scanf(" %d %d",&r_num, &value);
         getchar();
         reg[r_num] = value;
      }
      else if(!strcmp(command,"sm")){
         printf("Input <location> <value>: ");
         fflush(stdout);
         scanf(" %d %d",&m_loc, &value);
         getchar();
         MemAccess(m_loc,value,1,2);
      }
      else if(!strcmp(command,"b")){
         printf("Input <break point>: ");
         fflush(stdout);
         scanf(" %d", &b_point);
         getchar();
      }
      else if(!strcmp(command,"x")){
         printf("program exit\n");
         fflush(stdout);
         break;
      }
      else if(!strcmp(command,"c")){
         for(int i=0 ;i<32;i++){reg[i]=0;}
         for(int i=0;i<0x100000;i++){progMEM[i]=0;dataMEM[i]=0;stackMEM[i]=0;}
         system("cls");
         printf("All Data clear\n");
         fflush(stdout);
      }
      else if(!strcmp(command,"i")){
    	  for(int i = 0 ; i < Ins_count; i++){ show_instruction(MemAccess(0x00400000+i*4,ins,0,2));}
      }
      else{
         printf("wrong command\n");
         fflush(stdout);
      }
   }
   return 0;
}

void show_instruction(unsigned int opcode)
{
	union instructionRegister{ // 32bit 명령어, 모든 곳에서 사용할 수 있도록 여기잇음
	   unsigned int I;
	   struct RFormat{
	      unsigned int funct :6;
	      unsigned int shamt : 5;
	      unsigned int rd : 5;
	      unsigned int rt : 5;
	      unsigned int rs : 5;
	      unsigned int opcode : 6;
	   } RI; //RFormat register
	   struct IFormat{
	      unsigned int immediate : 16;
	      unsigned int rt : 5;
	      unsigned int rs : 5;
	      unsigned int opcode : 6;
	   } II;
	   struct JFormat{
	      unsigned int address : 26;
	      unsigned int opcode : 6;
	   } JI;
	}IR; //IR: inst

   char *reg[32] = {"$zero","$at","$v0","$v1","$a0","$a1","$a2","$a3","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$t7","$s0","$s1","$s2","$s3","$s4","$s5","$s6","$s7","$t8","$t9","$k0","$k1","$gp","$sp","$fp","$ra"};

   IR.I = opcode;
   if(IR.RI.opcode == 0)
   {
      switch(IR.RI.funct)
      {
         case 0:
            printf("%08X	sll %s, %s, %u\n",opcode, reg[IR.RI.rd], reg[IR.RI.rt], IR.RI.shamt);
            break;
         case 2:
            printf("%08X	srl %s, %s, %u\n",opcode, reg[IR.RI.rd], reg[IR.RI.rt], IR.RI.shamt);
            break;
         case 3:
            printf("%08X	sra %s, %s, %u\n",opcode, reg[IR.RI.rd], reg[IR.RI.rt], IR.RI.shamt);
            break;
         case 8:
            printf("%08X	jr %s\n",opcode, reg[IR.RI.rs]);
            break;
         case 12:
            printf("%08X	syscall\n",opcode);
            break;
         case 16:
            printf("%08X	mfhi %s\n",opcode, reg[IR.RI.rd]);
            break;
         case 18:
            printf("%08X	mflo %s\n", opcode,reg[IR.RI.rd]);
            break;
         case 24:
            printf("%08X	mul %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         case 32:
            printf("%08X	add %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         case 34:
            printf("%08X	sub %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         case 36:
            printf("%08X	and %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         case 37:
            printf("%08X	or %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         case 38:
            printf("%08X	xor %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         case 39:
            printf("%08X	nor %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         case 42:
            printf("%08X	slt %s, %s, %s\n",opcode, reg[IR.RI.rd], reg[IR.RI.rs], reg[IR.RI.rt]);
            break;
         default:
            printf("R-format error");
      }
   }//end R-format
   else
   {
      switch(IR.II.opcode)
      {
         case 1:
            printf("%08X	bltz %s, %u\n",opcode, reg[IR.II.rs], IR.II.immediate*4);
            break;
         case 4:
            printf("%08X	beq %s, %s, %d\n", opcode,reg[IR.II.rs], reg[IR.II.rt], IR.II.immediate*4);
            break;
         case 5:
            printf("%08X	bne %s, %s, %u\n", opcode,reg[IR.II.rs], reg[IR.II.rt], IR.II.immediate*4);
            break;
         case 8:
            if(IR.II.immediate>32767)
               printf("%08X		addi %s, %s, %d\n",opcode, reg[IR.II.rs], reg[IR.II.rt], IR.II.immediate- 65536);
            else
               printf("%08X		addi %s, %s, %d\n",opcode, reg[IR.II.rs], reg[IR.II.rt], IR.II.immediate);
            break;
         case 10:
            printf("%08X	slti %s, %s, %u\n",opcode, reg[IR.II.rt], reg[IR.II.rs], IR.II.immediate);
            break;
         case 12:
            printf("%08X	andi %s, %s, %u\n", opcode,reg[IR.II.rt], reg[IR.II.rs], IR.II.immediate);
            break;
         case 13:
            if(IR.II.immediate>32767)
               printf("%08X		ori %s, %s, %d\n",opcode, reg[IR.II.rt], reg[IR.II.rs], IR.II.immediate - 65536);
            else
               printf("%08X		ori %s, %s, %d\n",opcode, reg[IR.II.rt], reg[IR.II.rs], IR.II.immediate);
            break;
         case 14:
            printf("%08X	xori %s, %s, %u\n", opcode,reg[IR.II.rt], reg[IR.II.rs], IR.II.immediate);
            break;
         case 15:
            if(IR.II.immediate>32767)
               printf("%08X		lui %s, %d\n",opcode, reg[IR.II.rt], IR.II.immediate - 65536);
            else
               printf("%08X	lui %s, %d\n", opcode,reg[IR.II.rt], IR.II.immediate);
            break;
         case 32:
            printf("%08X	lb %s, %u, (%s)\n",opcode, reg[IR.II.rt], IR.II.immediate, reg[IR.II.rs]);
            break;
         case 35:
            printf("%08X	lw %s, %u(%s)\n",opcode, reg[IR.II.rt], IR.II.immediate, reg[IR.II.rs]);
            break;
         case 36:
            printf("%08X	lbu %s, %u, (%s)\n", opcode,reg[IR.II.rt], IR.II.immediate, reg[IR.II.rs]);
            break;
         case 40:
            printf("%08X	sb %s, %u, (%s)\n", opcode,reg[IR.II.rt], IR.II.immediate, reg[IR.II.rs]);
            break;
         case 43:
            printf("%08X	sw %s, %u(%s)\n", opcode,reg[IR.II.rt], IR.II.immediate, reg[IR.II.rs]);
            break;
         default:
            if(IR.JI.opcode == 2)
               printf("%08X	j 0x%x\n", opcode,IR.JI.address*4);
            else if(IR.JI.opcode == 3)
               printf("%08X	jal 0x%x\n",opcode, IR.JI.address*4);
            else
               printf("I,J-format error");
      }
   }//end I,J-format
   return;
}


