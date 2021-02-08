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

void control(unsigned int opcode) //control_signal�� ����� ���� �׸� 1����
{
   union op_input{//��ɾ� [31-25] 6bit, opcode
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
   }op; //�̸��� �̻��ؿ�;..
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
int Add_L(unsigned int pc) // pc 4����
{
   return pc+4;
}
unsigned int Add_R(unsigned int pc_4, unsigned int addr){ //4������ pc�� [15-0]���ϱ�
   return pc_4+addr;
}
unsigned int IMem()//�޸𸮿��� pc�� �ҷ����� IF����.
{
   IR.I =  MemAccess(PC, 0, 0, 2);//program MEM[pc]
   return IR.I;
}
unsigned int Shift_left2_L(unsigned input)//jump�ϱ� ���� [25-0] *4  ���� ���� pc�ּ��� �� 4bit ������ ��
{
   unsigned int output = ((Add_L(PC)) &0xff000000) | ((input << 2) & 0x00ffffff);
   return output;
}
unsigned int Shift_left2_R(unsigned Se)//[15-0] *4���ذ� # Add_R���� ���
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
{//�������� return�ؾߵǹǷ� *���� ���, Write data�� �ۿ��� �����ؾ��ϹǷ�   **������ ���
   *Read_data1   = reg[rs];
   *Read_data2 = reg[rt];//���������� ������ϴ� ��
   if(convalue.RegWrite == 1)//�������� write�� register �ּҰ� ��������
      *write_register = rd;
   else if(convalue.RegWrite == 0){;}//�ƹ��͵� ���ص���
   else{
      printf("RegWrite Control error\n");
      fflush(stdout);
      return;
   }
}
unsigned int ALU_control(unsigned int funct){//�׸� 2����
   union Operation{//ALU�� �Ѱ��� ��ȣ ex �������� c32, c10
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
unsigned int Jump_Mux(unsigned int jump_addr, unsigned int branch)//jump signal�� ���� ����
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
unsigned int Branch_Mux(unsigned int incre, unsigned int shift,int z)//branch signal�� ���� ����
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
unsigned int ALUSrc_Mux(unsigned int Read_data, unsigned int immediate)//alu�� ���� �� ����
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
unsigned int Sign_extend(unsigned int address){ //[15-0] 32bit���� ��ȯ
   if(IR.B.three & IR.B.two & ~(IR.B.one & IR.B.zero))//zero extend
      return address;
   return (address > 0x8000)?  0xffff0000 | address: address;//sign extend
}
unsigned int Data_Mem(unsigned int addr , unsigned int write_data)//data memory
{
   unsigned int data=0;
   if(convalue.MemWrite == 0){;}//���� ���� �ƹ��͵� ����
   else if(convalue.MemWrite == 1)//����
      data = MemAccess(addr, write_data, 1,2);//MeM[addr] = write_data;
   else
   {
      printf("Data_Mem write error\n");
      fflush(stdout);
      return 1;
   }
   if(convalue.MemRead == 0){;}//���� �� ���� �ƹ��͵� ����
   else if(convalue.MemRead ==1)//����
      data = MemAccess(addr, write_data, 0,2);//return MEM[addr];
   else
   {
      printf("Data_Mem read else\n");
      fflush(stdout);
      return 1;
   }
   return data;
}
unsigned int MemtoReg_Mux(unsigned int read_data, unsigned int ALU_result)//register�� �� �� ����
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
unsigned int ALU(unsigned int A, unsigned int B,unsigned int sig , int *Z)//alu����
{
   union Operation{//sig arg�� ���޹��� �� ����
      unsigned int In;
      struct op_num{
         unsigned int operation0 :1;
         unsigned int operation1 :1;//10
         unsigned int operation2 :1;
         unsigned int operation3 :1; //c32
         unsigned :28;//�Ⱦ��� ��
      }num; //op_num   if((convalue.ALUOp1 ==0) &(convalue.ALUOp0) == 0)
   }ALUOP;

   ALUOP.In = sig;//�Է�

   unsigned int logicOperation()//������ ����
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
int step(){//�帲�� ���� ����

   unsigned int curr_Inst = IMem();  //Ÿ�� ���� .
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
//�޸� ���� �Լ�
