//#include "proj3.h"
#include "stdafx.h"
#include "computer.h"
#include "proj1.h"
/*
 *  Return an initialized computer with the stack pointer set to the
 *  address of the end of data memory, the remaining registers initialized
 *  to zero, and the instructions read from the given file.
 *  The other arguments all govern how the program interacts with the user.
 */ 
Computer newComputer (FILE* filein, int printingRegisters, int printingMemory, int debugging, int interactive) {
    int k;
    unsigned int instr;
    Computer mips = (Computer) malloc (sizeof(struct SimulatedComputer));
    
    for (k=0; k<32; k++) mips->registers[k] = 0;	//以零值初始化每一个寄存器
    
    /* stack pointer starts at end of data area and grows down */
    mips->registers[29] = 0x00400000 + (MAXNUMINSTRS+MAXNUMDATA)*4;		//最大指令数+最大数据数

    k = 0;	//临时变量，表示以读取的指令数
    while (1) {
        instr = 0;
        unsigned char temp = 0;
        int i;
        for (i = 0; i < 4; i++) {
            if (!fread(&temp, 1, 1, filein)) {
                i = -1;
                break;
            }	//从文件流filein中读取文件信息，读入一个1字节的字符串，存入temp中
				//读文件直至文件结束
            instr |= temp << (i << 3);
        }
        if (i == -1) break;		//如果读取结束则跳出循环
        
		mips->memory[k] = instr;
        k++;			//将每一条指令写入内存

        if (k > MAXNUMINSTRS) {
            fprintf (stderr, "Program too big (%d instructions, only %d allowed).\n", k, MAXNUMINSTRS);
            exit (1);		//如果指令过多则显示提示信息
        }
    }

    mips->printingRegisters = printingRegisters;
    mips->printingMemory = printingMemory;
    mips->interactive = interactive;
    mips->debugging = debugging;
    return mips;
}

/*
 *  Run the simulation.
 */
void simulate (Computer mips) {
    char s[10];  /* used for handling interactive input */
    unsigned int instr;
    int changedReg, changedMem;

    mips->pc = 0x00400000;
    while (1) {
        if (mips->interactive) {
            printf ("> ");
            fgets(s, 10, stdin);	//将stdin文件流中的10个字节的字符串存储至s中
            if (s[0] == 'q') return;
        }

        instr = contents (mips, mips->pc);
        printf ("Executing instruction at %8.8x: %8.8x\n", mips->pc, instr);
		
		printf ("\t%s\n", disassembled (instr, mips->pc));
        simulateInstr (mips, instr, &changedReg, &changedMem);
        printInfo (mips, changedReg, changedMem);
    }
}

/*
 *  Print relevant information about the state of the computer.
 *  changedReg is the index of the register changed by the instruction
 *  being simulated.  If changedReg is -1, no register was updated by
 *  the simulated instruction, i.e. it was a branch, a jump, or a store).
 *  changedMem is the address of the memory location changed by the
 *  simulated instruction.  For anything but a store, changedMem will be -1.
 *  Previously initialized flags indicate whether to print all the
 *  registers or just the one that changed, and whether to print
 *  all the nonzero memory or just the memory location that changed.
 */
void printInfo (Computer mips, int changedReg, int changedMem) {
    int k, addr;
    printf ("New pc = %8.8x\n", mips->pc);
    if (!mips->printingRegisters && changedReg == -1) printf ("No register was updated.\n");
    else if (!mips->printingRegisters) printf ("Updated r%d to %8.8x\n", changedReg, mips->registers[changedReg]);
    else {
        for (k=0; k<32; k++) {
            printf ("r%2d: %8.8x  ", k, mips->registers[k]);
            if ((k+1)%4 == 0) printf ("\n");
        }
    }

    if (!mips->printingMemory && changedMem == -1) printf ("No memory location was updated.\n");
    else if (!mips->printingMemory) printf ("Updated memory at address %8.8x to %8.8x\n", changedMem, contents (mips, changedMem));
    else {
        printf ("Nonzero memory\n");
        printf ("ADDR     CONTENTS\n");

        for (addr = 0x00400000+(MAXNUMINSTRS << 2); addr < 0x00400000+((MAXNUMINSTRS+MAXNUMDATA) << 2); addr = addr+4) {
            if (contents (mips, addr) != 0) printf ("%8.8x  %8.8x\n", addr, contents (mips, addr));
        }
    }
    printf ("\n");
}

/*
 *  Return the contents of memory at the given address.
 */
unsigned int contents (Computer mips, int addr) {
    int index = (addr-0x00400000)/4;
    if (((addr & 0x3) != 0) || (index < 0) || (index >= (MAXNUMINSTRS+MAXNUMDATA))) {
        printf("Invalid Address: %8.8x", addr);
        exit(0);
    }
    return mips->memory[index];
}
