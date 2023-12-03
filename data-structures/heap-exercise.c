#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

typedef double element_t;

typedef struct {
	element_t *elements;
	int capacite;
	int taille;
} tas_t;

tas_t* creer_tas(int capacite);
int droit(int);
int gauche(int);
int parent(int);
int est_feuille(tas_t t, int i);
void echanger(tas_t *pt, int i, int j);
void descendre(tas_t *pt, int i);
element_t maximum(tas_t *pt);
void ajouter(tas_t *pt, element_t e);
void afficher_tableau(element_t *e, int dim);

int main(void) {
	srand(time(NULL));
	const int dim = 6;
	tas_t *tas_1 = NULL;
	tas_1 = creer_tas(dim);
	double tab_sans_tri[dim];
	double tab_tri_decroissant[dim];
	for (int i = 0; i < dim; i++) {
		tab_sans_tri[i] = (rand() % 10000) * 1.0 / 100;
	}
	printf("Tableau initial non trié de taille %d\n", dim);
	afficher_tableau(tab_sans_tri, dim);
	for (int i = 0; i < dim; i++) {
		ajouter(tas_1, tab_sans_tri[i]);
		afficher_tableau(tas_1->elements, tas_1->taille);
	}
	puts("\nTas final");
	afficher_tableau(tas_1->elements, tas_1->taille);
	for (int i = 0; i < dim; i++) {
		tab_tri_decroissant[i] = maximum(tas_1);
	}
	puts(
			"\nTableau final trié en ordre décroissant\npar suppression successive de la racine du tas");
	afficher_tableau(tab_tri_decroissant, dim);
	return (EXIT_SUCCESS);
}

tas_t* creer_tas(int n) {
	tas_t *res = malloc(sizeof(tas_t));
	res->taille = 0;
	res->elements = (double*) malloc(n * sizeof(double));
	if (res->elements == NULL) {
		perror("creer_tas : echec de l’allocation de memoire");
		res->capacite = 0;
	} else {
		res->capacite = n;
	}
	return (res);
}

int droit(int i) {
	return (2 * i + 2);
}

int gauche(int i) {
	return (2 * i + 1);
}

int parent(int i) {
	return ((i - 1) / 2);
}

int est_feuille(tas_t t, int i) {
	return (gauche(i) > t.taille);
}

void echanger(tas_t *pt, int i, int j) {
	element_t aux;
	assert(NULL != pt);
	assert(NULL != pt->elements);
	assert(i >= 0 && i < pt->taille);
	assert(j >= 0 && j < pt->taille);
	aux = pt->elements[i];
	pt->elements[i] = pt->elements[j];
	pt->elements[j] = aux;
}

void descendre(tas_t *pt, int i) {
	assert(NULL != pt);
	assert(NULL != pt->elements);
	assert(i >= 0);
	if (est_feuille(*pt, i) == 0) {
		int j = gauche(i);
		if (droit(i) < pt->taille) {
			if (pt->elements[j] < pt->elements[j + 1]) {
				j = j + 1;
			}
		}
		if (pt->elements[i] < pt->elements[j]) {
			echanger(pt, i, j);
			descendre(pt, j);
		}
	}
}

void ajouter(tas_t *pt, element_t e) {
	assert(NULL != pt);
	assert(NULL != pt->elements);
	printf("\najout de %.2f\n", e);
	int i;
	if (pt->taille == 0) {
		pt->elements[0] = e;
		pt->taille += 1;
	} else {
		pt->elements[pt->taille] = e;
		i = pt->taille;
		pt->taille += 1;
		while (parent(i) >= 0 && e > pt->elements[parent(i)]) {
			printf("Echange %d %d\n", i, parent(i));
			echanger(pt, i, parent(i));
			i = parent(i);
		}
	}

}

void afficher_tableau(element_t *e, int dim) {
	for (int i = 0; i < dim; i++) {
		printf("%.2f\t", e[i]);
	}
	puts("");
}
element_t maximum(tas_t *pt) {
	element_t res;
	assert(NULL != pt);
	assert(NULL != pt->elements);
	assert(0 < pt->taille);
	res = pt->elements[0];
	pt->elements[0] = pt->elements[pt->taille - 1];
	pt->taille -= 1;
	descendre(pt, 0);
	return (res);
}

void detruire_tas(tas_t *pt) {
	assert(NULL != pt);
	free(pt->elements);
	pt->capacite = 0;
	pt->taille = 0;
	free(pt); // A vérifier
}
