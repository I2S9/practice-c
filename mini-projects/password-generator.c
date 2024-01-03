#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("gestionnaire-mots-de-passe.txt", "w"); 
    if(fptr == NULL) {
        printf("Erreur lors de l'ouverture ou de la création du fichier!\n");
        exit(1);
    }
    fclose(fptr);
    return 0;
}

// void generatePasswords(char * password)
// {

// }
