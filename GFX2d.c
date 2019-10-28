#include "misc.h"

void drawSprite(sprite* sp)
{
	//Disable video
	videoDisable();
	
	//Enable data bus
	enableDataBus();

	//Enable addr bus
	enableAddrBus();
	
	
	for(int i = 0; i < sp->size_x;i++)
		for(int j = 0; j < sp->size_y; j+=2)
		{
			int addr = ((i+sp->pos.x) + (((j+sp->pos.y)/2)*0x100));
			
			
			writeByteVram(addr,(sp->bit_map[j+1][i]*0x10) + sp->bit_map[j][i]);	
			
		}


		
	videoEnable();
	
	
}

void drawImage(int size_x,int size_y,const int bit_map[size_y][size_x],position pos)
{
	//Disable video
	videoDisable();
	
	//Enable data bus
	enableDataBus();

	//Enable addr bus
	enableAddrBus();
	
	
	for(int i = 0; i < size_x;i++)
		for(int j = 0; j < size_y; j+=2)
		{
			int addr = ((i+pos.x) + (((j+pos.y)/2)*0x100));
			
			
			writeByteVram(addr,(bit_map[j+1][i]*0x10) + bit_map[j][i]);	
			
		}


		
	videoEnable();
	
	
}

void drawPixel(int addr,int color)
{
	
	//Disable video
	videoDisable();
	
	//Enable data bus
	enableDataBus();

	//Enable addr bus
	enableAddrBus();
	
	
	//int addr = (x + ((y/2)*0x100));
	
	//if(y%2)
	//{
	//	color = (color*0x10);
	//}
	
	writeByteVram(addr,color);
	
	videoEnable();
	
	
}

void copySprite(sprite* sp_s,sprite* sp_d)
{
	//Copy bit map
	for(int i = 0; i < sp_s->size_x;i++)
		for(int j = 0; j < sp_s->size_y; j++)
			sp_d->bit_map[j][i] = sp_s->bit_map[j][i];
	
	//Copy size		
	sp_d->size_x = sp_s->size_x;
	sp_d->size_y = sp_s->size_y;
	
	//Copy position
	sp_d->pos.x = sp_s->pos.x;
	sp_d->pos.y = sp_s->pos.y;
	
}


void spritInit(sprite *sp, int size_x,int size_y,const int bitmap[size_y][size_x])
{
	//start position
	sp->pos.x = 0;
	sp->pos.y = 0;
	
	//Sprite size		
	sp->size_x = size_x;
	sp->size_y = size_y;
	
	//Copy bitmap
	for(int i = 0; i < size_x; i++)
		for(int j = 0; j < size_y; j++)
			sp->bit_map[j][i] = bitmap[j][i];
	
	
	
}

//Move Sprite
void moveSprite(sprite *sp,position new_pos)
{
	
	//Disable video
	videoDisable();
	
	//Enable data bus
	enableDataBus();

	//Enable addr bus
	enableAddrBus();
	
	//Clear Sprite image
	for(int i = 0; i < sp->size_x;i++)
		for(int j = 0; j < sp->size_y; j+=2)
		{
			int addr = ((i+sp->pos.x) + (((j+sp->pos.y)/2)*0x100));
			
			
			writeByteVram(addr,0x00);	
			
		}


	//Set new position
	sp->pos.x = new_pos.x;
	sp->pos.y = new_pos.y;
	
	
	//Redraw Sprite
	for(int i = 0; i < sp->size_x;i++)
		for(int j = 0; j < sp->size_y; j+=2)
		{
			int addr = ((i+sp->pos.x) + (((j+sp->pos.y)/2)*0x100));
			
			
			writeByteVram(addr,(sp->bit_map[j+1][i]*0x10) + sp->bit_map[j][i]);	
			
		}



		
	videoEnable();
	
}
