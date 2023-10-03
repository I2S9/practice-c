#include <libTableauNoir.h>
#include <stdio.h>

void monRectangle(int x1, int y1, int x2, int y2){
  choisirTypeStylo(3,255,255,255);
  choisirCouleurPinceau(88,41,0);
  tracerRectangle(x1,y1,x2,y2);
}
double  monIsocele(int yc, int yab, int xa, int xb){
  tracerSegment(xa, yab, xb, yab);
  tracerSegment(xa, yab, (xa+xb)/2, yc);
  tracerSegment(xb, yab, (xa+xb)/2, yc);
  return ((xb-xa)*(yc-yab))/2;
}

void maMaison(int yc, int yab, int xa, int xb){
  monIsocele(yc,yab,xa,xb);
  monRectangle(yc,yab,xa,xb);
}

int main(){
  double surface;
  creerTableau();
  // monRectangle(100,100,200,200);
  surface = monIsocele(50,100,90,210);
  monIsocele(-50,-100,-90,-210);
  attendreClicGauche();
  maMaison(50,100,90,210);
  printf("surface = %f\n", surface);
  return 0;
}
