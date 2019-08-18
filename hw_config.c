#include "hw_config.h"
#include "LM4F120.h"
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
	
	//Bypass the PLL
	RCC |= 0x800;
	
	//Disable system clock divider
	RCC &= (~0x400000);
	
	//PLL xtal inplut value = 16MHz
	RCC &= (~0x7C0);
	RCC |= 0x540;
	
	//
	while(PLLSTAT);
	
	//Using RCC2 register
	RCC2 |= 0x80000000;
	
	//Turn PLL ON
	RCC2 &= (~0x2000);
	
	//Divid by for Sysfreq = 80MHz
	RCC2 &= (~0x1FC00000);
	RCC2 |= 0x1000000;
	
	//DIV = 400
	RCC2 |= 0x40000000;
	
	//Enable system clock divider
	RCC |= 0x400000;
	
	//Wait for PLL Lock
	while(!(RIS & 0x40));
	
	//Enable PLL as system clock
	RCC2 &= (~0x800);
	
}

//Enable PWM A in Timer 0
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
	
	//PWM period = 80us wirh main clock at 50MHz
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



//Configure control lines on ports PA[5:2]
void cfgCtrlLines()
{
	//Enable clk on GPIOA
	bit_set(RCGCGPIO,b0);
	
	//Port A access through AHB
	bit_set(GPIOHBCTL,b0);
	
	//Disable SSIO on PA
	GPIOPCTL_A = 0x00;

	//Set pins PA[5:2] as outputs
	bit_set(GPIODIR_A,(b5+b4+b3+b2));
	
	//Driver strength on PA[5:2] is 2mA
	bit_set(GPIODR2R_A,(b5+b4+b3+b2));
	
	//Enable digital out on PA[5:2]
	bit_set(GPIODEN_A,(b5+b4+b3+b2));
	
	
	
	
}
