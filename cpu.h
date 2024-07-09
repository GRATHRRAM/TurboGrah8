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
#define ic  0xA //instruction counter
#define ic2 0xB
#define bs  0xC //bus none/read/write


#define m_imm  0x0
#define m_mov  0x1
#define m_add  0x2
#define m_sub  0x3
#define m_mul  0x4
#define m_div  0x5
#define m_not  0x6
#define m_and  0x7
#define m_nand 0x8
#define m_or   0x9
#define m_nor  0xA
#define m_xor  0xB
#define m_nxor 0xC
#define m_shl  0xD
#define m_shr  0xE
#define m_cmp  0xF
#define m_big  0x10
#define m_sml  0x11
#define m_jmp  0x12
#define m_jiz  0x13
#define m_jnz  0x14

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