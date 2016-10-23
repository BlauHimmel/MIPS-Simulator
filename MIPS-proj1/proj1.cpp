#include "stdafx.h"
#include "proj1.h"
#include "computer.h"
#include <iostream>
using namespace std;

/*
 *  Return a string containing the disassembled version of the given
 *  instruction.  You absolutely MUST follow the formatting instructions
 *  given in the assignment.  Note that the string your return should
 *  not include a tab at the beginning or a newline at the end since
 *  those are added in computer.c where this function is called.
 *
 *  Finally you are responsible for managing the memory associated with
 *  any string you return.  If you use malloc, you will somehow need to
 *  free the memory later (note that you cannot modify computer.c).
 *  Hint: static or global variables.
 */

/*
R指令则opcode为0，表中表示funct,其他格式表示opcode
格式				指令					二进制		
R		addu    Rdest, Rsrc1, Rsrc2			100001
I       addiu   Rdest, Rsrc1, imm			001001
R       subu    Rdest, Rsrc1, Rsrc2			100011
R       sll     Rdest, Rsrc, shamt			000000
R       srl     Rdest, Rsrc, shamt			000010
R       and     Rdest, Rsrc1, Rsrc2			100100
I       andi    Rdest, Rsrc, imm			001100
R       or      Rdest, Rsrc1, Rsrc2			100101
I       ori     Rdest, Rsrc, imm			001101
I       lui     Rdest, imm					001111
R       slt     Rdest, Rsrc1, Rsrc2			101010
I       beq     Rsrc1, Rsrc2, raddr			000100
I       bne     Rsrc1, Rsrc2, raddr			000101
J       j       address						000010
J       jal     address						000011
R       jr      Rsrc						001000
I       lw      Rdest, offset (Radd)		100011
I       sw      Rsrc, offset (Radd)			101011
*/

char* address(char* target)
{
	char* result=new char[9];
	for(int i=0;i<8;i++)
		result[i]='0';
	result[8]='\0';
	int j=strlen(target);
	for(int i=8;j>=0;j--,i--)
		result[i]=target[j];
	return result;
}


char * disassembled (unsigned int instr, unsigned int pc) {

	int opcode,rs,rt,rd,shamt,funct,immediate,target_address;
	opcode=instr>>26;
	rs=(instr<<6)>>27;
	rt=(instr<<11)>>27;
	rd=(instr<<16)>>27;
	shamt=(instr<<21)>>27;
	funct=(instr<<26)>>26;
	immediate=(instr<<16)>>16;
	target_address=(instr<<6)>>6;	//首先取出备用的各种数据段

	if(opcode==0)	//R格式
	{
		if(funct==33)			//addu    Rdest, Rsrc1, Rsrc2
		{
			char* temp1="addu\t$";
			char* temp2=new char[3];
			char* temp4=new char[3];
			char* temp6=new char[3];

			itoa(rd,temp2,10);
			char* temp3=", $";
			itoa(rs,temp4,10);
			char* temp5=", $";
			itoa(rt,temp6,10);

			char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);
			strcat(result,temp3);
			strcat(result,temp4);
			strcat(result,temp5);
			strcat(result,temp6);

			delete[] temp2;
			delete[] temp4;
			delete[] temp6;

			return result;
		}
		else if(funct==35)		//subu    Rdest, Rsrc1, Rsrc2
		{
			char* temp1="subu\t$";
			char* temp2=new char[3];
			char* temp4=new char[3];
			char* temp6=new char[3];

			itoa(rd,temp2,10);
			char* temp3=", $";
			itoa(rs,temp4,10);
			char* temp5=", $";
			itoa(rt,temp6,10);
			
			char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);
			strcat(result,temp3);
			strcat(result,temp4);
			strcat(result,temp5);
			strcat(result,temp6);

			delete[] temp2;
			delete[] temp4;
			delete[] temp6;

			return result;
		}
		else if(funct==0)		//sll     Rdest, Rsrc, shamt
		{
			char* temp1="sll\t$";
			char* temp2=new char[3];
			char* temp4=new char[3];
			char* temp6=new char[3];

			itoa(rd,temp2,10);
			char* temp3=", $";
			itoa(rt,temp4,10);
			char* temp5=", ";
			itoa(shamt,temp6,10);
			
			char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);
			strcat(result,temp3);
			strcat(result,temp4);
			strcat(result,temp5);
			strcat(result,temp6);

			delete[] temp2;
			delete[] temp4;
			delete[] temp6;

			return result;
		}
		else if(funct==2)		//srl     Rdest, Rsrc, shamt
		{
			char* temp1="srl\t$";
			char* temp2=new char[3];
			char* temp4=new char[3];
			char* temp6=new char[3];

			itoa(rd,temp2,10);
			char* temp3=", $";
			itoa(rt,temp4,10);
			char* temp5=", ";
			itoa(shamt,temp6,10);
			
			char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);
			strcat(result,temp3);
			strcat(result,temp4);
			strcat(result,temp5);
			strcat(result,temp6);

			delete[] temp2;
			delete[] temp4;
			delete[] temp6;

			return result;
		}
		else if(funct==36)		//and     Rdest, Rsrc1, Rsrc2
		{
			char* temp1="and\t$";
			char* temp2=new char[3];
			char* temp4=new char[3];
			char* temp6=new char[3];

			itoa(rd,temp2,10);
			char* temp3=", $";
			itoa(rs,temp4,10);
			char* temp5=", $";
			itoa(rt,temp6,10);
			
			char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);
			strcat(result,temp3);
			strcat(result,temp4);
			strcat(result,temp5);
			strcat(result,temp6);

			delete[] temp2;
			delete[] temp4;
			delete[] temp6;

			return result;
		}
		else if(funct==37)		//or      Rdest, Rsrc1, Rsrc2	
		{
			char* temp1="or\t$";
			char* temp2=new char[3];
			char* temp4=new char[3];
			char* temp6=new char[3];

			itoa(rd,temp2,10);
			char* temp3=", $";
			itoa(rs,temp4,10);
			char* temp5=", $";
			itoa(rt,temp6,10);
			
			char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);
			strcat(result,temp3);
			strcat(result,temp4);
			strcat(result,temp5);
			strcat(result,temp6);

			delete[] temp2;
			delete[] temp4;
			delete[] temp6;

			return result;
		}
		else if(funct==42)		//slt     Rdest, Rsrc1, Rsrc2	
		{
			char* temp1="slt\t$";
			char* temp2=new char[3];
			char* temp4=new char[3];
			char* temp6=new char[3];

			itoa(rd,temp2,10);
			char* temp3=", $";
			itoa(rs,temp4,10);
			char* temp5=", $";
			itoa(rt,temp6,10);
			
			char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);
			strcat(result,temp3);
			strcat(result,temp4);
			strcat(result,temp5);
			strcat(result,temp6);

			delete[] temp2;
			delete[] temp4;
			delete[] temp6;

			return result;
		}
		else if(funct==8)		//jr      Rsrc		
		{
			char* temp1="jr\t$";
			char* temp2=new char[3];

			itoa(rs,temp2,10);
	
			char *result=new char[strlen(temp1)+strlen(temp2)+1];
			*result=NULL;
			strcat(result,temp1);
			strcat(result,temp2);

			delete[] temp2;

			return result;
		}
		else
		{
			exit(0);
		}
	}
	//I格式
	else if(opcode==9)		//addiu   Rdest, Rsrc1, imm
	{

		char* temp1="addiu\t$";
		char* temp2=new char[3];
		char* temp4=new char[3];
		char* temp6=new char[6];

		itoa(rt,temp2,10);
		char* temp3=", $";
		itoa(rs,temp4,10);
		char* temp5=", ";

		if(immediate>32768) //2^15
			immediate-=65536;  //2^16	符号扩展

		itoa(immediate,temp6,10);

			
		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);
		strcat(result,temp5);
		strcat(result,temp6);

		delete[] temp2;
		delete[] temp4;
		delete[] temp6;

		return result;
	}

	else if(opcode==12)		//andi    Rdest, Rsrc, imm			
	{
		char* temp1="andi\t$";
		char* temp2=new char[3];
		char* temp4=new char[3];
		char* temp6=new char[6];

		itoa(rt,temp2,10);
		char* temp3=", $";
		itoa(rs,temp4,10);
		char* temp5=", 0x";
		itoa(immediate,temp6,16);

		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);
		strcat(result,temp5);
		strcat(result,temp6);

		delete[] temp2;
		delete[] temp4;
		delete[] temp6;

		return result;
	}

	else if(opcode==13)		//ori     Rdest, Rsrc, imm			
	{
		char* temp1="ori\t$";
		char* temp2=new char[3];
		char* temp4=new char[3];
		char* temp6=new char[6];

		itoa(rt,temp2,10);
		char* temp3=", $";
		itoa(rs,temp4,10);
		char* temp5=", 0x";
		itoa(immediate,temp6,16);

			
		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);
		strcat(result,temp5);
		strcat(result,temp6);

		delete[] temp2;
		delete[] temp4;
		delete[] temp6;

		return result;
	}

	else if(opcode==15)		//lui     Rdest, imm				
	{
		char* temp1="lui\t$";
		char* temp2=new char[3];
		char* temp4=new char[6];

		itoa(rt,temp2,10);
		char* temp3=", 0x";
		itoa(immediate,temp4,16);

			
		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);

		delete[] temp2;;
		delete[] temp4;

		return result;
	}

	else if(opcode==4)		//beq     Rsrc1, Rsrc2, raddr	
	{
		char* temp1="beq\t$";
		char* temp2=new char[3];
		char* temp4=new char[3];
		char* temp6=new char[9];
		
		itoa(rs,temp2,10);
		char* temp3=", $";
		itoa(rt,temp4,10);
		char* temp5=", 0x";

		if(immediate>32768) //2^15
			immediate-=65536;  //2^16	符号扩展

		immediate=pc+4+4*immediate;

		itoa(immediate,temp6,16);

		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);
		strcat(result,temp5);
		strcat(result,address(temp6));

		delete[] temp2;
		delete[] temp4;
		delete[] temp6;

		return result;
	}

	else if(opcode==5)		//bne     Rsrc1, Rsrc2, raddr			
	{
		char* temp1="bne\t$";
		char* temp2=new char[3];
		char* temp4=new char[3];
		char* temp6=new char[9];

		itoa(rs,temp2,10);
		char* temp3=", $";
		itoa(rt,temp4,10);
		char* temp5=", 0x";

		if(immediate>32768) //2^15
			immediate-=65536;  //2^16	符号扩展
		
		immediate=pc+4+4*immediate;

		itoa(immediate,temp6,16);

		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);
		strcat(result,temp5);
		strcat(result,address(temp6));

		delete[] temp2;
		delete[] temp4;
		delete[] temp6;

		return result;
	}

	else if(opcode==35)		//lw      Rdest, offset (Radd)		
	{
		char* temp1="lw\t$";
		char* temp2=new char[3];
		char* temp4=new char[6];
		char* temp6=new char[3];

		itoa(rt,temp2,10);
		char* temp3=", ";

		if(immediate>32768) //2^15
			immediate-=65536;  //2^16	符号扩展

		itoa(immediate,temp4,10);
		char* temp5=" ($";
		itoa(rs,temp6,10);
		char* temp7=")";
		
		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+strlen(temp7)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);
		strcat(result,temp5);
		strcat(result,temp6);
		strcat(result,temp7);

		delete[] temp2;
		delete[] temp4;
		delete[] temp6;

		return result;

	}

	else if(opcode==43)		//sw      Rsrc, offset (Radd)			
	{
		char* temp1="sw\t$";
		char* temp2=new char[3];
		char* temp4=new char[6];
		char* temp6=new char[3];

		itoa(rt,temp2,10);
		char* temp3=", ";

		if(immediate>32768) //2^15
			immediate-=65536;  //2^16	符号扩展

		itoa(immediate,temp4,10);
		char* temp5=" ($";
		itoa(rs,temp6,10);
		char* temp7=")";
		
		char *result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+strlen(temp4)+strlen(temp5)+strlen(temp6)+strlen(temp7)+1];
		*result=NULL;
		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,temp3);
		strcat(result,temp4);
		strcat(result,temp5);
		strcat(result,temp6);
		strcat(result,temp7);

		delete[] temp2;
		delete[] temp4;
		delete[] temp6;

		return result;
	}
	//J格式
	else if(opcode==2)		//j       address				
	{
		char* temp1="j\t ";
		char* temp3=new char[9];

		target_address=(pc>>28)+target_address*4;

		char* temp2="0x";
		itoa(target_address,temp3,16);

		char* result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+1];
		*result=NULL;

		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,address(temp3));

		return result;
	}

	else if(opcode==3)		//jal     address
	{
		char* temp1="jal\t ";
		char* temp3=new char[9];

		target_address=(pc>>28)+target_address*4;

		char* temp2="0x";
		itoa(target_address,temp3,16);

		char* result=new char[strlen(temp1)+strlen(temp2)+strlen(temp3)+1];
		*result=NULL;

		strcat(result,temp1);
		strcat(result,temp2);
		strcat(result,address(temp3));

		return result;
	}
	
	else
	{
		exit(0);
	}

    /* You replace this code by the right stuff. */
	//if (/*instruction isn't supported */) exit (0); // Your program must exit when an unsupported instruction is detected
  	//return "";

}

/*
 *  Simulate the execution of the given instruction, updating the
 *  pc appropriately.
 *
 *  If the instruction modified a register--i.e. if it was lw,
 *  addu, addiu, subu, sll, srl, and, andi, or, ori, lui, or slt
 *  to list a few examples-- return the index of the modified
 *  register in *changedReg, otherwise return -1 in *changedReg.
 *  Note that you should never return 0 in *changedReg, since
 *  $0 cannot be changed!  Note that even if the instruction
 *  changes the register back to it's old value
 *  (e.g. addu $3, $3, $0) the destination register ($3 in the
 *  example) should be marked changed!
 *
 *  If the instruction was sw, return the address of the
 *  updated memory location in *changedMem, otherwise return -1
 *  in *changedMem.
 */
/*
R		addu    Rdest, Rsrc1, Rsrc2			100001
I       addiu   Rdest, Rsrc1, imm			001001
R       subu    Rdest, Rsrc1, Rsrc2			100011
R       sll     Rdest, Rsrc, shamt			000000
R       srl     Rdest, Rsrc, shamt			000010
R       and     Rdest, Rsrc1, Rsrc2			100100
I       andi    Rdest, Rsrc, imm			001100
R       or      Rdest, Rsrc1, Rsrc2			100101
I       ori     Rdest, Rsrc, imm			001101
I       lui     Rdest, imm					001111
R       slt     Rdest, Rsrc1, Rsrc2			101010
I       beq     Rsrc1, Rsrc2, raddr			000100
I       bne     Rsrc1, Rsrc2, raddr			000101
J       j       address						000010
J       jal     address						000011
R       jr      Rsrc						001000
I       lw      Rdest, offset (Radd)		100011
I       sw      Rsrc, offset (Radd)			101011
*/
void simulateInstr (Computer mips, unsigned int instr, int *changedReg, int *changedMem) {
	int opcode,rs,rt,rd,shamt,funct,immediate,target_address;
	opcode=instr>>26;
	rs=(instr<<6)>>27;
	rt=(instr<<11)>>27;
	rd=(instr<<16)>>27;
	shamt=(instr<<21)>>27;
	funct=(instr<<26)>>26;
	immediate=(instr<<16)>>16;
	target_address=(instr<<6)>>6;	//首先取出备用的各种数据段
	
	if(opcode==0) //R格式
	{
		if(funct==33)			//addu    Rdest, Rsrc1, Rsrc2
		{
			mips->registers[rd]=mips->registers[rs]+mips->registers[rt];
			mips->pc = mips->pc + 4;
			if(rd==0)
				*changedReg = -1;
			else
				*changedReg = rd;
			*changedMem = -1;
		}
		else if(funct==35)		//subu    Rdest, Rsrc1, Rsrc2
		{
			mips->registers[rd]=mips->registers[rs]-mips->registers[rt];
			mips->pc = mips->pc + 4;
			if(rd==0)
				*changedReg = -1;
			else
				*changedReg = rd;
			*changedMem = -1;
		}
		else if(funct==0)		//sll     Rdest, Rsrc, shamt
		{
			mips->registers[rd]=mips->registers[rt]<<shamt;
			mips->pc = mips->pc + 4;
			if(rd==0)
				*changedReg = -1;
			else
				*changedReg = rd;
			*changedMem = -1;
		}
		else if(funct==2)		//srl     Rdest, Rsrc, shamt
		{
			mips->registers[rd]=mips->registers[rt]>>shamt;
			mips->pc = mips->pc + 4;
			if(rd==0)
				*changedReg = -1;
			else
				*changedReg = rd;
			*changedMem = -1;
		}
		else if(funct==36)		//and     Rdest, Rsrc1, Rsrc2
		{
			mips->registers[rd]=mips->registers[rs]&mips->registers[rt];
			mips->pc = mips->pc + 4;
			if(rd==0)
				*changedReg = -1;
			else
				*changedReg = rd;
			*changedMem = -1;
		}
		else if(funct==37)		//or      Rdest, Rsrc1, Rsrc2	
		{
			mips->registers[rd]=mips->registers[rs]|mips->registers[rt];
			mips->pc = mips->pc + 4;
			if(rd==0)
				*changedReg = -1;
			else
				*changedReg = rd;
			*changedMem = -1;
		}
		else if(funct==42)		//slt     Rdest, Rsrc1, Rsrc2	
		{
			if(mips->registers[rs]<mips->registers[rt])
				mips->registers[rd]=1;
			else
				mips->registers[rd]=0;
			mips->pc = mips->pc + 4;
			if(rd==0)
				*changedReg = -1;
			else
				*changedReg = rd;
			*changedMem = -1;
		}
		else if(funct==8)		//jr      Rsrc		
		{
			mips->pc = mips->registers[rs];
			*changedReg = -1;
			*changedMem = -1;
		}
		else
		{
			exit(0);
		}
	}
	//I格式
	else if(opcode==9)		//addiu   Rdest, Rsrc1, imm
	{
		if(immediate>32768) //2^15
			immediate-=65536;  //2^16	符号扩展

		mips->registers[rt]=mips->registers[rs]+immediate;
		mips->pc = mips->pc + 4;
		if(rt==0)
				*changedReg = -1;
			else
				*changedReg = rt;

		*changedMem = -1;
	}
	else if(opcode==12)		//andi    Rdest, Rsrc, imm			
	{
		mips->registers[rt]=mips->registers[rs]&immediate;
		mips->pc = mips->pc + 4;
		if(rt==0)
				*changedReg = -1;
			else
				*changedReg = rt;
		*changedMem = -1;
	}
	else if(opcode==13)		//ori     Rdest, Rsrc, imm			
	{
		mips->registers[rt]=mips->registers[rs]|immediate;
		mips->pc = mips->pc + 4;
		if(rt==0)
				*changedReg = -1;
			else
				*changedReg = rt;
		*changedMem = -1;
	}
	else if(opcode==15)		//lui     Rdest, imm				
	{
		mips->pc=mips->pc+4;
		mips->registers[rt]=immediate*65536;		//*2^16 扔向高16位，即每一位的幂值增加16
		if(rt==0)
				*changedReg = -1;
		else
				*changedReg = rt;
		*changedMem = -1;
	}
	else if(opcode==4)		//beq     Rsrc1, Rsrc2, raddr	
	{
		if(mips->registers[rs]==mips->registers[rt])
		{
			if(immediate>32768) //2^15
				immediate-=65536;  //2^16	符号扩展
			mips->pc=mips->pc+4+4*immediate;
			*changedReg = -1;
			*changedMem = -1;
		}
		else
		{
			mips->pc=mips->pc+4;
			*changedReg = -1;
			*changedMem = -1;
		}
	}
	else if(opcode==5)		//bne     Rsrc1, Rsrc2, raddr			
	{
		if(mips->registers[rs]!=mips->registers[rt])
		{
			if(immediate>32768) //2^15
				immediate-=65536;  //2^16	符号扩展
			mips->pc=mips->pc+4+4*immediate;
			*changedReg = -1;
			*changedMem = -1;
		}
		else
		{
			mips->pc=mips->pc+4;
			*changedReg = -1;
			*changedMem = -1;
		}
	}
	else if(opcode==35)		//lw      Rdest, offset (Radd)		
	{
		if(immediate>32768) //2^15
				immediate-=65536;  //2^16	符号扩展
		mips->registers[rt]=mips->memory[((mips->registers[rs]+immediate)-4194304)/4];	//(地址-0x00400000)/4=words  0x00400000=(4194304)DEC
		mips->pc=mips->pc+4;
		if(rt==0)
				*changedReg = -1;
			else
				*changedReg = rt;
		*changedMem = -1;
	}
	else if(opcode==43)		//sw      Rsrc, offset (Radd)			
	{
		if(immediate>32768) //2^15
				immediate-=65536;  //2^16	符号扩展
		mips->memory[(mips->registers[rs]+immediate-4194304)/4]=mips->registers[rt];	//(地址-0x00400000)/4=words  0x00400000=(4194304)DEC
		mips->pc=mips->pc+4;
		*changedReg = -1;
		*changedMem = mips->registers[rs]+immediate;		
	}
	//J格式
	else if(opcode==2)		//j       address				
	{
		target_address=((mips->pc>>28)<<28)+target_address*4;
		mips->pc=target_address;
		*changedReg = -1;
		*changedMem = -1;
	}
	else if(opcode==3)		//jal     address
	{
		target_address=((mips->pc>>28)<<28)+target_address*4;
		mips->registers[31]=mips->pc+4;
		mips->pc=target_address;
		*changedReg = 31;
		*changedMem = -1;
	}
	else
	{  
		exit(0);
	}
}
