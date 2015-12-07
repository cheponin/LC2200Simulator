// Author: Nina Chepovska
// LC2200 Simulator
// Assembler

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

   FILE *input = fopen("input.txt", "r");
   char* instruction[31];
   char c = 0;
   int i = 0, j = 0;
   
   while (!feof(input)) {
      do {
         c = fgetc(input);
         instruction[i] = &c;
         i++;
      } while (c != '\n');
      instruction[i] = '\0';
      // Send string to FSM
      for (i = 0; i < 31; i++) {
          instruction[i] = ' ';
      }
      i = 0;
      j++;
      printf("While %d\n", j);
   }

   printf("End");

   return 0;
}

















/*
   typedef enum {ZERO, AT, V0, A0, A1, A2, T0, T1, T2, S0, S1, S2, K0, SP, FP, FA} register;
   typedef enum {NOP, ADD, NAND, LW, SW, JALR, BEQ} operation;

int main() {

   FILE *inputFile = fopen("input.txt", "r");
   FILE *outputFile = fopen("output.txt", "w");

   char opcode[5];
   char operand1[6];
   char operand2[6];
   char operand3[6];
   
   fgets(opcode, 5, inputFile);
   fgets(operand1, 4, inputFile);
   fgetc(inputFile);
   fgetc(inputFile);
   fgets(operand2, 4, inputFile);
   fgetc(inputFile);
   fgetc(inputFile);
   fgets(operand3, 4, inputFile);

   int enumvals[4];

   operation op = ADD;

   if (strcmp(opcode, "add")) {
      op = ADD;
      enumvals[0] = ADD;
   } else if (strcmp(opcode, "nand")) {
      op = NAND;
   } else if (strcmp(opcode, "jalr")) {
      op = JALR;
   } else if (strcmp(opcode, "beq")) {
      op = BEQ;
   } else if (strcmp(opcode, "lw")) {
      op = LW;
   } else if (strcmp(opcode, "sw")) {
      op = SW;
   }

   register reg1;

   if (strcmp(operand1, "$zero")) {
      reg1 = ZERO;
   } else if (strcmp(operand1, "$a0")) {
      reg1 = A0;
   } else if (strcmp(operand1, "$a1")) {
      reg1 = A1;
   } else if (strcmp(operand1, "$a2")) {
      reg1 = A2;
   } else if (strcmp(operand1, "$v0")) {
      reg1 = V0;
   } else if (strcmp(operand1, "$t0")) {
      reg1 = T0;
   } else if (strcmp(operand1, "$t1")) {
      reg1 = T1;
   } else if (strcmp(operand1, "$t2")) {
      reg1 = T2;
   } else if (strcmp(operand1, "$s0")) {
      reg1 = S0;
   } else if (strcmp(operand1, "$s1")) {
      reg1 = S1;
   } else if (strcmp(operand1, "$s2")) {
      reg1 = S2;
   } else if (strcmp(operand1, "$at")) {
      reg1 = AT;
   } else if (strcmp(operand1, "$k0")) {
      reg1 = K0;
   } else if (strcmp(operand1, "$sp")) {
      reg1 = SP;
   } else if (strcmp(operand1, "$fp")) {
      reg1 = FP;
   } else if (strcmp(operand1, "$fa")) {
      reg1 = FA;
   }      
 
   register reg2;

   if (strcmp(operand1, "$zero")) {
      reg2 = ZERO;
   } else if (strcmp(operand1, "$a0")) {
      reg2 = A0;
   } else if (strcmp(operand1, "$a1")) {
      reg2 = A1;
   } else if (strcmp(operand1, "$a2")) {
      reg2 = A2;
   } else if (strcmp(operand1, "$v0")) {
      reg2 = V0;
   } else if (strcmp(operand1, "$t0")) {
      reg2 = T0;
   } else if (strcmp(operand1, "$t1")) {
      reg2 = T1;
   } else if (strcmp(operand1, "$t2")) {
      reg2 = T2;
   } else if (strcmp(operand1, "$s0")) {
      reg2 = S0;
   } else if (strcmp(operand1, "$s1")) {
      reg2 = S1;
   } else if (strcmp(operand1, "$s2")) {
      reg2 = S2;
   } else if (strcmp(operand1, "$at")) {
      reg2 = AT;
   } else if (strcmp(operand1, "$k0")) {
      reg2 = K0;
   } else if (strcmp(operand1, "$sp")) {
      reg2 = SP;
   } else if (strcmp(operand1, "$fp")) {
      reg2 = FP;
   } else if (strcmp(operand1, "$fa")) {
      reg2 = FA;
   } 

   register reg3;

   if (strcmp(operand1, "$zero")) {
      reg3 = ZERO;
   } else if (strcmp(operand1, "$a0")) {
      reg3 = A0;
   } else if (strcmp(operand1, "$a1")) {
      reg3 = A1;
   } else if (strcmp(operand1, "$a2")) {
      reg3 = A2;
   } else if (strcmp(operand1, "$v0")) {
      reg3 = V0;
   } else if (strcmp(operand1, "$t0")) {
      reg3 = T0;
   } else if (strcmp(operand1, "$t1")) {
      reg3 = T1;
   } else if (strcmp(operand1, "$t2")) {
      reg3 = T2;
   } else if (strcmp(operand1, "$s0")) {
      reg3 = S0;
   } else if (strcmp(operand1, "$s1")) {
      reg3 = S1;
   } else if (strcmp(operand1, "$s2")) {
      reg3 = S2;
   } else if (strcmp(operand1, "$at")) {
      reg3 = AT;
   } else if (strcmp(operand1, "$k0")) {
      reg3 = K0;
   } else if (strcmp(operand1, "$sp")) {
      reg3 = SP;
   } else if (strcmp(operand1, "$fp")) {
      reg3 = FP;
   } else if (strcmp(operand1, "$fa")) {
      reg3 = FA;
   }

   printf("Opcode: %s\nOperand 1: %s\nOperand 2: %s\nOperand 3: %s\n", opcode, operand1, operand2, operand3);

   fwrite(enumvals, sizeof(int), 4, outputFile);

   fclose(inputFile);

   return 0;
}
*/