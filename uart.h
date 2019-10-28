#ifndef UART_H
#define UART_H

#include "misc.h"

//Enable UART
void enableUART0();

//Transmit one byte
void uartTxByte(int data);

//Transmit a string 
void uartTxString(char* s);

//Convert int to string
char* itoa(int i, char b[]);

#endif
