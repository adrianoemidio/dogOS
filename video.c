#include "misc.h"

//Clear video with a solid color
void clearVideo(int color)
{
	//Invalid Color
	if(color > 0x0F)
		return;
	
	//Copy color value to upper bits	
	color += (color*0x10);
		
	//Disable video
	videoDisable();
	
	//Enable data bus
	enableDataBus();

	//Enable addr bus
	enableAddrBus();
		
	for(int i = 0; i < (T_PIXEL/2); i++)
		writeByteVram(i,color);

	videoEnable();
		
}

//Write a single byte to VRAM
void writeByteVram(int addr, int data)
{
	
	//Disable output
	vramOutputDisable();
	
	//write bus adrr
	addrBusWrite(addr);
	
	//write data
	dataBusWrite(data);
	
	//Delay one cycles
	NOP();
	
	//Start writing
	vramChipSelectEnable();
	vramWriteEnable();
	
	//Delay one cycles
	NOP();
	
	//End writing
	vramWriteDisable();
	vramChipSelectDisable();
	
	
	
}

//Disable video and free bus for MCU writings
void videoDisable()
{
	//Disable ram Output
	vramOutputDisable();
	
	//Disable CPLD Counter output
	addrCounterDisable();
	
	//
	vramChipSelectDisable();	
	
}

//Enable video and disable MCU Writings
void videoEnable()
{
	//setBusTrisate();
	
	fastBusFree();
	
	vramChipSelectEnable();
	
	vramOutputEnable();
	
	addrCounterEnable();	
}
