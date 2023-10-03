#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int a;
    int b;
    int c;
}nombre_s;

struct nombre_s puissance(struct nombre_s x, int n){
    if(n==0){
        return 1;
    }
    return x*puissance(x,n-1);
}
