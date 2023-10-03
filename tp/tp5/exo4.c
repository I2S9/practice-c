#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {double x; double y;} coord_t;

double norme(coord_t u);
double norme(coord_t u)
{
  double norme_vecteurs = sqrt(pow(u.x), pow(u.y));
  printf("norme OM : %lf\n", norme_vecteurs);
}

//Fonction produit

coord_t mult(double a, coord_t u);
coord_t mult(double a, coord_t u){
  
  double produit = a *donnees->modele.main.p.u, 2,donnees->modele.main.p.u;
  printf("produit 2.OM : (%f,%f)\n", mult(2,donnees->modele.main.p).x, mult(2,donnees->modele.main.p).y);
}


//Fonction somme
coord_t plus(coord_t a, coord_t b);
coord_t plus(coord_t a, coord_t b){
  double somme = (a.x + b.x, a.y + b.y);

}

//Fonction vecteur
coord_t vect(coord_t A, coord_t B);
coord_t vect(coord_t A, coord_t B){
  double calcul_coord = (B.x - A.x)/(B.y - A.y);
}

//Fonction distance
double dist(coord_t A, coord_t B);
double dist(coord_t A, coord_t B){
  return 
}

