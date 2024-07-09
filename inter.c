#include <stdint.h>
#include <raylib.h>
#include "cpu.h"
//bus addresing is 16bit 0x0000 -> 0xFFFF

void WriteBus(uint8_t *RAM, Color *Screen, uint16_t adress, uint16_t value);
uint16_t ReadBus(uint8_t *RAM, Color *Screen, uint16_t adress);
void Interpreter(uint8_t *RAM, uint8_t *REGS, Color *Screen, uint8_t instruction[4]);

uint8_t u16TOu8(uint16_t value);

void WriteBus(uint8_t *RAM, Color *Screen, uint16_t adress, uint16_t value) {
	if(adress <= 0x0200) RAM[adress] = u16TOu8(value);
}

uint16_t ReadBus(uint8_t *RAM, Color *Screen, uint16_t adress) {
	if(adress <= 0x0200) return RAM[adress];
	return 0;
}

void Interpreter(uint8_t *RAM, uint8_t *REGS, Color *Screen, uint8_t instruction[4]) {
	

}

uint8_t u16TOu8(uint16_t value) {
	return value & 0x00FF;
}