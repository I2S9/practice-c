#include <libTableauNoir.h>

void monRectangle(int x1, int y1, int x2, int y2){
  choisirTypeStylo(3,255,255,255);
  choisirCouleurPinceau(88,41,0);
  tracerRectangle(x1,y1,x2,y2);
}

int main(){
  creerTableau();
  monRectangle(100,100,200,200);
  attendreClicGauche();
  return 0;
}
