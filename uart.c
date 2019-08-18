#include "LM4F120.h"
#include "misc.h"

//Enable UART
void enableUART0()
{

	//Port A access through AHB
	bit_set(GPIOHBCTL,b0);

	//Enable clk on GPIOA
	bit_set(RCGCGPIO,b0);
	
	//Enable UART module
	bit_set(RCGCUART,b0);
	
	//Bits 0 and 1 as TX an RX
	bit_set(GPIOAFSEL_A,(b0+b1));

	//Driver strength on PA[1:0] is 2mA
	bit_set(GPIODR8R_A,(b0+b1));
	
	//UART disabled
	bit_clr(UARTCC_U0,b0);
	
	//Baud Rate to 115200
	UARTIBRD_U0 = 0x1B;
	UARTFBRD_U0 = 0x08;
	
	//Data length of 8 bits, One stop bit, No parity, FIFOs disabled
	UARTLCRH_U0 = 0x60;
	
	//Enable digital out on PA[1:0]
	bit_set(GPIODEN_A,(b0+b1));
	
	
	//Enable Recieve Interrupt
	bit_set(UARTIM_U0,b4);
	
	//Enable UART0 Interrupt
	bit_set(EN0,b5);
	
	//SysClk as UART CLkSRc
	UARTCC_U0 = 0x00;
	
	//Enable Trasmition an reception
	bit_set(UARTCTL_U0,(b9+b8));
	

	//Enable Serial
	bit_set(UARTCTL_U0,b0);
	
}

//Transmit one byte
void uartTxByte(int data)
{
	//Wait unit previous Tx ends
	while((UARTFR_U0 & b3));
	
	//Transmit data
	UARTDR_U0 = (data & 0xFF);
	
	
}

//Transmit a string 
void uartTxString(char* s)
{
	int count = 0;
	
	while((*s != '\0') && (count < 100))
	{
		uartTxByte(*s);
		
		s++;
		count++;
		
	}
	
}

//Convert int to string
char* itoa(int i, char b[])
{
	char const digit[] = "0123456789";
	
	char* p = b;
	
	if(i<0)
	{
		*p++ = '-';
		i *= (-1);
	}
	
	int shifter = i;
	
	do
	{
		++p;
		shifter /= 10;
		
	}while(shifter);
	
	
	*p = '\0';
	
	do
	{
		*--p = digit[i%10];
		i /= 10;
					
		
	}while(i);
	
	return b;
	
}	

