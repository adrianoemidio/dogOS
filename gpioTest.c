#include "gpioTest.h"
#include "LM4F120.h"
#include "hw_config.h"
#include "uart.h"
#include "misc.h"

//Test port state on power up and reset
void portTest()
{
	//All ports acessed through AHB
	GPIOHBCTL |= 0x3F;
	
	//All ports Cloclk enable
	RCGCGPIO |= 0x3F;
	
	int afsel_bkp = GPIOAFSEL_A;
	int den_bkp =	GPIODEN_A;
	
	char newLine = '\n';
	
	char temp[12]; 
	
	//Enable UART0
	enableUART0();
	
	// Intro
	uartTxString(introMsg);
	uartTxByte(newLine);
	uartTxString(septr);
	
	//Test msg
	uartTxString(testMsg);
	uartTxString(septr);
	uartTxString(ptregs);
	uartTxByte(newLine);
	
	//GPIO A
	uartTxString(port);
	uartTxString("A\n");
	uartTxString(reg0);
	uartTxString(itoa(afsel_bkp,temp));
	uartTxByte(newLine);
	uartTxString(reg1);
	uartTxString(itoa(den_bkp,temp));
	uartTxByte(newLine);
	uartTxString(reg2);
	uartTxString(itoa(GPIOPDR_A,temp));
	uartTxByte(newLine);
	uartTxString(reg3);
	uartTxString(itoa(GPIOPUR_A,temp));
	uartTxByte(newLine);
	uartTxString(reg4);
	uartTxString(itoa(GPIOPCTL_A,temp));

	uartTxByte(newLine);
	uartTxString(septr);
	uartTxByte(newLine);
		
	//GPIO B
	uartTxString(port);
	uartTxString("B\n");
	uartTxString(reg0);
	uartTxString(itoa(GPIOAFSEL_B,temp));
	uartTxByte(newLine);
	uartTxString(reg1);
	uartTxString(itoa(GPIODEN_B,temp));
	uartTxByte(newLine);
	uartTxString(reg2);
	uartTxString(itoa(GPIOPDR_B,temp));
	uartTxByte(newLine);
	uartTxString(reg3);
	uartTxString(itoa(GPIOPUR_B,temp));
	uartTxByte(newLine);
	uartTxString(reg4);
	uartTxString(itoa(GPIOPCTL_B,temp));

	uartTxByte(newLine);
	uartTxString(septr);
	uartTxByte(newLine);
	
	
	//GPIO C
	uartTxString(port);
	uartTxString("C\n");
	uartTxString(reg0);
	uartTxString(itoa(GPIOAFSEL_C,temp));
	uartTxByte(newLine);
	uartTxString(reg1);
	uartTxString(itoa(GPIODEN_C,temp));
	uartTxByte(newLine);
	uartTxString(reg2);
	uartTxString(itoa(GPIOPDR_C,temp));
	uartTxByte(newLine);
	uartTxString(reg3);
	uartTxString(itoa(GPIOPUR_C,temp));
	uartTxByte(newLine);
	uartTxString(reg4);
	uartTxString(itoa(GPIOPCTL_C,temp));

	uartTxByte(newLine);
	uartTxString(septr);
	uartTxByte(newLine);
	
	//Port D
	uartTxString(port);
	uartTxString("D\n");
	uartTxString(reg0);
	uartTxString(itoa(GPIOAFSEL_D,temp));
	uartTxByte(newLine);
	uartTxString(reg1);
	uartTxString(itoa(GPIODEN_D,temp));
	uartTxByte(newLine);
	uartTxString(reg2);
	uartTxString(itoa(GPIOPDR_D,temp));
	uartTxByte(newLine);
	uartTxString(reg3);
	uartTxString(itoa(GPIOPUR_D,temp));
	uartTxByte(newLine);
	uartTxString(reg4);
	uartTxString(itoa(GPIOPCTL_D,temp));

	uartTxByte(newLine);
	uartTxString(septr);
	uartTxByte(newLine);
	
	
	//Port E
	uartTxString(port);
	uartTxString("E\n");
	uartTxString(reg0);
	uartTxString(itoa(GPIOAFSEL_E,temp));
	uartTxByte(newLine);
	uartTxString(reg1);
	uartTxString(itoa(GPIODEN_E,temp));
	uartTxByte(newLine);
	uartTxString(reg2);
	uartTxString(itoa(GPIOPDR_E,temp));
	uartTxByte(newLine);
	uartTxString(reg3);
	uartTxString(itoa(GPIOPUR_E,temp));
	uartTxByte(newLine);
	uartTxString(reg4);
	uartTxString(itoa(GPIOPCTL_E,temp));

	uartTxByte(newLine);
	uartTxString(septr);
	uartTxByte(newLine);
	
	//Port F
	uartTxString(port);
	uartTxString("F\n");
	uartTxString(reg0);
	uartTxString(itoa(GPIOAFSEL_F,temp));
	uartTxByte(newLine);
	uartTxString(reg1);
	uartTxString(itoa(GPIODEN_F,temp));
	uartTxByte(newLine);
	uartTxString(reg2);
	uartTxString(itoa(GPIOPDR_F,temp));
	uartTxByte(newLine);
	uartTxString(reg3);
	uartTxString(itoa(GPIOPUR_F,temp));
	uartTxByte(newLine);
	uartTxString(reg4);
	uartTxString(itoa(GPIOPCTL_F,temp));

	uartTxByte(newLine);
	uartTxString(septr);
	uartTxByte(newLine);
	
	
}
