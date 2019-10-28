#ifndef GFX2D_H
#define GFX2D_H

#include "misc.h"


typedef struct
{
	int x,y;
	
}position;

//Sprite bitmap form: bit_map[y][x]
//
typedef struct
{
	int size_x;
	int size_y;
	
	position pos;
	
	char bit_map [8][13];
	
}sprite;

//Draw sprite on screen
void drawSprite(sprite* sp);

//Draw a picture to the screeen
void drawImage(int size_x,int size_y,const int bit_map[*][*],position pos);

//Draw a single pixel on screen
void drawPixel(int addr,int color);

//Copy spite
void copySprite(sprite* sp_s,sprite* sp_d);

//Sprite Initialization
void spritInit(sprite *sp,int size_x,int size_y,const int bitmap[*][*]);

//Move Sprite
void moveSprite(sprite *sp,position pos);


#endif
