#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct BitFieldExample
{
    unsigned int field1 : 1;
    unsigned int field2 : 2;
    unsigned int field3 : 3;
};

//Practical Code Example in C 

int main()
{
   struct BitFieldExample structExample;

   structExample.field1 = 1; //We can storre values 0-1    
   structExample.field2 = 3; //We can storre values 0-3    
   structExample.field3 = 5; //We can storre values 0-7

   printf("field1: %u, field2: %u, field3: %u\n", structExample.field1, structExample.field2, structExample.field3);

   return 0;    
}
