#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int main()
{
    srand(time(NULL));
    int nbRandom = rand()%(MAX+1);
    int nbUser;
    printf("###################################################################################\n");
    printf("#                                                                                 #\n");
    printf("#                                                                                 #\n");
    printf("#                          BIENVENUE DANS LE JUSTE PRIX!                          #\n");
    printf("#                                                                                 #\n");
    printf("#                                                                                 #\n");
    printf("###################################################################################\n\n");
    printf("Veuillez saisir un nombre compris entre 1 et 100 : ");
    scanf("%d", &nbUser);

    while(nbUser != nbRandom)
    {
        if(nbUser>nbRandom)
            printf("Le nombre choisi est trop grand !\n");
        else
            printf("Le nombre choisi est trop petit !\n");
        printf("Veuillez entrer a nouveau un nombre : ");          
        scanf("%d", &nbUser);
    }
    printf("Felecitations il s'agit du nombre recherche !");
}
