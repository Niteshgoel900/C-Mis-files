/*
Group Members:
  Eshika Sahay
  Anjali Ramsahai
  Nitesh Goel
*/

#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{
    // converts the control signal to integer
    int x = (int)(ALUControl);
    switch(x)
    {
      case 0:
        *ALUresult = A + B;
        break;
      case 1:
        *ALUresult = A - B;
        break;
      case 2:
        if ((signed)A < (signed)B)
          *ALUresult = 1;
        else
          *ALUresult = 0;
        break;
      case 3:
        if (A < B)
          *ALUresult = 1;
        else
          *ALUresult = 0;
        break;
      case 4:
        *ALUresult = A && B;
        break;
      case 5:
        *ALUresult = A || B;
        break;
      case 6:
        *ALUresult = B << 16;
        break;
      case 7:
        *ALUresult = !A;
    }

    if (*ALUresult == 0)
    {
      *Zero = 1;
    }
    else
    {
      *Zero = 0;
    }
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
    unsigned position = PC >> 2;

    if (PC % 4 == 0)
    {
        *instruction = Mem[position];
        return 0;
    }
    return 1;
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    *op     = (instruction & 0xFC000000) >> 26;
    *r1     = (instruction & 0x03E00000) >> 21;
    *r2     = (instruction & 0x001F0000) >> 16;
    *r3     = (instruction & 0x0000F800) >> 11;
    *funct  =  (instruction & 0x0000003F);
    *offset =  (instruction & 0x0000FFFF);
    *jsec   =  (instruction & 0x03FFFFFF);
}


/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

  switch(op)
  {
     //R Type
     case 0:
         controls->RegDst = 1;
         controls->Jump = 0;
         controls->Branch = 0;
         controls->MemRead = 0;
         controls->MemtoReg = 0;
         controls->ALUOp = 7;
         controls->MemWrite = 0;
         controls->ALUSrc = 0;
         controls->RegWrite = 1;
         break;

     //I Type
     //beq
     case 4:
         controls->RegDst = 2;
         controls->Jump = 0;
         controls->Branch = 1;
         controls->MemRead = 0;
         controls->MemtoReg = 2;
         controls->ALUOp = 1;
         controls->MemWrite = 0;
         controls->ALUSrc = 0;
         controls->RegWrite = 0;
         break;
     //addi
     case 8:
         controls->RegDst = 0;
         controls->Jump = 0;
         controls->Branch = 0;
         controls->MemRead = 0;
         controls->MemtoReg = 0;
         controls->ALUOp = 0;
         controls->MemWrite = 0;
         controls->ALUSrc = 1;
         controls->RegWrite = 1;
         break;
     //slt
     case 10:
         controls->RegDst = 0;
         controls->Jump = 0;
         controls->Branch = 0;
         controls->MemRead = 0;
         controls->MemtoReg = 0;
         controls->ALUOp = 2;
         controls->MemWrite = 0;
         controls->ALUSrc = 1;
         controls->RegWrite = 1;
         break;
     //sltu
     case 11:
         controls->RegDst = 0;
         controls->Jump = 0;
         controls->Branch = 0;
         controls->MemRead = 0;
         controls->MemtoReg = 0;
         controls->ALUOp = 3;
         controls->MemWrite = 0;
         controls->ALUSrc = 1;
         controls->RegWrite = 1;
         break;
     //lw
     //lui
     case 15:
         controls->RegDst = 0;
         controls->Jump = 0;
         controls->Branch = 0;
         controls->MemRead = 0;
         controls->MemtoReg = 0;
         controls->ALUOp = 6;
         controls->MemWrite = 0;
         controls->ALUSrc = 1;
         controls->RegWrite = 1;
         break;
     case 35:
         controls->RegDst = 0;
         controls->Jump = 0;
         controls->Branch = 0;
         controls->MemRead = 1;
         controls->MemtoReg = 1;
         controls->ALUOp = 0;
         controls->MemWrite = 0;
         controls->ALUSrc = 1;
         controls->RegWrite = 1;
         break;
     //sw
     case 43:
         controls->RegDst = 2;
         controls->Jump = 0;
         controls->Branch = 0;
         controls->MemRead = 0;
         controls->MemtoReg = 2;
         controls->ALUOp = 0;
         controls->MemWrite = 1;
         controls->ALUSrc = 1;
         controls->RegWrite = 0;
         break;

     //J Type
     //Jump
     case 2:
         controls->RegDst = 0;
         controls->Jump = 1;
         controls->Branch = 0;
         controls->MemRead = 0;
         controls->MemtoReg = 0;
         controls->ALUOp = 0;
         controls->MemWrite = 0;
         controls->ALUSrc = 0;
         controls->RegWrite = 0;
         break;
    //End J Type

     default:
         return 1;
    }

    return 0;
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    //shift right 15 places to get the sign bit
    unsigned n = offset >> 15;
    //if the number is negative, extend 1s
    if(n == 1)
        *extended_value = offset | 0xFFFF0000;
    //extend 0s
    else
        *extended_value = offset & 0x0000FFFF;
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{
    if (ALUSrc == 1)
    {
        data2 = extended_value;
    }

    if (ALUOp == 7)
    {
    	switch(funct)
      {
	    	// add
	    	case 32:
	    		ALUOp = 0;
	    		break;
	    	// subtract
	    	case 34:
	    		ALUOp = 1;
	    		break;
	    	// set less than signed
	    	case 42:
	    		ALUOp = 2;
	    		break;
	    	// set less than unsigned
	    	case 43:
	    		ALUOp = 3;
	    		break;
	    	// and
	    	case 36:
	    		ALUOp = 4;
	    		break;
	    	// or
	    	case 37:
	    		ALUOp = 5;
	    		break;
	    	// shift left
	    	case 38:
	    		ALUOp = 6;
	    		break;
	    	// not
	    	case 39:
	    		ALUOp = 7;
	    		break;
	    	// halt
	    	default:
	    		return 1;
	    }
	    ALU(data1, data2, ALUOp, ALUresult, Zero);
    }

    else
    {
    	ALU(data1, data2, ALUOp, ALUresult, Zero);
    }

    return 0;

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{
    if(MemRead || MemWrite)
    {
      // if alligned
      if(ALUresult % 4 != 0)
      {
        return 1;
      }
    }

    if(MemRead == 1)
    {
      // read
      *memdata = Mem[ALUresult >> 2];
    }
    else if(MemWrite == 1)
    {
      // write
      Mem[ALUresult >> 2] = data2;
    }
    return 0;
}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{
  if (RegWrite == 1)
  {
      if (MemtoReg == 1)
      {
          // store memory in r2
          if (RegDst == 0)
              Reg[r2] = memdata;
          // store memory in r3
          else
              Reg[r3] = memdata;
      }
      else
      {
          // store ALUresult in r2
          if (RegDst == 0)
              Reg[r2] = ALUresult;
          // store ALUresult in r3
          else
              Reg[r3] = ALUresult;
      }
  }
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{
    *PC = *PC + 4;

    // if jumping then go to jump register and align the word by multiplying by 4
    if(Jump == 1)
    {
      *PC = jsec << 2 | (*PC & 0xF0000000);
    }
    // if branching and have zero then add the aligned extended value
    if(Branch == 1 && Zero == 1)
    {
      *PC = *PC + (extended_value << 2);
    }
}
