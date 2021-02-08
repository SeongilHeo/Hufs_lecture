/*
 * datapath.c
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

void control(unsigned int opcode) //control_signal을 만드는 과정 그림 1참고
{
   union op_input{//명령어 [31-25] 6bit, opcode
      unsigned int In;
      struct op_num{
         unsigned int U :1;
         unsigned int I :1;
         unsigned int J :1;
         unsigned int B :1;
         unsigned int S :1;
         unsigned int L :1;
         unsigned int R :1;
      }num;
   }op; //이름이 이상해요;..
   op.In = opcode;
   op.num.I = ~IR.B.five & ~IR.B.four & IR.B.three;
   op.num.R = ~IR.B.zero & ~IR.B.one & ~IR.B.two & ~IR.B.three & ~IR.B.four & ~IR.B.five;//R
   op.num.L = ~IR.B.three & ~IR.B.four &  IR.B.five;//L
   op.num.S = ~IR.B.two &  IR.B.three & ~IR.B.four &  IR.B.five;//S
   op.num.J = ~IR.B.five & ~IR.B.four & ~IR.B.three & ~IR.B.two & IR.B.one;
   op.num.B = ~IR.B.one &  (IR.B.two| IR.B.zero) & ~IR.B.three & ~IR.B.four & ~IR.B.five;//B
   op.num.U = IR.B.zero & IR.B.one & IR.B.two;

   convalue.RegDst = op.num.R;//R;
   convalue.ALUSrc = op.num.L | op.num.S | op.num.I; //L || S;
   convalue.MemtoReg = op.num.L;//L;
   convalue.RegWrite = op.num.R | op.num.L | op.num.I;//R || L;
   convalue.MemRead = op.num.L;//L;
   convalue.MemWrite = op.num.S;//S;
   convalue.Branch = op.num.B;//B;
   convalue.ALUOp1 = op.num.R | (op.num.I & (IR.B.two & ~(IR.B.one & IR.B.zero)));//R;
   convalue.ALUOp0 = op.num.B | (op.num.I & (IR.B.two & ~(IR.B.one & IR.B.zero)));//B;
   convalue.Jump = op.num.J;
}
int Add_L(unsigned int pc) // pc 4증가
{
   return pc+4;
}
unsigned int Add_R(unsigned int pc_4, unsigned int addr){ //4증가한 pc에 [15-0]더하기
   return pc_4+addr;
}
unsigned int IMem()//메모리에서 pc값 불러오기 IF시작.
{
   IR.I =  MemAccess(PC, 0, 0, 2);//program MEM[pc]
   return IR.I;
}
unsigned int Shift_left2_L(unsigned input)//jump하기 위해 [25-0] *4  해준 다음 pc주소의 앞 4bit 합쳐준 값
{
   unsigned int output = ((Add_L(PC)) &0xff000000) | ((input << 2) & 0x00ffffff);
   return output;
}
unsigned int Shift_left2_R(unsigned Se)//[15-0] *4해준값 # Add_R에서 사용
{
   return Se << 2;
}
unsigned int RegDst_Mux(unsigned int rt,unsigned int rd){//rt[20-16], rd[15-11]
   if(convalue.RegDst==1 )
      return rd;
   else if(convalue.RegDst == 0)
      return rt;
   else{
      printf("RegDst Error\n");
      fflush(stdout);
      return 1;
   }
   printf("finish\n");
   fflush(stdout);

}
void Reg_file(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int *Read_data1, unsigned int *Read_data2, unsigned int *write_register)//25-21,20-16 rs,rt,rt||rd //////write data
{//여러개를 return해야되므로 *변수 사용, Write data는 밖에서 수정해야하므로   **변수로 사용
   *Read_data1   = reg[rs];
   *Read_data2 = reg[rt];//공통적으로 해줘야하는 것
   if(convalue.RegWrite == 1)//마지막에 write할 register 주소값 가져오기
      *write_register = rd;
   else if(convalue.RegWrite == 0){;}//아무것도 안해도됌
   else{
      printf("RegWrite Control error\n");
      fflush(stdout);
      return;
   }
}
unsigned int ALU_control(unsigned int funct){//그림 2참고
   union Operation{//ALU에 넘겨줄 신호 ex 과제에서 c32, c10
      unsigned int In;
      struct op_num{
         unsigned int operation0 :1;
         unsigned int operation1 :1;
         unsigned int operation2 :1;
         unsigned int operation3 :1;
         unsigned int :28;
      }num; //op_num   if((convalue.ALUOp1 ==0) &(convalue.ALUOp0) == 0)
   }OP;
   OP.In = 0;
   if(!convalue.ALUOp1 & !convalue.ALUOp0) //add
   {
      OP.num.operation1 = 0;
      OP.num.operation2 = 0;
      OP.num.operation3 = 1;
   }
   else if((convalue.ALUOp1 & ~convalue.ALUOp0)==1) //r-type
   {
      OP.num.operation0 = IR.B.Zero;
      OP.num.operation1 = IR.B.One;
      OP.num.operation2 = (IR.B.Two | IR.B.Four) | (IR.B.Five & IR.B.Three);
      OP.num.operation3 = IR.B.Five & ~IR.B.Three;
   }
   else if(!convalue.ALUOp1 && convalue.ALUOp0)//sub
   {
      OP.num.operation1 = 1;
      OP.num.operation2 = 0;
      OP.num.operation3 = 1;
   }
   else if(convalue.ALUOp1 & convalue.ALUOp0)//andi,xori,ori
   {
      OP.num.operation3= IR.B.three;
      OP.num.operation2= IR.B.two;
      OP.num.operation1= IR.B.one;
      OP.num.operation0= IR.B.zero;
   }
   else{printf("ALU_contorl else\n");}
   return OP.In;
}
unsigned int Jump_Mux(unsigned int jump_addr, unsigned int branch)//jump signal에 따라 진행
{
   if(convalue.Jump == 1)
   {
      if(IR.B.zero == 1){branch=RegAccess(31, PC+4, 1);}
      return jump_addr;
   }
   else if(convalue.Jump == 0)
      return branch;
   else
   {
      printf("Jump_Mux else\n");
      fflush(stdout);
      return 1;
   }
}
unsigned int Branch_Mux(unsigned int incre, unsigned int shift,int z)//branch signal에 따라 진행
{
   if((convalue.Branch & z) == 0)
      return incre;
   else if((convalue.Branch & z) == 1)
      return shift;
   else
   {
      printf("Branch_Mux else\n");
      fflush(stdout);
      return 1;
   }
}
unsigned int ALUSrc_Mux(unsigned int Read_data, unsigned int immediate)//alu로 보낼 값 지정
{
   if(convalue.ALUSrc == 1)
      return immediate;
   else if(convalue.ALUSrc == 0)
      return Read_data;
   else
   {
      printf("ALUSrc_Mux error\n");
      fflush(stdout);
      return 1;
   }
}
unsigned int Sign_extend(unsigned int address){ //[15-0] 32bit으로 전환
   if(IR.B.three & IR.B.two & ~(IR.B.one & IR.B.zero))//zero extend
      return address;
   return (address > 0x8000)?  0xffff0000 | address: address;//sign extend
}
unsigned int Data_Mem(unsigned int addr , unsigned int write_data)//data memory
{
   unsigned int data=0;
   if(convalue.MemWrite == 0){;}//쓸거 없음 아무것도 안함
   else if(convalue.MemWrite == 1)//쓴다
      data = MemAccess(addr, write_data, 1,2);//MeM[addr] = write_data;
   else
   {
      printf("Data_Mem write error\n");
      fflush(stdout);
      return 1;
   }
   if(convalue.MemRead == 0){;}//읽을 거 없음 아무것도 암함
   else if(convalue.MemRead ==1)//읽음
      data = MemAccess(addr, write_data, 0,2);//return MEM[addr];
   else
   {
      printf("Data_Mem read else\n");
      fflush(stdout);
      return 1;
   }
   return data;
}
unsigned int MemtoReg_Mux(unsigned int read_data, unsigned int ALU_result)//register에 쓸 값 전달
{
   if(convalue.MemtoReg == 1)
      return read_data;
   else if(convalue.MemtoReg == 0)
      return ALU_result;
   else
   {
      printf("MemtoReg_Mux else\n");
      fflush(stdout);
      return 1;
   }
}
unsigned int ALU(unsigned int A, unsigned int B,unsigned int sig , int *Z)//alu동작
{
   union Operation{//sig arg로 전달받은 거 분해
      unsigned int In;
      struct op_num{
         unsigned int operation0 :1;
         unsigned int operation1 :1;//10
         unsigned int operation2 :1;
         unsigned int operation3 :1; //c32
         unsigned :28;//안쓰는 값
      }num; //op_num   if((convalue.ALUOp1 ==0) &(convalue.ALUOp0) == 0)
   }ALUOP;

   ALUOP.In = sig;//입력

   unsigned int logicOperation()//과제와 동일
   {
      if((ALUOP.num.operation0 == 0) && (ALUOP.num.operation1==0))      //and
         return A&B;
      else if((ALUOP.num.operation0 == 1) && (ALUOP.num.operation1 == 0)) // or
         return A|B;
      else if((ALUOP.num.operation0 == 0) && (ALUOP.num.operation1 == 1)) // xor
         return A^B;
      else if((ALUOP.num.operation0 == 1) && (ALUOP.num.operation1 == 1)) // nor
         return ~(A|B);
      else
         return 1;
   }
   unsigned int shiftOperation()
   {
      if((ALUOP.num.operation0 == 0) && (ALUOP.num.operation1 == 0))//sll
         return B << IR.RI.shamt;
      else if((ALUOP.num.operation0 == 1) && (ALUOP.num.operation1 == 0)) // no
         return A;
      else if((ALUOP.num.operation0 == 1) && (ALUOP.num.operation1 == 1))//sra
      {
         int b =B;
         return b >> IR.RI.shamt;
      }
      else if((ALUOP.num.operation0 == 0) && (ALUOP.num.operation1 == 1))// arithmetic right
         return B >> IR.RI.shamt;
      else
         return 1;
   }
   unsigned int addSubtract()
   {
      unsigned int ret=0;
      if(ALUOP.num.operation1 == 0)//add
      {
         if(IR.B.zero&IR.B.one&IR.B.two)
            B=B<<16;
         ret = A + B;
      }
      else if(ALUOP.num.operation1 == 1) // subtract
      {
         ret = A -B;
         if(ret == 0)
         {
            if((IR.B.zero == 1) && (IR.B.two ==1))//bne branch Zero
            {
               *Z = 0;
               return ret;
            }
         }
         if(ret !=0)
         {
            *Z=1;
            return ret;
         }
         if(ret < 0 )
         {
            if((IR.B.two == 0)&&(IR.B.zero ==1)) //bltz
            {
               *Z = 1;
               return ret;
            }
         }
      }
      else
         return 1;
      *Z = (ret==0)? 1:0;
      return ret;
   }
   int checkSetLess()
   {
      return (A-B<0)?1:0;
   }
   if ((ALUOP.num.operation3 == 0) && (ALUOP.num.operation2 == 0)) // shift
      return shiftOperation();
   else if ((ALUOP.num.operation3 == 0) && (ALUOP.num.operation2 == 1)) // set less
      return checkSetLess();
   else if ((ALUOP.num.operation3 == 1) && (ALUOP.num.operation2 == 0)) // addsubtract
      return addSubtract();
   else if((ALUOP.num.operation3 == 1) && (ALUOP.num.operation2 == 1)) // logic
      return logicOperation();
   else
   {
      printf("alu else\n");
      fflush(stdout);
      return 1;
   }
}
int step(){//흐림에 따라 진행

   unsigned int curr_Inst = IMem();  //타입 저장 .
   if((IR.RI.opcode == 0) && (IR.RI.funct == 8))
   {
      PC = RegAccess(31, 0, 0);
      return 2;
   }
   if(curr_Inst==0x0000000c)//syscall 10
      return 1;
   IR.I=  curr_Inst;


   unsigned int incre_pc = Add_L(PC);//PC+4
   //-------------------------
   control(IR.RI.opcode);
   unsigned int jump_addr = Shift_left2_L(IR.JI.address);//[25-0]->[31-0]
   unsigned int Read_data1=0;
   unsigned int Read_data2=0;
   unsigned int write_register;
   Reg_file(IR.RI.rs, IR.RI.rt, RegDst_Mux(IR.RI.rt,IR.RI.rd), &Read_data1, &Read_data2, &write_register); //25-21, 20-16 /////20-16, 15-11

   unsigned int Se = Sign_extend(IR.II.immediate);//[15-0]->32bit
   //-------------------------------

   unsigned int sig = ALU_control(IR.RI.funct);
   int z=0;
   unsigned int ALU_result = ALU(Read_data1, ALUSrc_Mux(Read_data2,Se), sig, &z);
   //---------------
   PC=Jump_Mux(((incre_pc & 0xff000000) | jump_addr),Branch_Mux(incre_pc,Add_R(PC,Shift_left2_R(Se)),z));

   unsigned int read_data = Data_Mem(ALU_result,Read_data2);
   if(convalue.RegWrite == 1)
      reg[write_register] = MemtoReg_Mux(read_data, ALU_result);

   return 0;
}
//메모리 접근 함수
