// Author: Nina Chepovska
// LC2200 Simulator
// Assembler

#include <stdio.h>
#include <stdlib.h>

int main() {
   char instruction[18] = "add $v0, $a0, $a1";
   char opcode[4];
   char operand1[6];
   char operand2[6];
   char operand3[6];
   
   sscanf(instruction, "%s %s %s %s", opcode, operand1, operand2, operand3);

   printf("Opcode: %s\nOperand 1: %s\nOperand 2: %s\nOperand 3: %s\n", opcode, operand1, operand2, operand3);

   return 0;
}
