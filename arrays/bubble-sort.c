typedef struct maillon_s maillon_t;
typedef struct liste_s liste_t;

struct maillon_s {
  element_t valeur;
  maillon_t * suivant;
};

struct liste_s {
  maillon_t * premier;
  maillon_t * dernier;
};

void liste_tri_bulle(liste_t * pl) {
  int fini;
  assert(NULL != pl);
  if (pl->premier != pl->dernier) {
    do {
      maillon_t ** ppm = &(pl->premier);
      fini = 1;
      while (NULL != (*ppm)->suivant) {
        if (-1 != element_cmp(&((*ppm)->valeur), &((*ppm)->suivant->valeur))) {
          liste_echanger_maillons(ppm, &((*ppm)->suivant), pl);
          fini = 0;
        }
        else {
          ppm = &((*ppm)->suivant);
        }
      }
    } while (! fini);
  }
}
