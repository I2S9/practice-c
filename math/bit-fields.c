#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// struct{
//     type[member_name]: width;
// };

struct BitFieldExample{
    unsigned int field1 : 1; 
    unsigned int field2 : 2;
    unsigned int field3 : 3;
};
