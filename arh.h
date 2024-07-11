#include <raylib.h>
#include <stdint.h>
#include "cpu.h"

void WriteBus(uint8_t *RAM, Color *Screen, uint16_t adress, uint16_t value);
uint16_t ReadBus(uint8_t *RAM, Color *Screen, uint16_t adress);
void DoInstruction(uint8_t *RAM, uint8_t *REGS, Color *Screen, uint8_t instruction[4]);
uint16_t u8TOu16(uint8_t high, uint8_t low);