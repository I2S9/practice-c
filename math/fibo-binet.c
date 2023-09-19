//Cette fonction calcule les nombres de Fibonacci à partir du nombre d'or

  fonction fibonacci(n)
	phi = (1+sqrt(5))/2
	retourner (phi^n-(-phi)^(-n))/sqrt(5)


#include "bibonacci.h"
#include <math.h>

long nth_bibonacci(long n) {
	if(n < 0) return -1;
	if(n < 2) return n;
	return (pow(1 + sqrt(5), n) - pow(1 - sqrt(5), n)) / (pow(2, n) * sqrt(5));	
}

Entrer un entier n.
Sortie fn
def FiboBinet(n) :
  racine5 = 5 ∗ ∗(1/2)
  phi = (1 + racine5)/2
  phi′ = (1 − racine5)/2
  return ((phi ∗ ∗n) − (phi′ ∗ ∗n))/racine5


  // Fibonacci :

Algorithm 13 (Suite de Fibonacci)
Entrer un entier n.
Sortie fn
def Fibo(n) :
  if n <= 1 :
    if n == 0 :
      return 0
    else :
      return 1
    else :
      return F ibo(n − 1) + F ibo(n − 2) :


Algorithm 14 (Suite de Fibonacci avec m´emo¨ısation)
Entrer un entier n.
Sortie fn
def FiboMem(n) :
if n == 0 :
return 0
else :
tab = [0 for i in range(n+1)]
// création d’un tableau de longueur n+1, initialis´e `a 0, destin´e `a ce que tab[i] = fi
tab[1]=1
for i in range(2, n + 1) :
tab[i] = tab[i − 1] + tab[i − 2]
return tab[n]






