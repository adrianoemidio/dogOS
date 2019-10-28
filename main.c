#include "misc.h"

#include "img.h"


void main(void)
{
	
	update = 0;
	
	disable_interrupts();
	
	holdBus();
	
	
	
	//setFreq80();
	setFreq50();
	
	cfgCtrlLines();



	
	videoEnable();
	clearVideo(0x00);
	
	
	
	sprite squid[4];
	
	spritInit(&squid[0],8,8,squid_spt);
		
	squid[0].pos.x = 248;
	squid[0].pos.y = 232;
	
	
	for(int i = 1; i < 4; i++)
		copySprite(&squid[0],&squid[i]);
	
	squid[1].pos.x = 0;
	squid[1].pos.y = 0;
	
	squid[2].pos.x = 248;
	squid[2].pos.y = 0;
	
	squid[3].pos.x = 0;
	squid[3].pos.y = 232;
	
	
	for(int i = 0; i < 4; i++)		
		drawSprite(&squid[i]);
		
	
	//sprite crab[2];
	
	spritInit(&crab[0],11,8,crab_spt);
	copySprite(&crab[0],&crab[1]);
	
	crab[0].pos.x = 100;
	crab[0].pos.y = 100;
	
	drawSprite(&crab[0]);
	
	
	position p1,p2;
	
	p1.x = 120;
	p1.y = 100;
	
	p2.x = 140;
	p2.y = 100;
	

	
	drawImage(12,8,octopus_spt,p1);
	drawImage(13,8,cannon_spt,p2);
	



	
	portTest();
		
	
	
	enableSysTick();

	enableVSyncInterr();
	

	
	//Enable PWM
	enablePWM0();

	enable_interrupts();
	
	
	

	
	

	//Loop Forever	
	while(1)
	{
		
		
		//if(!USR_SW1)
			//LED_R = 0xFF;
		//else
			//LED_R = 0x00;
		
	}
	


}









