#include <stdlib.h>
#include <stdint.h>
#include <raylib.h>
#include <stdio.h>
#include "arh.h"
#include "cpu.h"

#define Screen_res 255*255

#define Ram_Size 4096 //kB  
#define Ram_Size_Bytes Ram_Size / 8
//0x0000 -> 0x0200 Ram
//0x0201 Screen_PixelPosition
//0x0202 Screen_PixelColorRed
//0x0203 Screen_PixelColorBlue
//0x0204 Screen_PixelColorGreen
//0x0205 Keyboard



int main(void) {
	InitWindow(1280, 720, "TurboGrah8");

	Camera2D cam = {0};
	cam.zoom = 1;

 	uint8_t RAM[Ram_Size_Bytes];
 	Color Screen[Screen_res];

	while(!WindowShouldClose()) {
		/*
		system("clear");
		for(uint16_t i = 0,ii = 0; i < Ram_Size_Bytes; ++i) {
			printf("%hx ", RAM[i]);
			ii++;
			if(ii == 20) {
				ii = 0;
				putchar('\n');
			}
		}
		*/

		BeginDrawing();
		BeginMode2D(cam);

		DrawLine(0,0,255,255,RED);

		EndMode2D();
		EndDrawing();
	}

	return 0;
}// 