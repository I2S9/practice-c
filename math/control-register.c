#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// struct BitFieldExample
// {
//     unsigned int field1 : 1;
//     unsigned int field2 : 2;
//     unsigned int field3 : 3;
// };

//32-bit control registerS

typedef struct ControlRegister
{
    unsigned int enableDevice : 1; //Bit 0
    unsigned int resetDevice : 1; //Bit 1 : Reset the device
    unsigned int interruptDevice : 1; //Bit 2 : Enable or disable interrupts
    unsigned int modeSelect : 2; //Bit 3-4 : Select operating mode (00, 01, 10 or 11)
    unsigned int reserved : 27; //Bit 5-31 : Reserved for futur use
}ControlRegister;

int main()
{
    //Declare a control register
    ControlRegister controlReg = { 0 };

    //Enable the device
    controlReg.enableDevice = 1;

    //Select operating mode 3
    controlReg.modeSelect = 3;

    //The size of ControlRegister should be 5 bytes (32 bits)
    printf("Size fo control register is : %lu bytes \n", sizeof(ControlRegister));
    return 0;
}
