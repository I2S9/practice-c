#include <stdio.h>

void fusionner(int tableau[], int debut, int milieu, int fin) {
    int debutDroit = milieu + 1;

    // Si le tableau est déjà trié
    if (tableau[milieu] <= tableau[debutDroit]) {
        return;
    }

    // Deux pointeurs pour parcourir les deux moitiés
    while (debut <= milieu && debutDroit <= fin) {
        // Si l'élément de gauche est en place
        if (tableau[debut] <= tableau[debutDroit]) {
            debut++;
        } else {
            int valeur = tableau[debutDroit];
            int index = debutDroit;

            // Déplacer tous les éléments entre les éléments tableau[debut] et tableau[debutDroit] à droite de leur position actuelle
            while (index != debut) {
                tableau[index] = tableau[index - 1];
                index--;
            }
            tableau[debut] = valeur;

            // Mettre à jour tous les pointeurs
            debut++;
            milieu++;
            debutDroit++;
        }
    }
}

void triFusionIteratif(int tableau[], int tailleTableau) {
    int tailleSousTableau;  // Taille des sous-tableaux à fusionner
    int debutGauche; // Pour choisir le tableau de gauche à fusionner

    // Fusionner les sous-tableaux en bas vers le haut. La taille des sous-tableaux double à chaque itération.
    for (tailleSousTableau = 1; tailleSousTableau <= tailleTableau - 1; tailleSousTableau = 2 * tailleSousTableau) {
        // Choisir le début du sous-tableau de gauche que nous allons fusionner
        for (debutGauche = 0; debutGauche < tailleTableau - 1; debutGauche += 2 * tailleSousTableau) {
            // Trouver la fin du sous-tableau de gauche
            // milieu+1 est le début du sous-tableau de droite
            int milieu = debutGauche + tailleSousTableau - 1;
            int finDroite = (debutGauche + 2 * tailleSousTableau - 1 < tailleTableau - 1) ? (debutGauche + 2 * tailleSousTableau - 1) : (tailleTableau - 1);

            // Fusionner les sous-tableaux tableau[debutGauche...milieu] et tableau[milieu+1...finDroite]
            fusionner(tableau, debutGauche, milieu, finDroite);
        }
    }
}

int main() {
    int tableau[] = {12, 11, 13, 5, 6, 7};
    int tailleTableau = sizeof(tableau) / sizeof(tableau[0]);

    triFusionIteratif(tableau, tailleTableau);

    printf("Tableau trié : \n");
    for (int i = 0; i < tailleTableau; i++)
        printf("%d ", tableau[i]);
    printf("\n");

    return 0;
}
