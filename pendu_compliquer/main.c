#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// prototype
void compterNombreLettre(char motSecret[], int *nombreLettre);
void motCCacher(int *nombreLettre, char chaineCacher[]);
void recupererSaisi(char saisiPlayer[]);
int lire(char *chaine, int longueur);
void verifierLettre(char motSecret[], char saisiPlayer[],char motCacher[],int *coupsRestants, int nombreLettre, int *conditionVictoire);

// toupper(char ch); permet de transformer n'importe quelle lettre en majuscule 

int main(int argc, char const *argv[])
{
    char lettre = 0;
    char motSecret[] = "MANGER", motCacher[25], saisiPlayer[2], bugScanf = 0;
    int coupsRestants = 10, nombreLettre = 0, conditionVictoire = 0;

    compterNombreLettre(motSecret, &nombreLettre);
    motCCacher(&nombreLettre,motCacher);
    conditionVictoire = nombreLettre; // moyen simple pour faire gagner, a chaque lettre trouver il diminu de 1 et quand arriver a 0 c'est win
    // boucle principale 
    while (coupsRestants > 0)
    {
        printf("Voici votre mot cacher\n%s\n", motCacher);
        recupererSaisi(saisiPlayer);
        scanf("%c",&bugScanf); // car je n'arrive pas a gérer un bug de buffer ^^'
        verifierLettre(motSecret,saisiPlayer,motCacher,&coupsRestants,nombreLettre,&conditionVictoire);
        printf("%s\n", motCacher);
        printf("nombre de coups restants %d\n", coupsRestants);
        if (conditionVictoire <= 0) // condition de victoire
        {
            printf("Bravo vous avez trouver le mots qui etait : %s\n", motSecret);
            break;
        }
    }
    if (coupsRestants == 0) // condition de defaite
        printf("t'es mauvais Jack\n");
    
    return 0;
}

// permet de compter le nombre de lettre du mot a chercher
void compterNombreLettre(char motSecret[], int *nombreLettre)
{
    *nombreLettre = strlen(motSecret);
}

// permet de créé une chaine de '*' pour afficher un mot en mode invisible 
void motCCacher(int *nombreLettre, char chaineCacher[])
{
    for (size_t i = 0; i < *nombreLettre; i++)
    {
        chaineCacher[i] = '*';
    }    
}

// permet de recuperer et modifier le saisi de l'utilisateur
void recupererSaisi(char saisiPlayer[])
{
    char lettre = 0;
    printf("Entrer une lettre\n");
    lire(saisiPlayer,2);
    saisiPlayer[0] = toupper(saisiPlayer[0]); // troupper de la biblio <ctype.h> permet de mettre en majuscule les lettres saisis
}

// une fonction avance pour recuperer un saisi
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
 
    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
}

// permet de voir si la lettre saisi appartient au mot et de rendre visible cette lettre, et de mettre a jour les données importantes
void verifierLettre(char motSecret[], char saisiPlayer[],char motCacher[],int *coupsRestants, int nombreLettre, int *conditionVictoire)
{
    int lettreTrouver = 0; // permet de savoir si une lettre a été trouver et donc qu'il ne faut pas decendre la vie
    for (size_t i = 0; i < nombreLettre; i++) // boucle qui analyse chacun des caractère du mot avec le saisi pour voir si elles correpondes
    {
        if (motSecret[i] == saisiPlayer[0])
        {
            motCacher[i] = motSecret[i];
            lettreTrouver = 1;
            *conditionVictoire -= 1; // permet de mettre a jour la condition de victoir qui arrive a 0 quand toute les lettres sont trouvées
        }    
    }
    if (lettreTrouver != 1) // si aucune lettre n'a été trouvée il faut diminuer la vie du joueur
        *coupsRestants -= 1;
    lettreTrouver = 0;
}