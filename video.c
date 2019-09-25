#include "video.h"

void clearVideo(int color)
{
	//Invalid Color
	if(color > 0x0F)
		return;
	
	//Copy color value to upper bits	
	color += (color*0x10);
		
	//Disable video
	videoDisable();
		
	for(int i = 0; i < (T_PIXEL/2); i++)
		writeByteVram(i,color);
		
}

void writeByteVram(int addr, int data)
{
	//write bus adrr
	addrBusWrite(addr);
	
	//write data
	dataBusWrite(data);
	
	//Delay 5 cycles
	delay(5);
	
	//Start writing
	vramChipSelectEnable();
	vramWriteEnable();
	
	//Delay 5 cycles
	delay(5);
	
	//End writing
	vramWriteDisable();
	vramChipSelectDisable();
	
	
}

void videoDisable()
{
	//Disable ram Output
	vramOutputDisable();
	
	//Disable CPLD Counter output
	addrCounterDisable();
	
	//
	vramChipSelectDisable();	
	
}
