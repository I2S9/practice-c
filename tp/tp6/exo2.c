#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  char *c = argv[1];
  FILE *d = fopen(c, "r");
  if(d == NULL){
    printf("Impossible d'ouvrir le dossier :%s\n", c);
  }

  int nb_lignes = 0;
  int nb_mots = 0;
  int nb_bits = 0;
  int mot = 0;
  int v;

  while((v = fgetc(d)) != EOF){
    nb_bits++;
    if(v == '\n'){
      nb_lignes++;
    }
    if(v == ' ' || v == '\t' || v == '\n'){
      mot = 0;
    }
    else if(mot == 0){
      mot = 1;
      nb_mots++;
    }
 }

  fclose(d);
  printf("%d %d %d %s\n", nb_lignes, nb_mots, nb_bits, c);
}
