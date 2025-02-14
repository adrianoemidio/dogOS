#ifndef LM4F120_H
#define LM4F120_H

// Macros to enable/disable global interrupts
#define enable_interrupts() asm("cpsie i\n")
#define disable_interrupts() asm("cpsid i\n")
#define NOP() asm("nop\n")

#define STACK_TOP 0x20007000
#define NULL_HANDLER 0x00000000

#define REG32(ADDR) (*((volatile unsigned int *)(ADDR)))

//System Control Registers
#define SYSTEMCONTROL 0x400FE000

#define RIS  REG32(SYSTEMCONTROL + 0x50)
#define RCC	 REG32(SYSTEMCONTROL + 0x60)
#define RCC2 REG32(SYSTEMCONTROL + 0x70)

//PLL STATUS
#define PLLSTAT REG32(SYSTEMCONTROL + 0x168)

#define	GPIOHBCTL REG32(SYSTEMCONTROL +0x06c)

//GPIO Run Mode Clock Gating Control
#define RCGCGPIO REG32(SYSTEMCONTROL + 0x608)

//UART Run Mode Clock Gating Control
#define RCGCUART REG32(SYSTEMCONTROL + 0x618)

//GPTM Run Mode Clock Gating Control
#define RCGCTIMER REG32(SYSTEMCONTROL + 0x604)

//Core Peripherals Register Map
#define COREPERIPHERALS 0xE000E000

//System Timer (SysTick) Registers
#define STCTRL		REG32(COREPERIPHERALS + 0x10)
#define STRELOAD	REG32(COREPERIPHERALS + 0x14)
#define STCURRENT	REG32(COREPERIPHERALS + 0x18)

//Nested Vectored Interrupt Controller (NVIC) Registers
#define	EN0		REG32(COREPERIPHERALS	+	0x100)
#define	EN1		REG32(COREPERIPHERALS	+	0x104)
#define	EN2		REG32(COREPERIPHERALS	+	0x108)
#define	EN3		REG32(COREPERIPHERALS	+	0x10C)
#define	EN4		REG32(COREPERIPHERALS	+	0x110)
#define	DIS0	REG32(COREPERIPHERALS	+	0x180)
#define	DIS1	REG32(COREPERIPHERALS	+	0x184)
#define	DIS2	REG32(COREPERIPHERALS	+	0x188)
#define	DIS3	REG32(COREPERIPHERALS	+	0x18C)
#define	DIS4	REG32(COREPERIPHERALS	+	0x190)
#define	PEND0	REG32(COREPERIPHERALS	+	0x200)
#define	PEND1	REG32(COREPERIPHERALS	+	0x204)
#define	PEND2	REG32(COREPERIPHERALS	+	0x208)
#define	PEND3	REG32(COREPERIPHERALS	+	0x20C)
#define	PEND4	REG32(COREPERIPHERALS	+	0x210)
#define	UNPEND0	REG32(COREPERIPHERALS	+	0x280)
#define	UNPEND1	REG32(COREPERIPHERALS	+	0x284)
#define	UNPEND2	REG32(COREPERIPHERALS	+	0x288)
#define	UNPEND3	REG32(COREPERIPHERALS	+	0x28C)
#define	UNPEND4	REG32(COREPERIPHERALS	+	0x290)
#define	ACTIVE0	REG32(COREPERIPHERALS	+	0x300)
#define	ACTIVE1	REG32(COREPERIPHERALS	+	0x304)
#define	ACTIVE2	REG32(COREPERIPHERALS	+	0x308)
#define	ACTIVE3	REG32(COREPERIPHERALS	+	0x30C)
#define	ACTIVE4	REG32(COREPERIPHERALS	+	0x310)
#define	PRI0	REG32(COREPERIPHERALS	+	0x400)
#define	PRI1	REG32(COREPERIPHERALS	+	0x404)
#define	PRI2	REG32(COREPERIPHERALS	+	0x408)
#define	PRI3	REG32(COREPERIPHERALS	+	0x40C)
#define	PRI4	REG32(COREPERIPHERALS	+	0x410)
#define	PRI5	REG32(COREPERIPHERALS	+	0x414)
#define	PRI6	REG32(COREPERIPHERALS	+	0x418)
#define	PRI7	REG32(COREPERIPHERALS	+	0x41C)
#define	PRI8	REG32(COREPERIPHERALS	+	0x420)
#define	PRI9	REG32(COREPERIPHERALS	+	0x424)
#define	PRI10	REG32(COREPERIPHERALS	+	0x428)
#define	PRI11	REG32(COREPERIPHERALS	+	0x42C)
#define	PRI12	REG32(COREPERIPHERALS	+	0x430)
#define	PRI13	REG32(COREPERIPHERALS	+	0x434)
#define	PRI14	REG32(COREPERIPHERALS	+	0x438)
#define	PRI15	REG32(COREPERIPHERALS	+	0x43C)
#define	PRI16	REG32(COREPERIPHERALS	+	0x440)
#define	PRI17	REG32(COREPERIPHERALS	+	0x444)
#define	PRI18	REG32(COREPERIPHERALS	+	0x448)
#define	PRI19	REG32(COREPERIPHERALS	+	0x44C)
#define	PRI20	REG32(COREPERIPHERALS	+	0x450)
#define	PRI21	REG32(COREPERIPHERALS	+	0x454)
#define	PRI22	REG32(COREPERIPHERALS	+	0x458)
#define	PRI23	REG32(COREPERIPHERALS	+	0x45C)
#define	PRI24	REG32(COREPERIPHERALS	+	0x460)
#define	PRI25	REG32(COREPERIPHERALS	+	0x464)
#define	PRI26	REG32(COREPERIPHERALS	+	0x468)
#define	PRI27	REG32(COREPERIPHERALS	+	0x46C)
#define	PRI28	REG32(COREPERIPHERALS	+	0x470)
#define	PRI29	REG32(COREPERIPHERALS	+	0x474)
#define	PRI30	REG32(COREPERIPHERALS	+	0x478)
#define	PRI31	REG32(COREPERIPHERALS	+	0x47C)
#define	PRI32	REG32(COREPERIPHERALS	+	0x480)
#define	PRI33	REG32(COREPERIPHERALS	+	0x484)
#define	PRI34	REG32(COREPERIPHERALS	+	0x488)
#define	SWTRIG	REG32(COREPERIPHERALS	+	0xF00)




//GPIO Control Register MAP

//Port A
#define PORTA 0x40058000 //(AHB)
#define GPIODATA_A	REG32(PORTA + GPIODATA) 
#define GPIODIR_A	REG32(PORTA + GPIODIR)
#define GPIOIS_A	REG32(PORTA + GPIOIS)
#define GPIOIBE_A	REG32(PORTA + GPIOIBE)
#define GPIOIEV_A	REG32(PORTA + GPIOIEV)
#define GPIOIM_A	REG32(PORTA + GPIOIM)
#define GPIORIS_A	REG32(PORTA + GPIORIS)
#define GPIOMIS_A	REG32(PORTA + GPIOMIS)
#define GPIOICR_A	REG32(PORTA + GPIOICR)
#define GPIOAFSEL_A REG32(PORTA + GPIOAFSEL)
#define GPIODR2R_A	REG32(PORTA + GPIODR2R)
#define GPIODR4R_A	REG32(PORTA + GPIODR4R)
#define GPIODR8R_A	REG32(PORTA + GPIODR8R)
#define GPIODEN_A	REG32(PORTA + GPIODEN)
#define GPIOPUR_A	REG32(PORTA + GPIOPUR)
#define GPIOPCTL_A	REG32(PORTA + GPIOPCTL)
#define GPIOLOCK_A	REG32(PORTA + GPIOLOCK)
#define GPIOCR_A	REG32(PORTA + GPIOCR)
#define GPIOPDR_A	REG32(PORTA + GPIOPDR)

//PA pins
#define PA0	REG32(PORTA + P0)
#define PA1	REG32(PORTA + P1)
#define PA2	REG32(PORTA + P2)
#define PA3	REG32(PORTA + P3)
#define PA4	REG32(PORTA + P4)
#define PA5	REG32(PORTA + P5)
#define PA6	REG32(PORTA + P6)
#define PA7	REG32(PORTA + P7)

//Port B
#define PORTB 0x40059000 //AHB
#define GPIODATA_B	REG32(PORTB + GPIODATA) 
#define GPIODIR_B	REG32(PORTB + GPIODIR)
#define GPIOIS_B	REG32(PORTB + GPIOIS)
#define GPIOIBE_B	REG32(PORTB + GPIOIBE)
#define GPIOIEV_B	REG32(PORTB + GPIOIEV)
#define GPIOIM_B	REG32(PORTB + GPIOIM)
#define GPIORIS_B	REG32(PORTB + GPIORIS)
#define GPIOMIS_B	REG32(PORTB + GPIOMIS)
#define GPIOICR_B	REG32(PORTB + GPIOICR)
#define GPIOAFSEL_B REG32(PORTB + GPIOAFSEL)
#define GPIODR2R_B	REG32(PORTB + GPIODR2R)
#define GPIODR4R_B	REG32(PORTB + GPIODR4R)
#define GPIODR8R_B	REG32(PORTB + GPIODR8R)
#define GPIOSLR_B	REG32(PORTB + GPIOSLR)
#define GPIODEN_B	REG32(PORTB + GPIODEN)
#define GPIOPUR_B	REG32(PORTB + GPIOPUR)
#define GPIOPCTL_B	REG32(PORTB + GPIOPCTL)
#define GPIOLOCK_B	REG32(PORTB + GPIOLOCK)
#define GPIOCR_B	REG32(PORTB + GPIOCR)
#define GPIOPDR_B	REG32(PORTB + GPIOPDR)

//PB pins
#define PB0	REG32(PORTB + P0)
#define PB1	REG32(PORTB + P1)
#define PB2	REG32(PORTB + P2)
#define PB3	REG32(PORTB + P3)
#define PB4	REG32(PORTB + P4)
#define PB5	REG32(PORTB + P5)
#define PB6	REG32(PORTB + P6)
#define PB7	REG32(PORTB + P7)

//Port C
#define PORTC 0x4005A000 //AHB
#define GPIODATA_C	REG32(PORTC + GPIODATA) 
#define GPIODIR_C	REG32(PORTC + GPIODIR)
#define GPIOIS_C	REG32(PORTC + GPIOIS)
#define GPIOIBE_C	REG32(PORTC + GPIOIBE)
#define GPIOIEV_C	REG32(PORTC + GPIOIEV)
#define GPIOIM_C	REG32(PORTC + GPIOIM)
#define GPIORIS_C	REG32(PORTC + GPIORIS)
#define GPIOMIS_C	REG32(PORTC + GPIOMIS)
#define GPIOICR_C	REG32(PORTC + GPIOICR)
#define GPIOAFSEL_C REG32(PORTC + GPIOAFSEL)
#define GPIODR2R_C	REG32(PORTC + GPIODR2R)
#define GPIODR4R_C	REG32(PORTC + GPIODR4R)
#define GPIODR8R_C	REG32(PORTC + GPIODR8R)
#define GPIOSLR_C	REG32(PORTC + GPIOSLR)
#define GPIODEN_C	REG32(PORTC + GPIODEN)
#define GPIOPUR_C	REG32(PORTC + GPIOPUR)
#define GPIOPCTL_C	REG32(PORTC + GPIOPCTL)
#define GPIOLOCK_C	REG32(PORTC + GPIOLOCK)
#define GPIOCR_C	REG32(PORTC + GPIOCR)
#define GPIOPDR_C	REG32(PORTC + GPIOPDR)

//PC pins
#define PC0	REG32(PORTC + P0)
#define PC1	REG32(PORTC + P1)
#define PC2	REG32(PORTC + P2)
#define PC3	REG32(PORTC + P3)
#define PC4	REG32(PORTC + P4)
#define PC5	REG32(PORTC + P5)
#define PC6	REG32(PORTC + P6)
#define PC7	REG32(PORTC + P7)


//Port D
#define PORTD 0x4005B000 //AHB
#define GPIODATA_D	REG32(PORTD + GPIODATA) 
#define GPIODIR_D	REG32(PORTD + GPIODIR)
#define GPIOIS_D	REG32(PORTD + GPIOIS)
#define GPIOIBE_D	REG32(PORTD + GPIOIBE)
#define GPIOIEV_D	REG32(PORTD + GPIOIEV)
#define GPIOIM_D	REG32(PORTD + GPIOIM)
#define GPIORIS_D	REG32(PORTD + GPIORIS)
#define GPIOMIS_D	REG32(PORTD + GPIOMIS)
#define GPIOICR_D	REG32(PORTD + GPIOICR)
#define GPIOAFSEL_D REG32(PORTD + GPIOAFSEL)
#define GPIODR2R_D	REG32(PORTD + GPIODR2R)
#define GPIODR4R_D	REG32(PORTD + GPIODR4R)
#define GPIODR8R_D	REG32(PORTD + GPIODR8R)
#define GPIOSLR_D	REG32(PORTD + GPIOSLR)
#define GPIODEN_D	REG32(PORTD + GPIODEN)
#define GPIOPUR_D	REG32(PORTD + GPIOPUR)
#define GPIOPCTL_D	REG32(PORTD + GPIOPCTL)
#define GPIOLOCK_D	REG32(PORTD + GPIOLOCK)
#define GPIOCR_D	REG32(PORTD + GPIOCR)
#define GPIOPDR_D	REG32(PORTD + GPIOPDR)

//PC pins
#define PD0	REG32(PORTD + P0)
#define PD1	REG32(PORTD + P1)
#define PD2	REG32(PORTD + P2)
#define PD3	REG32(PORTD + P3)
#define PD4	REG32(PORTD + P4)
#define PD5	REG32(PORTD + P5)
#define PD6	REG32(PORTD + P6)
#define PD7	REG32(PORTD + P7)

//Port E

#define PORTE 0x4005C000 //AHB
#define GPIODATA_E	REG32(PORTE + GPIODATA) 
#define GPIODIR_E	REG32(PORTE + GPIODIR)
#define GPIOIS_E	REG32(PORTE + GPIOIS)
#define GPIOIBE_E	REG32(PORTE + GPIOIBE)
#define GPIOIEV_E	REG32(PORTE + GPIOIEV)
#define GPIOIM_E	REG32(PORTE + GPIOIM)
#define GPIORIS_E	REG32(PORTE + GPIORIS)
#define GPIOMIS_E	REG32(PORTE + GPIOMIS)
#define GPIOICR_E	REG32(PORTE + GPIOICR)
#define GPIOAFSEL_E REG32(PORTE + GPIOAFSEL)
#define GPIODR2R_E	REG32(PORTE + GPIODR2R)
#define GPIODR4R_E	REG32(PORTE + GPIODR4R)
#define GPIODR8R_E	REG32(PORTE + GPIODR8R)
#define GPIOSLR_E	REG32(PORTE + GPIOSLR)
#define GPIODEN_E	REG32(PORTE + GPIODEN)
#define GPIOPUR_E	REG32(PORTE + GPIOPUR)
#define GPIOPCTL_E	REG32(PORTE + GPIOPCTL)
#define GPIOLOCK_E	REG32(PORTE + GPIOLOCK)
#define GPIOCR_E	REG32(PORTE + GPIOCR)
#define GPIOPDR_E	REG32(PORTE + GPIOPDR)

//Pe pins
#define PE0	REG32(PORTE + P0)
#define PE1	REG32(PORTE + P1)
#define PE2	REG32(PORTE + P2)
#define PE3	REG32(PORTE + P3)
#define PE4	REG32(PORTE + P4)
#define PE5	REG32(PORTE + P5)
#define PE6	REG32(PORTE + P6)
#define PE7	REG32(PORTE + P7)


//Port F
#define PORTF 0x4005D000 //(AHB)
#define GPIODATA_F	REG32(PORTF + GPIODATA) 
#define GPIODIR_F	REG32(PORTF + GPIODIR)
#define GPIOIS_F	REG32(PORTF + GPIOIS)
#define GPIOIBE_F	REG32(PORTF + GPIOIBE)
#define GPIOIEV_F	REG32(PORTF + GPIOIEV)
#define GPIOIM_F	REG32(PORTF + GPIOIM)
#define GPIORIS_F	REG32(PORTF + GPIORIS)
#define GPIOMIS_F	REG32(PORTF + GPIOMIS)
#define GPIOICR_F	REG32(PORTF + GPIOICR)
#define GPIOAFSEL_F REG32(PORTF + GPIOAFSEL)
#define GPIODR2R_F	REG32(PORTF + GPIODR2R)
#define GPIODR4R_F	REG32(PORTF + GPIODR4R)
#define GPIODR8R_F	REG32(PORTF + GPIODR8R)
#define GPIODEN_F	REG32(PORTF + GPIODEN)
#define GPIOPUR_F	REG32(PORTF + GPIOPUR)
#define GPIOPCTL_F	REG32(PORTF + GPIOPCTL)
#define GPIOLOCK_F	REG32(PORTF + GPIOLOCK)
#define GPIOCR_F	REG32(PORTF + GPIOCR)
#define GPIOPDR_F	REG32(PORTF + GPIOPDR)

//PF pins
#define PF0	REG32(PORTF + P0)
#define PF1	REG32(PORTF + P1)
#define PF2	REG32(PORTF + P2)
#define PF3	REG32(PORTF + P3)
#define PF4	REG32(PORTF + P4)
#define PF5	REG32(PORTF + P5)
#define PF6	REG32(PORTF + P6)
#define PF7	REG32(PORTF + P7)

//GPIO Offsets
#define GPIODATA	0x000 
#define GPIODIR		0x400
#define GPIOIS		0x404
#define GPIOIBE		0x408
#define GPIOIEV		0x40C
#define GPIOIM		0x410
#define GPIORIS		0x414
#define GPIOMIS		0x418
#define GPIOICR		0x41C
#define GPIOAFSEL	0x420
#define GPIODR2R	0x500
#define GPIODR4R	0x504
#define GPIODR8R	0x508
#define GPIOSLR		0x518
#define GPIODEN		0x51C
#define GPIOPUR		0x510
#define GPIOPCTL	0x52C
#define GPIOLOCK	0x520
#define GPIOCR		0x524
#define GPIOPDR		0x514

//Individual Pins on port
#define	P0	0x004
#define P1	0x008
#define P2	0x010
#define P3	0x020
#define P4	0x040
#define P5	0x080
#define P6	0x100
#define P7	0x200


//UART

//UART 0 
#define UART0	0x4000C000
#define	UARTDR_U0			REG32(UART0 + UARTDR)
#define	UARTRSR_U0			REG32(UART0 + UARTRSR)
#define	UARTFR_U0			REG32(UART0 + UARTFR)
#define	UARTILPR_U0			REG32(UART0 + UARTILPR)
#define	UARTIBRD_U0			REG32(UART0 + UARTIBRD)
#define	UARTFBRD_U0			REG32(UART0 + UARTFBRD)
#define	UARTLCRH_U0			REG32(UART0 + UARTLCRH)
#define	UARTCTL_U0			REG32(UART0 + UARTCTL)
#define	UARTIFLS_U0			REG32(UART0 + UARTIFLS)
#define	UARTIM_U0			REG32(UART0 + UARTIM)
#define	UARTRIS_U0			REG32(UART0 + UARTRIS)
#define	UARTMIS_U0			REG32(UART0 + UARTMIS)
#define	UARTICR_U0			REG32(UART0 + UARTICR)
#define	UARTDMACTL_U0		REG32(UART0 + UARTDMACTL)
#define	UARTLCTL_U0			REG32(UART0 + UARTLCTL)
#define	UARTLSS_U0			REG32(UART0 + UARTLSS)
#define	UARTLTIM_U0			REG32(UART0 + UARTLTIM)
#define	UART9BITADDR_U0		REG32(UART0 + UART9BITADDR)
#define	UART9BITAMASK_U0	REG32(UART0 + UART9BITAMASK)
#define	UARTPP_U0			REG32(UART0 + UARTPP)
#define	UARTCC_U0			REG32(UART0 + UARTCC)
#define	UARTPeriphID4_U0	REG32(UART0 + UARTPeriphID4)
#define	UARTPeriphID5_U0	REG32(UART0 + UARTPeriphID5)
#define	UARTPeriphID6_U0	REG32(UART0 + UARTPeriphID6)
#define	UARTPeriphID7_U0	REG32(UART0 + UARTPeriphID7)
#define	UARTPeriphID0_U0	REG32(UART0 + UARTPeriphID0)
#define	UARTPeriphID1_U0	REG32(UART0 + UARTPeriphID1)
#define	UARTPeriphID2_U0	REG32(UART0 + UARTPeriphID2)
#define	UARTPeriphID3_U0	REG32(UART0 + UARTPeriphID3)
#define	UARTPCellID0_U0		REG32(UART0 + UARTPCellID0)
#define	UARTPCellID1_U0		REG32(UART0 + UARTPCellID1)
#define	UARTPCellID2_U0		REG32(UART0 + UARTPCellID2)
#define	UARTPCellID3_U0		REG32(UART0 + UARTPCellID3)

//UART Offsets
#define	UARTDR			0x000
#define	UARTRSR			0x004
#define	UARTFR			0x018
#define	UARTILPR		0x020
#define	UARTIBRD		0x024
#define	UARTFBRD		0x028
#define	UARTLCRH		0x02C
#define	UARTCTL			0x030
#define	UARTIFLS		0x034
#define	UARTIM			0x038
#define	UARTRIS			0x03C
#define	UARTMIS			0x040
#define	UARTICR			0x044
#define	UARTDMACTL		0x048
#define	UARTLCTL		0x090
#define	UARTLSS			0x094
#define	UARTLTIM		0x098
#define	UART9BITADDR	0x0A4
#define	UART9BITAMASK	0x0A8
#define	UARTPP			0xFC0
#define	UARTCC			0xFC8
#define	UARTPeriphID4	0xFD0
#define	UARTPeriphID5	0xFD4
#define	UARTPeriphID6	0xFD8
#define	UARTPeriphID7	0xFDC
#define	UARTPeriphID0	0xFE0
#define	UARTPeriphID1	0xFE4
#define	UARTPeriphID2	0xFE8
#define	UARTPeriphID3	0xFEC
#define	UARTPCellID0	0xFF0
#define	UARTPCellID1	0xFF4
#define	UARTPCellID2	0xFF8
#define	UARTPCellID3	0xFFC

//General proupose timers

//GPTM 0
#define GPTM0	0x40030000
#define	GPTMCFG_0			REG32(GPTM0 + GPTMCFG)
#define	GPTMTAMR_0			REG32(GPTM0 + GPTMTAMR)
#define	GPTMTBMR_0			REG32(GPTM0 + GPTMTBMR)
#define	GPTMCTL_0			REG32(GPTM0 + GPTMCTL)
#define	GPTMSYNC_0			REG32(GPTM0 + GPTMSYNC)
#define	GPTMIMR_0			REG32(GPTM0 + GPTMIMR)
#define	GPTMRIS_0			REG32(GPTM0 + GPTMRIS)
#define	GPTMMIS_0			REG32(GPTM0 + GPTMMIS)
#define	GPTMICR_0			REG32(GPTM0 + GPTMICR)
#define	GPTMTAILR_0			REG32(GPTM0 + GPTMTAILR)
#define	GPTMTBILR_0			REG32(GPTM0 + GPTMTBILR)
#define	GPTMTAMATCHR_0		REG32(GPTM0 + GPTMTAMATCHR)
#define	GPTMTBMATCHR_0		REG32(GPTM0 + GPTMTBMATCHR)
#define	GPTMTAPR_0			REG32(GPTM0 + GPTMTAPR)
#define	GPTMTBPR_0			REG32(GPTM0 + GPTMTBPR)
#define	GPTMTAPMR_0			REG32(GPTM0 + GPTMTAPMR)
#define	GPTMTBPMR_0			REG32(GPTM0 + GPTMTBPMR)
#define	GPTMTAR_0			REG32(GPTM0 + GPTMTAR)
#define	GPTMTBR_0			REG32(GPTM0 + GPTMTBR)
#define	GPTMTAV_0			REG32(GPTM0 + GPTMTAV)
#define	GPTMTBV_0			REG32(GPTM0 + GPTMTBV)
#define	GPTMRTCPD_0			REG32(GPTM0 + GPTMRTCPD)
#define	GPTMTAPS_0			REG32(GPTM0 + GPTMTAPS)
#define	GPTMTBPS_0			REG32(GPTM0 + GPTMTBPS)
#define	GPTMTAPV_0			REG32(GPTM0 + GPTMTAPV)
#define	GPTMTBPV_0			REG32(GPTM0 + GPTMTBPV)
#define	GPTMPP_0			REG32(GPTM0 + GPTMPP)


//GPTM Offsets	
#define	GPTMCFG			0x000
#define	GPTMTAMR		0x004
#define	GPTMTBMR		0x008
#define	GPTMCTL			0x00C
#define	GPTMSYNC		0x010
#define	GPTMIMR			0x018
#define	GPTMRIS			0x01C
#define	GPTMMIS			0x020
#define	GPTMICR			0x024
#define	GPTMTAILR		0x028
#define	GPTMTBILR		0x02C
#define	GPTMTAMATCHR	0x030
#define	GPTMTBMATCHR	0x034
#define	GPTMTAPR		0x038
#define	GPTMTBPR		0x03C
#define	GPTMTAPMR		0x040
#define	GPTMTBPMR		0x044
#define	GPTMTAR			0x048
#define	GPTMTBR			0x04C
#define	GPTMTAV			0x050
#define	GPTMTBV			0x054
#define	GPTMRTCPD		0x058
#define	GPTMTAPS		0x05C
#define	GPTMTBPS		0x060
#define	GPTMTAPV		0x064
#define	GPTMTBPV		0x068
#define	GPTMPP			0xFC0


//LaunchPad board peripherals 
#define LED_R PF1
#define LED_G PF3
#define LED_B PF2
#define LED_A REG32(PORTF + 0x38)

#define USR_SW1 PF4
#define USR_SW2 PF0 

#endif
