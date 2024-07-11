#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>
#include <stdio.h>
#include <string.h>
#include "arh.h"

#define Screen_res 255*255

#define Ram_Size 4096 //kB  
#define Ram_Size_Bytes Ram_Size / 8
//0x0000 -> 0x0200 Ram
//0x0201 Screen_PixelPosition
//0x0202 Screen_PixelColorRed
//0x0203 Screen_PixelColorBlue
//0x0204 Screen_PixelColorGreen
//0x0205 Keyboard

void Get_Instruction(FILE *hxd, uint8_t *REGS, char buff[16]);

void Icrement_ic(uint8_t *REGS);

int main(void) {
	InitWindow(1280, 720, "TurboGrah8");

	Camera2D cam = {0};
	cam.zoom = 1;

 	uint8_t RAM[Ram_Size_Bytes];
 	uint8_t REGS[0x14];
 	Color Screen[Screen_res];

 	FILE *hxd = fopen("test.hxd", "r");
 	char buff[16];

	while(!WindowShouldClose()) {
		
		system("clear");
		for(uint16_t i = 0; i < 0x14; ++i) {
			printf("REG $%hx; Val $%hx;\n",i,REGS[i]);
		}


		Get_Instruction(hxd,REGS,buff);
		printf("yo %s\n", buff);
		char *buff2;
    	buff2 = strtok( buff, " ");
    	uint8_t inst[4];

    	inst[0] = (uint8_t) strtol(buff2, NULL, 16);
        buff2 = strtok( NULL, " ");
        inst[1] = (uint8_t) strtol(buff2, NULL, 16);
        buff2 = strtok( NULL, " ");
        inst[2] = (uint8_t) strtol(buff2, NULL, 16);
        buff2 = strtok( NULL, " ");
        inst[3] = (uint8_t) strtol(buff2, NULL, 16);
        buff2 = strtok( NULL, " ");

        DoInstruction(RAM,REGS,Screen,inst);
    	

		Icrement_ic(REGS);

		

		BeginDrawing();
		BeginMode2D(cam);

		DrawLine(0,0,255,255,RED);

		EndMode2D();
		EndDrawing();
	}

	fclose(hxd);
	return 0;
}

void Get_Instruction(FILE *hxd, uint8_t *REGS, char buff[16]) {
	for(uint16_t i=0;fgets(buff, 16, hxd);++i) 
		if(i == u8TOu16(REGS[ich], REGS[icl])) return;
	buff = "0 0 0 0";
}

void Icrement_ic(uint8_t *REGS) {
	uint16_t val = u8TOu16(REGS[ich], REGS[icl]);
	val++;
	REGS[icl] = (uint8_t) val & 0x00FF;
	REGS[ich] = (uint8_t) (val & 0xFF00) >> 8;
}