#include <stdint.h>

//registers
#define nl  0x0 //null regiser (do not exist!) (returns 0)
#define A   0x1
#define B   0x2
#define C   0x3
#define D   0x4
#define E   0x5
#define F   0x6
#define G   0x7
#define H   0x8
#define cp  0x9 //if return val 
#define icl  0xA //instruction counter
#define ich 0xB
#define bs  0xC //bus none/read/write

void _imm (uint8_t *REGS,uint8_t value,  uint8_t return_adress);                   //0x00  Immidiet value
void _mov (uint8_t *REGS,uint8_t address1,uint8_t return_adress);                  //0x01  Move val
void _add (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x02  add
void _sub (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x03  substract
void _mul (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x04  multiply
void _div (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x05  divide
void _not (uint8_t *REGS,uint8_t address1,uint8_t return_adress);                  //0x06  not gate
void _and (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x07  and gate
void _nand(uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x08  nand gate
void _or  (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x09  or gate
void _nor (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x0A  nor gate
void _xor (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x0B  xor gate
void _nxor(uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x0C  nxor gate
void _shl (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x0D  shift bit left
void _shr (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress);//0x0E  shift bit right
void _cmp (uint8_t *REGS,uint8_t address1,uint8_t address2);                       //0x0F  if(reg_Val == reg2_val) cp = true else cp = false
void _big (uint8_t *REGS,uint8_t address1,uint8_t address2);                       //0x10  if(reg_Val > Reg2_val)  cp = true else cp = false
void _sml (uint8_t *REGS,uint8_t address1,uint8_t address2);                       //0x11  if(reg_Val < Reg2_val)  cp = true else cp = false
void _jmp (uint8_t *REGS,uint8_t address1,uint8_t address2);                       //0x12  ic = reg_val(0x00ff) + reg2_val(0xff00)
void _jiz (uint8_t *REGS,uint8_t address1,uint8_t address2);                       //0x13  if(cp == 0) jmp
void _jnz (uint8_t *REGS,uint8_t address1,uint8_t address2);                       //0x14  if(cp != 0) jmp



void _imm (uint8_t *REGS,uint8_t value,  uint8_t return_adress)                    {REGS[return_adress] = value;}
void _mov (uint8_t *REGS,uint8_t address1,uint8_t return_adress)                   {REGS[return_adress] = REGS[address1];}
void _add (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] + REGS[address2];}
void _sub (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] - REGS[address2];}
void _mul (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] * REGS[address2];}
void _div (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] / REGS[address2];}
void _not (uint8_t *REGS,uint8_t address1,uint8_t return_adress)                   {REGS[return_adress] = (uint8_t) ~REGS[address1];}
void _and (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] & REGS[address2];}
void _nand(uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) ~(REGS[address1] & REGS[address2]);}
void _or  (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] | REGS[address2];}
void _nor (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) ~(REGS[address1] | REGS[address2]);}
void _xor (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] ^ REGS[address2];}
void _nxor(uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) ~(REGS[address1] ^ REGS[address2]);}
void _shl (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] >> REGS[address2];}
void _shr (uint8_t *REGS,uint8_t address1,uint8_t address2, uint8_t return_adress) {REGS[return_adress] = (uint8_t) REGS[address1] << REGS[address2];}

void _cmp (uint8_t *REGS,uint8_t address1,uint8_t address2)          {if(REGS[address1] == REGS[address2]) REGS[cp] = 1;else REGS[cp] = 1;}
void _big (uint8_t *REGS,uint8_t address1,uint8_t address2)          {if(REGS[address1] > REGS[address2]) REGS[cp] = 1;else REGS[cp] = 1;}
void _sml (uint8_t *REGS,uint8_t address1,uint8_t address2)          {if(REGS[address1] < REGS[address2]) REGS[cp] = 1;else REGS[cp] = 1;}
void _jmp (uint8_t *REGS,uint8_t address1,uint8_t address2)          {REGS[icl] = address1; REGS[ich] = address2;}
void _jiz (uint8_t *REGS,uint8_t address1,uint8_t address2)          {if(cp==0) {REGS[icl] = address1;REGS[ich]=address2;}}
void _jnz (uint8_t *REGS,uint8_t address1,uint8_t address2) 		 {if(cp!=0) {REGS[icl] = address1;REGS[ich]=address2;}}