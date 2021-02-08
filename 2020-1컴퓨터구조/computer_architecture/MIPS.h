/*
 * MIPS.h
 *
 *  Created on: 2020. 6. 8.
 *      Author: tjddl
 */

#ifndef MIPS_H_
#define MIPS_H_
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//메모리
//레지스터

//unsigned int MemAccess(unsigned int A, unsigned int V, int nRW,int S);
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
	struct bit{
		unsigned int  Zero:1;//funct0
		unsigned int  One:1;
		unsigned int  Two:1;
		unsigned int  Three:1;
		unsigned int  Four:1;//funct4
		unsigned int  Five:1;//funct5
		unsigned int :20;
		unsigned int  zero:1;//op0
		unsigned int  one:1;
		unsigned int  two:1;
		unsigned int  three:1;
		unsigned int  four:1;//op4
		unsigned int  five:1;//op5
	} B;
}IR; //IR: instruction register
struct control_signal{ //opcode로 만든 control #각 부분에서 signal을 사용한다
	unsigned int RegDst :1;
	unsigned int Jump:1;
	unsigned int ALUSrc :1;
	unsigned int MemtoReg :1;
	unsigned int RegWrite :1;
	unsigned int MemRead :1;
	unsigned int MemWrite :1;
	unsigned int Branch :1;
	unsigned int ALUOp1 :1;
	unsigned int ALUOp0 :1;
}convalue;

unsigned int MemAccess(unsigned int A,unsigned int V, int nRW,int S);
void viewRegister(void);
void viewMemory(unsigned int start, unsigned int end);
unsigned int RegAccess( int A, unsigned int V, unsigned int nRW);


void control(unsigned int opcode);
int Add_L(unsigned int pc);
unsigned int Add_R(unsigned int pc_4, unsigned int addr);
unsigned int IMem();
unsigned int Shift_left2_L(unsigned input);
unsigned int Shift_left2_R(unsigned Se);
unsigned int RegDst_Mux(unsigned int rt,unsigned int rd);
void Reg_file(unsigned int rs, unsigned int rt, unsigned int rd, unsigned int *Read_data1, unsigned int *Read_data2, unsigned int *write_register);
unsigned int ALU_control(unsigned int funct);
unsigned int Jump_Mux(unsigned int jump_addr, unsigned int branch);
unsigned int Branch_Mux(unsigned int incre, unsigned int shift,int z);
unsigned int ALUSrc_Mux(unsigned int Read_data, unsigned int immediate);
unsigned int Sign_extend(unsigned int address);
unsigned int Data_Mem(unsigned int addr , unsigned int write_data);//data memory
unsigned int MemtoReg_Mux(unsigned int read_data, unsigned int ALU_result);//register에 쓸 값 전달
unsigned int ALU(unsigned int A, unsigned int B,unsigned int sig , int *Z);
int step();
//메모리 접근 함수
#endif /* MIPS_H_ */
