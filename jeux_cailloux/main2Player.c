#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// prototype des focntion
void nbCaillouxBot(int *nombreDeCailloux, int *difficulte);
void nbCaillouxUser(int *nombreDeCailloux);
void initialisationPartie(int *quiCommence, int *combienDeCailloux, int *nombrePlayer);

// fonction principale
int main(int argc, char const *argv[])
{
    int nombreDeCailloux = 0, recommencer = 1, player1 = 0, difficulte = 0, nombrePlayer = 0;

    
    while (recommencer == 1) // boucle tant que le joueur ne veut pas arreter de jouer
    {
        printf("----Le Jeux Du Ramassage De Cailloux----\nle but de ce jeux est de ne pas rammasser le dernier cailloux sinon vous avez perdu !\n");
        initialisationPartie(&player1, &nombreDeCailloux, &nombrePlayer); // fonction initialisation
        while (nombreDeCailloux >= 0) // boucle tant qu'il reste de la caillasse
        {
            if (nombrePlayer == 1)
            {
                printf("veuillez choisir une difficulté\nnormal 1)\nIMPOSSIBLE 2)\n");
                scanf("%d", &difficulte); 
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
            else if (nombrePlayer == 2)
            {
                if (player1 == 1) // si joueur 1
                {   
                    printf("Au PLAYER 1 de jouer");
                    nbCaillouxUser(&nombreDeCailloux);
                    if (nombreDeCailloux <= 0)
                    {
                        printf("PLAYER 2 à gagner !\n");
                        break; // permet de sortir de la boucle 
                    }
                    printf("Au PLAYER 2 de jouer");
                    nbCaillouxUser(&nombreDeCailloux);
                    if (nombreDeCailloux <= 0)
                    {
                        printf("PLAYER 1 à gagner !\n");
                        break;
                    } 
                }
                else // sinon si PLAYER 2 commence
                {
                    printf("Au PLAYER 2 de jouer");
                    nbCaillouxUser(&nombreDeCailloux);
                    if (nombreDeCailloux <= 0)
                    {
                        printf("PLAYER 1 à gagner !\n");
                        break;
                    }
                    printf("Au PLAYER 1 de jouer");
                    nbCaillouxUser(&nombreDeCailloux);
                    if (nombreDeCailloux <= 0)
                    {
                        printf("PLAYER 2 à gagner !\n");
                        break;
                    } 
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
    printf("\nveuillze choisir un nombre entre 1, 2 et 3\n");
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
    printf("il rest %d cailloux\n\n", *nombreDeCailloux);
    
}

// fonction qui permet de definir les paramètre de la partie
void initialisationPartie(int *quiCommence, int *combienDeCailloux, int *nombrePlayer)
{
    printf("Voulez-vous jouer tout seul ou a 2 ?\n1 PLAYER\n2 PLAYER\n");
    scanf("%d", nombrePlayer);
    while (!(*nombrePlayer == 1 || *nombrePlayer == 2))
    {
        printf("POUR UN JOUER TAP 1, POUR DEUX JOUEUR TAP 2\n");
        scanf("%d", nombrePlayer);
    }
    if (*nombrePlayer == 1)
    {
        printf("voulez vous commencer ?\nsi oui taper 1 sinon taper 2\n");
        scanf("%d", quiCommence); 
        printf("avec combien de cailloux voulez vous faire la partie ?\n");
        scanf("%d", combienDeCailloux);
    }
    else if (*nombrePlayer == 2)
    {
        printf("Qui commence ?\nPLAYER 1\nPLAYER 2\n");
        scanf("%d", quiCommence); 
        while (!(*quiCommence == 1 || *quiCommence ==2))
        {
            printf("Veuillez choisir un nombre entre 1 et 2\n");
            scanf("%d", quiCommence); 
        }
        
        printf("avec combien de cailloux voulez vous faire la partie ?\n");
        scanf("%d", combienDeCailloux);
        while (*combienDeCailloux <= 0)
        {
            printf("Veuillez choisir un nombre de cailloux superieur a 0\n");
            scanf("%d", combienDeCailloux);
        }
        
    }
    
    
}