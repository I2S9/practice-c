//Cette fonction calcule les nombres de Fibonacci à partir du nombre d'or

#include "bibonacci.h"
#include <math.h>

long nth_bibonacci(long n) {
	if(n < 0) return -1;
	if(n < 2) return n;
	return (pow(1 + sqrt(5), n) - pow(1 - sqrt(5), n)) / (pow(2, n) * sqrt(5));	
}

int fibo_binet(int n)
{
    double sqrt5 = sqrt(5);

    int resultat = (int)( pow((1 + sqrt5), n) - pow((1 - sqrt5), n) ) / (int)( pow(2, n) * sqrt5 );
    return resultat;
}

