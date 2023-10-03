#include <libTableauNoir.h>
#include <math.h>    /* compiler avec l'option « -lm » */

typedef struct {
	double x;
	double y;
} coord_t;

typedef struct {
	coord_t centre;
	double angle;
	double longueur;
} aiguille_t;

typedef struct {
	double secondes;
        double minutes;
	aiguille_t aiguille_secondes;
        aiguille_t aiguille_minutes; 
    
} donnees_t;

donnees_t initialiser_donnees();
void afficher(donnees_t donnees);
void mise_à_jour(donnees_t * donnees_p);

coord_t calcule_arrivée(coord_t depart, double direction, double longueur) ;

/* fonction principale */
int main()
{
	creerTableau();
	fixerModeBufferisation(1);
	donnees_t donnees = initialiser_donnees(); /* initialisation */
	while (! fermetureDemandee()) {
		afficher(donnees);               /* tracé */
		tamponner();
		effacerTableau();
                mise_à_jour(&donnees);           /* modification des positions */
	}
	return 0;
}

donnees_t initialiser_donnees()
  
{
	donnees_t donnees = {
		.secondes = 0,
		.aiguille_secondes = {.centre = {0, 0}, .angle = M_PI / 2, .longueur = 200},
		.aiguille_minutes = {.centre = {0,0}, .angle = M_PI /2 , .longueur = 100}
	};
        
	return donnees;
}

void afficher(donnees_t d) {
	choisirTypeStylo(1, 255, 0, 255);
	coord_t arrivée = calcule_arrivée(d.aiguille_secondes.centre,
	                                  d.aiguille_secondes.angle,
	                                  d.aiguille_secondes.longueur);
	
	tracerSegment(d.aiguille_secondes.centre.x, d.aiguille_secondes.centre.y,
	              arrivée.x, arrivée.y);
	
	choisirTypeStylo(1, 0, 255, 0);
       	tracerSegment(d.aiguille_minutes.centre.x, d.aiguille_minutes.centre.y,
	              arrivée.x, arrivée.y);
}

void mise_à_jour(donnees_t* dp)
{
	/* incrémentation du temps */
	dp->secondes = dp->secondes + 1;
	dp->minutes = dp->minutes + 60;
	/* on ramène les secondes dans l'intervalle [0,60] pour l'aiguille des secondes */
	double secondes = dp->secondes - floor(dp->secondes / 60) * 60;
       	double minutes = dp->minutes - floor(dp->minutes / 3600)  ;
	/* calcul de l'angle de l'aiguille des secondes */
	dp->aiguille_secondes.angle = M_PI / 2 - secondes * (2 * M_PI) / 60 ;
       	dp->aiguille_minutes.angle = M_PI / 2 - minutes * (2 * M_PI) / 3600 ;
}

coord_t calcule_arrivée(coord_t depart, double direction, double longueur)
{
    coord_t p = { .x=depart.x+longueur*cos(direction),
                  .y=depart.y+longueur*sin(direction) };
    return p;
}
