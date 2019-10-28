#include "misc.h"


//Set oscillator freq to 50 MHz
void setFreq50()
{
	//Bypass the PLL
	RCC |= 0x800;
	
	//Disable system clock divider
	RCC &= (~0x400000);
	
	//PLL xtal inplut value = 16MHz
	RCC &= (~0x7C0);
	RCC |= 0x540;
	
	//Turn PLL ON
	RCC &= (~0x2000);
	
	//Divid by for Sysfreq = 50MHz
	RCC &= (~0x7800000);
	RCC |= 0x1800000;
	
	//Use External clock source
	RCC &= (~b4);
	
	//Enable system clock divider
	RCC |= 0x400000;

	
	//Wait for PLL Lock
	while(!(RIS & 0x40));
	
	//Enable PLL as system clock
	RCC &= (~0x800);
	
	
}

//Set oscillator freq to 80 MHz
void setFreq80()
{
	
	//PLL xtal inplut value = 16MHz
	RCC &= (~0x7C0);
	RCC |= 0x540;
	
	//Using RCC2 register
	bit_set(RCC2,b31);
	
	//Bypass the PLL
	bit_set(RCC2,b11);
	
	//Disable system clock divider
	//RCC &= (~0x400000);

	//Wait to clock start
	while(PLLSTAT);
	
	
	//Turn PLL ON
	RCC2 &= (~0x2000);
	
	//Divid by for Sysfreq = 80MHz
	RCC2 &= (~0x1FC00000);
	RCC2 |= 0x1000000;
	
	//DIV = 400
	bit_set(RCC2,b30);
	
	//SYSDIV2LSB = 0;
	bit_clr(RCC2,b22);
	

	//Wait for PLL Lock
	while(!(RIS & 0x40));
	
	//Enable PLL as system clock
	RCC2 &= (~0x800);
	
}

//Enable PWM A in Timer 0
// Freq. 10MHz for System Clk = 80MHz
void enablePWM0()
{
	
	//Enable GPTM0 Clock
	RCGCTIMER |= 0x01;
	
	//Ensure timer 0 is disable
	GPTMCTL_0 = 0x00;
	
	//Timer 0 as 16-bit timer wide
	GPTMCFG_0 = 0x04;
	
	//PWM mode is enabled, edge-Count mode and Timer B in periodic timer mode
	GPTMTBMR_0 |= 0x0A;
	
	//PWM period = 50us with main clock at 80MHz
	GPTMTBILR_0 = 0x03;
	
	//PWM dutcycle = 50%
	GPTMTBMATCHR_0 = 0x01;
	
	//Enable PWM on Timer B enable
	GPTMCTL_0 |= b8;
	
	
	//Pin PB7 as output
	GPIODIR_B |= b7;
	
	//Alternate function on PB7
	GPIOAFSEL_B |= b7;
		
	//PB7 as T0CCP1 output
	GPIOPCTL_B = 0x70000000;
	
	//PORT B 8-mA Drive Select
	GPIODR8R_B = 0xFF;
	
	//Slew Rate enable on pin PB6
	//GPIOSLR_B |= b6;
	
	//Enable PB6 Pad
	GPIODEN_B |= b7;
	
	
	
	
}

void fastBusFree()
{
	//reg &= (~mask)
	//GPIODEN=0, GPIOPDR=0, GPIOPUR=0
	
	//Port B
	GPIODEN_B &= (~MASK_PB);
	GPIOPDR_B &= (~MASK_PB);
	GPIOPUR_B &= (~MASK_PB);
	
	//Port C
	GPIODEN_C &= (~MASK_PC);
	GPIOPDR_C &= (~MASK_PC);
	GPIOPUR_C &= (~MASK_PC);
	
	//Port D
	GPIODEN_D &= (~MASK_PD);
	GPIOPDR_D &= (~MASK_PD);
	GPIOPUR_D &= (~MASK_PD);
	
	//Port E
	GPIODEN_E &= (~MASK_PE);
	GPIOPDR_E &= (~MASK_PE);
	GPIOPUR_E &= (~MASK_PE);
	
	//Port F
	GPIODEN_F &= (~MASK_PF);
	GPIOPDR_F &= (~MASK_PF);
	GPIOPUR_F &= (~MASK_PF);	
	
	
	
}

//Configure all GPIO as Tristate
void setBusTrisate()
{
	//GPIOAFSEL=0,GPIODEN=0, GPIOPDR=0, GPIOPUR=0, and GPIOPCTL=0
	
	//Enable clk on all GPIO
	RCGCGPIO |= 0x3F;
	
	//Turn on AHB access to All GPIO
	GPIOHBCTL |= 0x3F;
	
	//GPIO A
	GPIOAFSEL_A	= 0x00;
	GPIODEN_A	= 0x00;
	GPIOPDR_A	= 0x00;
	GPIOPUR_A	= 0x00;
	GPIOPCTL_A	= 0x00;
	
	//GPIO B
	GPIOAFSEL_B	= 0x00;
	GPIODEN_B	= 0x00;
	GPIOPDR_B	= 0x00;
	GPIOPUR_B	= 0x00;
	GPIOPCTL_B	= 0x00;
	
	//GPIO C
	/*GPIOAFSEL_C	= 0x00;
	GPIODEN_C	= 0x00;
	GPIOPDR_C	= 0x00;
	GPIOPUR_C	= 0x00;
	GIOPCTL_C	= 0x00;*/
	
	GPIOAFSEL_C	= 15;
	GPIODEN_C	= 15;
	GPIOPDR_C	= 0x00;
	GPIOPUR_C	= 15;
	GPIOPCTL_C	= 4369;
	
	//GPIO D
	GPIOAFSEL_D	= 0x00;
	GPIODEN_D	= 0x00;
	GPIOPDR_D	= 0x00;
	GPIOPUR_D	= 0x00;
	GPIOPCTL_D	= 0x00;
	
	//GPIO E
	GPIOAFSEL_E	= 0x00;
	GPIODEN_E	= 0x00;
	GPIOPDR_E	= 0x00;
	GPIOPUR_E	= 0x00;
	GPIOPCTL_E	= 0x00;
	
	//GPIO F
	GPIOAFSEL_F	= 0x00;
	GPIODEN_F	= 0x00;
	GPIOPDR_F	= 0x00;
	GPIOPUR_F	= 0x00;
	GPIOPCTL_F	= 0x00;
	

	cfgCtrlLines();
}

//Enable data bus
void enableDataBus()
{
	//Enable clk on GPIO C and F
	RCGCGPIO |= 0x24;
	
	//Turn on AHB access to All GPIO
	GPIOHBCTL |= 0x3F;


	//GPIO C
	//PC[7:4]
	GPIODIR_C |= 0xF0;
	GPIOPUR_C |= 0x00;
	GPIOPDR_C |= 0xF0;
	GPIODR2R_C |= 0xF0;
	GPIOAFSEL_C &= 0x0F;
	GPIODEN_C |= 0xF0;
	
	//GPIO F
	//PF[4:1] as output
	GPIODIR_F |= 0x1E;
	GPIOPUR_F |= 0x00;
	GPIOPDR_F |= 0x1E;
	GPIODR2R_F |= 0x1E;
	GPIOAFSEL_F |= 0x00;
	GPIODEN_F |= 0x1E;
		
}

//Enable addr bus
void enableAddrBus()
{
	//Enable clk on All Ports
	RCGCGPIO |= 0x3F;
	
	//Turn on AHB access to All GPIO
	GPIOHBCTL |= 0x3F;



	//PORTB 
	//PB[1:0] and PB[4:6] as outputss
	GPIODIR_B	|= 0x73;
	GPIOPUR_B	|= 0x00;
	GPIOPDR_B	|= 0x73;
	GPIODR2R_B	|= 0x73;
	GPIOAFSEL_B	|= 0x00;
	GPIODEN_B	|= 0x73;

	//GPIO D
	//PD[3:0] as outputs
	GPIODIR_D	|= 0x0F;
	GPIOPUR_D	|= 0x00;
	GPIOPDR_D	|= 0x0F;
	GPIODR2R_D	|= 0x0F;
	GPIOAFSEL_D	|= 0x00;
	GPIODEN_D	|= 0x0F;
	
	//GPIO E
	//PE[5:0] as outputs
	GPIODIR_E	|= 0x3F;
	GPIOPUR_E	|= 0x00;
	GPIOPDR_E	|= 0x3F;
	GPIODR2R_E	|= 0x3F;
	GPIOAFSEL_E |= 0x00;
	GPIODEN_E	|= 0x3F;

}

//Send value to data bus
void dataBusWrite(int data)
{
	
	PF1 = (data & b0) ? 0xFF:0x00;
	PF2 = (data & b1) ? 0xFF:0x00;
	PF3 = (data & b2) ? 0xFF:0x00;
	PF4 = (data & b3) ? 0xFF:0x00;
	
	PC4 = (data & b4) ? 0xFF:0x00;
	PC5 = (data & b5) ? 0xFF:0x00;
	PC6 = (data & b6) ? 0xFF:0x00;
	PC7 = (data & b7) ? 0xFF:0x00; 
	
	
}

//Send value to data bus
void addrBusWrite(int data)
{
	PD0	= (data & b0)	? 0xFF:0x00;
	PD1	= (data & b1)	? 0xFF:0x00;
	PD2	= (data & b2)	? 0xFF:0x00;
	PD3	= (data & b3)	? 0xFF:0x00;
	PE0	= (data & b4)	? 0xFF:0x00;
	PE1	= (data & b5)	? 0xFF:0x00;
	PE2	= (data & b6)	? 0xFF:0x00;
	PE3	= (data & b7)	? 0xFF:0x00;
	PE4	= (data & b8)	? 0xFF:0x00;
	PE5	= (data & b9)	? 0xFF:0x00;
	PB0	= (data & b10)	? 0xFF:0x00;
	PB1	= (data & b11)	? 0xFF:0x00;
	PB4	= (data & b12)	? 0xFF:0x00;
	PB5	= (data & b13)	? 0xFF:0x00;
	PB6	= (data & b14)	? 0xFF:0x00;


}

//Enable interrupt on V Blank
void enableVSyncInterr()
{
	//Enable interrupt
	bit_set(EN0,b0);
	
	//Interrupt is Edge sensitive
	bit_clr(GPIOIS_A,b6);
	
	//Interrupt generation is controlled by the GPIOIEV register
	bit_clr(GPIOIBE_A,b6);
	
	//Interrupt on falling edge
	bit_clr(GPIOIEV_A,b6);
	
	//PA6 interrupt is will be send to interrupt controller
	bit_set(GPIOIM_A,b6);
	
	//Clear interrupt
	bit_set(GPIOICR_A,b6);
	
	
}


//Configure control lines on ports PA[5:2]
void cfgCtrlLines()
{
	//Enable clk on all GPIO
	RCGCGPIO |= 0x3F;
	
	//Turn on AHB access to All GPIO
	GPIOHBCTL |= 0x3F;

	//Disable alternate functions on GPIO A, except for Serial
	GPIOPCTL_A	= 0x11; 

	//PA[5,2] as outputs
	GPIODIR_A	|= 0x3C;
	
	//PA[7:6] as inputs
	bit_clr(GPIODIR_A,b6+b7);
	
	//2mA output buffer on PA[5,2]
	GPIODR2R_A	|= 0x3C;
	
	//Enable digital output
	GPIODEN_A |= 0xFC;
		
	//Pin PB7 as output
	GPIODIR_B |= b7;
	
	//Alternate function on PB7
	GPIOAFSEL_B |= b7;
		
	//PB7 as T0CCP1 output
	GPIOPCTL_B = 0x70000000;
	
	//PORT B 8-mA Drive Select
	GPIODR8R_B = 0xFF;
	
	//Slew Rate enable on pin PB6
	//GPIOSLR_B |= b6;
	
	//Enable PB6 Pad
	GPIODEN_B |= b7;
	

	
}


void holdBus()
{
	//Enable clk on GPIO A
	RCGCGPIO |= 0x03;
	
	//Turn on AHB access to All GPIO
	GPIOHBCTL |= 0x3F;

	//Disable alternate functions on GPIO A, except for Serial
	GPIOPCTL_A	= 0x11; 
	
	//Disable analog funcios
	//GPIOAFSEL_A &= (~0x3C);
	
	//PA[5,2] as outputs
	GPIODIR_A	|= 0x3C;
	
	//2mA output buffer on PA[5,2]
	GPIODR2R_A	|= 0x3C;
	
	//Enable digital output
	GPIODEN_A |= 0x3C;
	
	
	vramOutputDisable();
	vramChipSelectDisable();
	addrCounterDisable();
	vramWriteDisable();
	
	
	
	GPIOPCTL_B = 0x00;
	
}

//SysTck configuration
void enableSysTick()
{
			
	
	//Counter value = 0xFFFFFF
	STRELOAD |= 0xFFFFFF;
	//Enable Interrupt and counter
	STCTRL	 |= 0x07;
}

void delay(int dly)
{
	while (dly--);
}

