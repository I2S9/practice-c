#include <libTableauNoir.h>
#include <math.h>    /* compiler avec l'option « -lm » */

EtatSourisClavier esc = lireEtatSourisClavier();

typedef struct {
	double x;
	double y;
} coord_t;

typedef struct {
	int affiche;
	coord_t position;
} donnees_t;

donnees_t initialiser_donnees();
void afficher(donnees_t donnees);
void mise_à_jour(donnees_t * donnees_p);


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
                mise_à_jour(&donnees);           /* modification */
	}
	return 0;
}

donnees_t initialiser_donnees()
{
	donnees_t donnees = {
		.affiche = 1,
		.position = {0, 0}
	};
	return donnees;
}

void afficher(donnees_t d) {
	if (d.affiche) {
		choisirTypeStylo(50, 255, 0, 255);
		tracerPoint(d.position.x, d.position.y);
	}
}

void mise_à_jour(donnees_t* dp)
{
	EtatSourisClavier esc = lireEtatSourisClavier();
	dp->affiche = 1;
	if (esc.touchesClavier[20] == 1)
	{
		dp->affiche = 0;
	}
}
