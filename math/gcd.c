#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pgcd(int a; int b){
    if(b==0){
        return a;
    }
    return pgcd(b, a%b);
}
