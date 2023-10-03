#include <libTableauNoir.h>
#include <math.h>
#include <stdlib.h>

/***********************/
/* définition de TYPES */
/***********************/

/* coordonnées dans le plan */
typedef struct {double x; double y;} coord_t;

/* objet mobile défini par une position p et une vitesse v*/
typedef struct {coord_t p; coord_t v;} mobile_t;

/* ballon = objet mobile o avec une masse m */
typedef struct {mobile_t o; double m;} ballon_t;

/* modèle conceptuel : une main et un ballon */
typedef struct {
    mobile_t main;
    ballon_t ballon;    
} modele_t;


/* stylos utilisés pour tracer les objets */
typedef struct {
    tStylo main;
    tStylo ballon;
    tStylo ficelle;
} stylos_t;

/* état du programme :
   contient un modèle conceptuel et des stylos */
typedef struct {
    modele_t modele;
    stylos_t stylos;
    int fini;
} donnees_t;

/********************************/
/* déclaration des fonctions    */
/********************************/

/* initialisation */
modele_t init_modele();
stylos_t init_stylos();

/* les quatre fonctions de la boucle d'animation */
donnees_t initialiser_donnees();
void effacer(donnees_t);
void afficher(donnees_t);
void mettre_a_jour(donnees_t *);
int fini(donnees_t);



/*****************************************************/
/* fonction principale : point d'entrée du programme */
/*****************************************************/

int main()
{
    donnees_t donnees;

    /* ouverture de la fenêtre graphique avec quelques réglages */
    creerTableau();
    fixerModeBufferisation(1);
    fixerTaille(800,600);

    /* initialisation du modèle et des stylos */
    donnees = initialiser_donnees();

    /* boucle d'animation */
    while (! donnees.fini) {
        /* créer l'image sur le buffer */
        afficher(donnees);
        /* afficher le buffer à l'écran */
        tamponner();
        /* effacer le buffer */
        effacer(donnees);
        /* mettre à jour le contenu de la variable donnees */
        mettre_a_jour(&donnees);
    }
    return EXIT_SUCCESS;
}

/* initialisation des données */
donnees_t initialiser_donnees()
{
    donnees_t donnees = { .fini=0 };
    donnees.modele = init_modele();
    donnees.stylos = init_stylos();
    return donnees ;
}

/* initialisation du modèle */
modele_t init_modele()
{
    modele_t m = {main: {p: {0, 0}, v: {0, 0}},
                  ballon: {o: {p: {0, 0}, v: {0, 0}}, m: 1}};
    return m;
}

/* initialisation des stylos */
stylos_t init_stylos()
{
    stylos_t stylos;
    /* création d'un stylo pour la main en mémoire */
    choisirTypeStylo(30,255,255,255);
    /* stockage du stylo */
    stylos.main    = stockerStylo();
    /* idem pour le ballon */
    choisirTypeStylo(60,255,  0,  0);
    stylos.ballon  = stockerStylo();
    /* idem pour la ficelle */
    choisirTypeStylo( 1,  0,255,255);
    stylos.ficelle = stockerStylo();
    return stylos;
}

/* afficher les objets mouvants */
void afficher(donnees_t donnees)
{
    selectionnerStylo(donnees.stylos.ficelle);
    
    selectionnerStylo(donnees.stylos.main);
    
    selectionnerStylo(donnees.stylos.ballon);
    
}

/* effacer les objets mouvants */
void effacer(donnees_t donnees)
{
    selectionnerStylo(donnees.stylos.ballon);
    tracerPoint(22, 22);
    selectionnerStylo(donnees.stylos.main);
    tracerPoint(52, 52);
    selectionnerStylo(donnees.stylos.ficelle);
    tracerSegment(22, 22, 52, 52);
}

/* mettre à jour l'état du programme */
void mettre_a_jour(donnees_t * donnees)
{
    EtatSourisClavier esc = lireEtatSourisClavier();
    // double dt = delta_temps();        

    if (esc.sourisBoutonDroit) {
        donnees->fini = 1;
    }
    
}
