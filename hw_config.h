#ifndef HW_CONFIG_H
#define HW_CONFIG_H

//Set oscillator freq to 50 MHz
void setFreq50();

//Set oscillator freq to 80 MHz
void setFreq80();

//Enable PWM A in Timer 0
void enablePWM0();

//Configure Control Lines
void cfgCtrlLines();

//Configure all GPIO as Tristate
void setBusTrisate();

//Enable data bus
void enableDataBus();

//Enable addr bus
void enableAddrBus()

//Send value to data bus
void dataBusWrite(int data);

//Send value to data bus
void addrBusWrite(int data)

//Disable Video RAM and and addr. counter
void holdBus();


#endif
