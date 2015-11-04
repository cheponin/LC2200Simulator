#include <stdlib.h>
#include <stdio.h>
#define OP_COUNT 4
#define REG_COUNT 16

int REGISTER_FILE[16];
int Rx;
int Ry;
int Rz;
int A;
int B;
typedef enum REGS { ZERO, AT, V0, A0, A1, A2, T0, T1, T2, S0, S1, S2, K0, SP, FP, FA} REGS;
typedef enum OPS{NOP, ADD1, ADD2, ADD3} OPS; /*These are microinstruction for testing state machine*/
//typedef enum OPS{NOP, ADD, NAND, LW, SW, JALR, BEQ}; <--- These are the actual instructions
typedef void (*func)();
void ifetch1(void);
void ifetch2(void);
void ifetch3(void);
void add1();
void add2();
void add3();
void nand1();
void nand2();
void nand3();
void print_status();
typedef struct TRANSITION
{
    REGS current_reg;
    func operation;
}TRANSITION;
TRANSITION table[OP_COUNT][REG_COUNT] =
{ 
/*NOP*/              {{ZERO, 0},{AT, 0}, {V0, 0}, {A0, 0},
                      {A1, 0},{A2, 0},{T0, 0}, {T1, 0},
                      {T2, 0}, {S0, 0}, {S1, 0}, {S2, 0},
                      {K0, 0}, {SP, 0}, {FP, 0}, {FA, 0}},

/*add1*/             {{ZERO, add1},{AT, add1}, {V0, add1}, {A0, add1},
                      {A1,add1}, {A2, add1}, {T0, add1}, {T1, add1},
                      {T2, add1}, {S0, add1}, {S1, add1}, {S2, add1},
                      {K0, add1}, {SP, add1}, {FP, add1}, {FA, add1}},

/*add2*/             {{ZERO, add2},{AT, add2}, {V0, add2}, {A0, add2},
                     {A1, add2}, {A2, add2}, {T0, add2}, {T1, add2},
                     {T2, add2}, {S0, add2}, {S1, add2}, {S2, add2},
                     {K0, add2}, {SP, add2}, {FP, add2}, {FA, add2}},

/*add3*/             {{ZERO, add3},{AT, add3}, {V0, add3}, {A0, add3},
                     {A1,add3},{A2, add3},{T0, add3}, {T1, add3},
                     {T2, add3},{S0, add3}, {S1, add3}, {S2, add3}, 
                     {K0, add3},{SP, add3}, {FP, add3}, {FA, add3}}
};
void add1(){
    printf("Add1");    
//Ry = (int*)REGISTER_FILE[someReg];
    A = Ry;
}
void add2(){
    printf("Add2");
   // Rz = (int*)REGISTER_FILE[someReg];
  B = Rz;
}
void add3(){
  //  Rx = (int*)REGISTER_FILE[someReg];
   Rx = A + B;
    printf("Add3");
}
void print_status(){
    int i =0;
    for(i =0; i < 15; i++){
        printf("Register%d: %d\n", i, REGISTER_FILE[i]);
    }
    printf("Rx:%d, Ry:%d, Rz%d", Rx, Ry, Rz);
    
}
int main(void){
    REGS reg1 = V0;
   REGS reg2 = AT;
    REGS reg3 = S2;
    //REGISTER_FILE[V0] = 5;
   //Rx = 0;
   // Ry = 4;
    //Rz = 12;
    
    REGISTER_FILE[reg1] = 12;
    REGISTER_FILE[reg2] = 3;
    REGISTER_FILE[reg3] = 0;
    print_status();
    Rx = REGISTER_FILE[reg1];
    Ry = REGISTER_FILE[reg2];
    Rz = REGISTER_FILE[reg3];
    OPS instruction_queue[3] = {ADD1,ADD2,ADD3};
    int instruction_index =0;
    for(; instruction_index < 3; instruction_index++){
        OPS inst = instruction_queue[instruction_index];
        table[inst][reg1].operation();
        //reg1 = table[inst][reg1].current_reg;
            
    }
    REGISTER_FILE[reg1] = Rx;
    REGISTER_FILE[reg2] = Ry;  
    REGISTER_FILE[reg3] = Rz;
    print_status();

    return 0;
}


    
 
