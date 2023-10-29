#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N (1 << 5)

/*
 * type et fonction utilises pour le comptage des operations
 */
enum operation_e {
    GET,
    RAZ,
    INCREMENTER
};

int compteur(enum operation_e);

/*
 * definition du type element_t et declaration des
 * differentes fonctions de comparaison d'elements
 */
typedef int element_t;

int element_inferieur(element_t, element_t);
int element_infouegal(element_t, element_t);
int element_superieur(element_t, element_t);
int element_supouegal(element_t, element_t);

/*
 * declaration des fonctions implementant les differentes
 * variantes du tri fusion et de leurs fonctions auxiliaires
 */
void tri_fusion(element_t[], element_t[], int, int);
void tri_fusion2(element_t[], int, int);
void tri_fusion_iter(element_t[], element_t[], int, int);
void tri_fusion_iter2(element_t[], int, int);
void fusionner(element_t[], element_t[], int, int, int);
void fusionner2(element_t[], int, int, int);

/*
 * definition de la fonction main
 */

int main() {
    element_t t[N];
    element_t aux[N];
    int i, n;
    
    /* initialisation du generateur de nombres pseudo-aleatoires */
    srand(123);

    /* initialisation du tableau avec des valeurs aleatoires */
    for(i = 0; i < N; ++i)
        t[i] = rand() % 512;
    
    /* affichage des elements du tableau */
    for(i = 0; i < N; ++i)
        printf("%4d", t[i]);
    putchar('\n');
    
    /* initialisation du compteur de comparaisons */
    compteur(RAZ);
    
    /* tri fusion */
    tri_fusion(t, aux, 0, N-1);
    
    /* affichage des elements du tableau */
    for(i = 0; i < N; ++i)
        printf("%4d", t[i]);
    putchar('\n');
    
    /* experiences */
    printf("N;NbComp;ValeurTheorique\n");
    for(n = 1; n <= N; ++n) {
        /* initialisation du tableau avec des valeurs aleatoires */
        for(i = 0; i < n; ++i)
            t[i] = rand();
        /* initialisation du compteur de comparaisons */
        compteur(RAZ);
        /* tri fusion */
        tri_fusion(t, aux, 0, n-1);
        /* affichage du nombre de comparaisons d'elements */
        printf("%d;%d;%d\n",
               n,
               compteur(GET),
               (int)(floorl(log2l(n))*n + 2*n - powl(2, floorl(log2l(n))+1)));
    }

    /* sortie */
    return EXIT_SUCCESS;
}

/*
 * definition de la fonction utilisee pour le comptage des operations
 */

int compteur(enum operation_e op) {
    static int cpt;
    switch (op) {
        case RAZ :
            cpt = 0;
            break;
        case INCREMENTER :
            ++cpt;
            break;
        default :
            ;
    }
    return cpt;
}


/*
 * definition des differentes fonctions de comparaison d'elements
 */

int element_inferieur(element_t x, element_t y) {
    compteur(INCREMENTER);
    return (x < y);
}


int element_infouegal(element_t x, element_t y) {
    compteur(INCREMENTER);
    return (x <= y);
}


int element_superieur(element_t x, element_t y) {
    compteur(INCREMENTER);
    return (x > y);
}


int element_supouegal(element_t x, element_t y) {
    compteur(INCREMENTER);
    return (x >= y);
}


/*
 * definitions des fonctions implementant les differentes
 * variantes du tri fusion et de leurs fonctions auxiliaires
 */

void tri_fusion(element_t t[], element_t aux[], int g, int d) {
    if (g < d) {
        int m = (g + d)/2;
        tri_fusion(t, aux, g, m);
        tri_fusion(t, aux, m+1, d);
        fusionner(t, aux, g, m, d);
    }
}


void tri_fusion2(element_t t[], int g, int d) {
    if (g < d) {
        int m = (g + d)/2;
        tri_fusion2(t, g, m);
        tri_fusion2(t, m+1, d);
        fusionner2(t, g, m, d);
    }
}


void tri_fusion_iter(element_t t[], element_t aux[], int g, int d) {
    int bloc = 1;
    
    while (bloc < d - g + 1) {
        int i = g;
        int j = i + 2*bloc - 1;
        if (j > d)
            j = d;
        while (i + bloc <= d) {
            fusionner(t, aux, i, i + bloc - 1, j);
            i = i + 2*bloc;
            j = i + 2*bloc - 1;
            if (j > d)
                j = d;
        }
        bloc = 2 * bloc;
    }
}


void tri_fusion_iter2(element_t t[], int g, int d) {
    int bloc = 1;
    
    while (bloc < d - g + 1) {
        int i = g;
        int j = i + 2*bloc - 1;
        if (j > d)
            j = d;
        while (i + bloc <= d) {
            fusionner2(t, i, i + bloc - 1, j);
            i = i + 2*bloc;
            j = i + 2*bloc - 1;
            if (j > d)
                j = d;
        }
        bloc = 2 * bloc;
    }
}


void fusionner(element_t t[], element_t aux[], int g, int m, int d) {
    int i, j, k;
    
    for(i = g; i <= m; ++i)
        aux[i] = t[i];
    for(j = m+1; j <= d; ++j)
        aux[j] = t[d + m + 1 - j];
    
    for(i = g, j = d, k = g; k <= d; ++k)
        if (element_inferieur(aux[i], aux[j]))
            t[k] = aux[i++];
        else
            t[k] = aux[j--];
}


void fusionner2(element_t t[], int g, int m, int d) {
    int i = g, j = m+1;
    while (i < d && j <= d) {
        if (element_superieur(t[i], t[j])) {
            int k;
            element_t x = t[j];
            for(k = j; k > i; --k)
                t[k] = t[k-1];
            t[i] = x;
            ++j;
        }
        ++i;
    }
}
