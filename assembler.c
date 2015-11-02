// Author: Nina Chepovska
// LC2200 Simulator
// Assembler

#include <stdio.h>
#include <stdlib.h>

int main() {

   FILE *inputFile = fopen("input.txt", "r");
   char opcode[5];
   char operand1[6];
   char operand2[6];
   char operand3[6];
   
   fgets(opcode, 5, inputFile);
   //fgetc(inputFile);
   fgets(operand1, 4, inputFile);
   fgetc(inputFile);
   fgetc(inputFile);
   fgets(operand2, 4, inputFile);
   fgetc(inputFile);
   fgetc(inputFile);
   fgets(operand3, 4, inputFile);

   printf("Opcode: %s\nOperand 1: %s\nOperand 2: %s\nOperand 3: %s\n", opcode, operand1, operand2, operand3);
   fclose(inputFile);

   return 0;
}
