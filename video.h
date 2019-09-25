#ifndef VIDEO_H
#define VIDEO_H

//Screen resolution
#define SCR_HEIGHT 220
#define SCR_LENGTH 256

#define T_PIXEL 220*256

//Control RAM's OE signal
#define vramOutputEnable() PA2 = 0x00
#define vramOutputDisable() PA2 = 0xFF

//Control RAM's CS signal
#define vramChipSelectEnable() PA3 = 0x00
#define vramChipSelectDisable() PA3 = 0xFF

//Control RAM's WE signal
#define vramWriteEnable() PA4 = 0x00
#define vramWriteDisable() PA4 = 0xFF

//Control addr lines
//Addr lines controled by CPLD
#define addrCounterEnable() PA5 = 0xFF;
//Addr lines controles by MCU (CPLD lines as tristate)
#define addrCounterDisable() PA5 = 0x00;

//Display a solid color on entire screen
void clearVideo(int color);

//White Single byte to vram
void writeByteVram(int addr, int data);

//Disable video and free bus acesses
void videoDisable();



#endif
