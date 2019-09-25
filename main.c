#include "LM4F120.h"
#include "hw_config.h"
#include "uart.h"
#include "misc.h"
#include "gpioTest.h"



//Delay x cycles
void delay(int dly);




void main(void)
{
	
	// Define system clock as 16MHz (PIOSC)
	//RCC = 0x3AD1;
	
	disable_interrupts();
	
	holdBus();
	
	//setBusTrisate();
	
	setFreq80();
	
	//enableDataBus();
	
	portTest();
		
	//Enable GPIOF AND GPIOB Ports clk
	RCGCGPIO |= 0x22;
	
	//Turn on AHB access to GPIOF AND GPIOB
	GPIOHBCTL |= 0x22;
	
	//Unlock Port F
	//GPIOLOCK_A = 0x4C4F434B;
	
	// Allow changes to PF4-1
	//GPIOCR_A = 0xFF;
	
	//PORT F 8-mA Drive Select
	//GPIODR8R_F = 0xFF;
		
	//PF1,PF2,PF3 as outputs and PF0, PF4 as inputs
	//GPIODIR_F = 0x0E;
	//GPIOPCTL_F = 0x00;
	
	//Port F as Digital I/O
	//GPIOAFSEL_F = 0x00;
		
	// PF4 (USR_SW1) Pull-up enable
	//GPIOPUR_F = 0x10;
	
	//Enable PF0, PF1, PF2, PF3 and PF4 Pad
	//GPIODEN_F = 0x1F;
	
	
	//CLear All LEDs
	//LED_A = 0x00;
	
	//SysTck configuration
	
	//Counter value = 0xFFFFFF
	STRELOAD |= 0xFFFFFF;
	//Enable Interrupt and counter
	STCTRL	 |= 0x07;
	
	//cfgCtrlLines();	
	
	//Enable PWM
	enablePWM0();
	

	//enable_interrupts();
	
	//enableUART0();
	
	
	//uartTxString(msg);
	
	//char new = '\n';
	
	//uartTxByte(new);
	

	//Loop Forever	
	while(1)
	{
		
		//if(!USR_SW1)
			//LED_R = 0xFF;
		//else
			//LED_R = 0x00;
		
	}
	


}





void delay(int dly)
{
	while (dly--);
}




