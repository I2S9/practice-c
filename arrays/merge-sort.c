#include <stdio.h>
#include <limits.h>

// Prototype des fonctions auxiliaires
void fusion(int t[], int debut, int milieu, int fin);

void tri_fusion(int t[], int n) {
    if (n < 2) {  // Un tableau d'un seul élément est déjà trié.
        return;
    }

    for (int taille = 1; taille < n; taille *= 2) {
        for (int gauche = 0; gauche < n - taille; gauche += 2 * taille) {
            int milieu = gauche + taille - 1;
            int droite = gauche + 2 * taille - 1;
            if (droite >= n) {  // On s'assure de ne pas dépasser la fin du tableau.
                droite = n - 1;
            }
            fusion(t, gauche, milieu, droite);
        }
    }
}

void fusion(int t[], int debut, int milieu, int fin) {
    int i, j;
    int taille_gauche = milieu - debut + 1;
    int taille_droite = fin - milieu;

    // Utiliser INT_MAX comme marqueur de fin pour éviter de vérifier si l'un des côtés a été complètement parcouru.
    int gauche[taille_gauche + 1], droite[taille_droite + 1];

    for (i = 0; i < taille_gauche; i++) {
        gauche[i] = t[debut + i];
    }
    for (j = 0; j < taille_droite; j++) {
        droite[j] = t[milieu + 1 + j];
    }

    gauche[taille_gauche] = INT_MAX;
    droite[taille_droite] = INT_MAX;

    i = 0;
    j = 0;

    for (int k = debut; k <= fin; k++) {
        if (gauche[i] <= droite[j]) {
            t[k] = gauche[i];
            i++;
        } else {
            t[k] = droite[j];
            j++;
        }
    }
}

// Fonction principale pour tester le tri_fusion
int main() {
    int t[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(t) / sizeof(t[0]);

    tri_fusion(t, n);

    printf("Tableau trié: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");

    return 0;
}
