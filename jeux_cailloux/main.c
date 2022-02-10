#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// prototype des focntion
void nbCaillouxBot(int *nombreDeCailloux, int *difficulte);
void nbCaillouxUser(int *nombreDeCailloux);
void initialisationPartie(int *quiCommence, int *combienDeCailloux);

// fonction principale
int main(int argc, char const *argv[])
{
    int nombreDeCailloux = 0, recommencer = 1, player1 = 0, difficulte = 0;

    
    while (recommencer == 1) // boucle tant que le joueur ne veut pas arreter de jouer
    {
        initialisationPartie(&player1, &nombreDeCailloux); // fonction initialisation
        printf("veuillez choisir une difficulté\nnormal 1)\nIMPOSSIBLE 2)\n");
        scanf("%d", &difficulte); 
        while (nombreDeCailloux >= 0) // boucle tant qu'il reste de la caillasse
        {
            if (player1 == 1) // si c'est le joueur 1 qui commence 
            {
                nbCaillouxUser(&nombreDeCailloux);
                if (nombreDeCailloux <= 0)
                {
                    printf("vous avez perdu\n");
                    break; // permet de sortir de la boucle 
                }
                nbCaillouxBot(&nombreDeCailloux,&difficulte);
                if (nombreDeCailloux <= 0)
                {
                    printf("vous avez gagner\n");
                    break;
                } 
            }
            else // sinon si l'adversaire commence
            {
                nbCaillouxBot(&nombreDeCailloux,&difficulte);
                if (nombreDeCailloux <= 0)
                {
                    printf("vous avez gagner\n");
                    break;
                }
                nbCaillouxUser(&nombreDeCailloux);
                if (nombreDeCailloux <= 0)
                {
                    printf("vous avez perdu\n");
                    break;
                } 
            }
            
        }
        printf("Voulez-vous rejouer ?\noui taper 1 sinon taper 2\n\n\n");
        scanf("%d",&recommencer);
    }
    
    
    return 0;
}

// fonction de l'action de l'adversaire
void nbCaillouxBot(int *nombreDeCailloux, int *difficulte)
{
    int nb = 0;
    const int MAX = 3, MIN = 1;
    srand(time(NULL));
    nb = (rand() % (MAX - MIN + 1)) + MIN;
    if (*difficulte == 2)
    {
        switch (*nombreDeCailloux) // système autoWin 
        {
        case 8:
            nb = 3;
            break;
        case 7:
            nb = 2;
            break;
        case 6:
            nb = 1;
            break;
        case 5:
            nb = 1;
            break;
        case 4:
            nb = 3;
            break;
    
        default:
            break;
        }
    }
    
    if ((*nombreDeCailloux <= 3) && (*nombreDeCailloux > 1)) // pour pas qu'il envoie une valeur debile

    nb = (*nombreDeCailloux-1);
    else if (*nombreDeCailloux == 1)
    {
        nb = 1;
    }
    *nombreDeCailloux -= nb;
    
    printf("votre adversaire a prit %d cailloux, il reste donc %d cailloux\n", nb, *nombreDeCailloux);
}

// fonction qui permet de faire jouer l'utilisateur
void nbCaillouxUser(int *nombreDeCailloux)
{
    int nombre = 0;
    printf("veuillze choisir un nombre entre 1, 2 et 3\n");
    scanf("%d", &nombre);
    while (nombre > 3) // permet d'empecher les gruges
    {
        printf("JE T'ES DIS ENTRE 1 ET 3\n");
        scanf("%d", &nombre);
    }

    while (nombre > *nombreDeCailloux) // empêche de faire des choses impossible
    {
        printf("ÇA T'AMUSE DE VOULOIR PRENDRE PLUS DE CAILLOUX QU'IL Y EN RESTE??????\nil reste %d cailloux gros batard\n",*nombreDeCailloux);
        scanf("%d",&nombre);
    }
    *nombreDeCailloux -= nombre;
    
}

// fonction qui permet de definir les paramètre de la partie
void initialisationPartie(int *quiCommence, int *combienDeCailloux)
{
    int transi1 = 0, transi2 = 0; 
    printf("voulez vous commencer ?\nsi oui taper 1 sinon taper 2\n");
    scanf("%d", &transi1); 
    printf("avec combien de cailloux voulez vous faire la partie ?\n");
    scanf("%d", &transi2);
    *quiCommence = transi1; // transmet la valeur au pointeur
    *combienDeCailloux = transi2; // transmet la valeur au pointeur
}