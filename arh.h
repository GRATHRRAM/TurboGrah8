#include <raylib.h>
#include <stdint.h>


void WriteBus(uint8_t *RAM, Color *Screen, uint16_t adress, uint16_t value);
uint16_t ReadBus(uint8_t *RAM, Color *Screen, uint16_t adress);
void Interpreter(uint8_t *RAM, uint8_t *REGS, Color *Screen, uint8_t instruction[4]);