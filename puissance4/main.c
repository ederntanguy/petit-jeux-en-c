#include <stdio.h>

// prototype
void grille(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);
void jetonJaune(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);
void jetonBleu(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);
int verificationVictoire(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);

// fonction principale
int main(int argc, char const *argv[])
{
    int colone1[7] = {0}, colone2[7] = {0}, colone3[7] = {0}, colone4[7] = {0}, colone5[7] = {0}, colone6[7] = {0}, colone7[7] = {0}; // initialisation des 7 colonnes qui vont former la grille
    int player = 0, verif = 0;                                                                                                        // verif sert de condition de victoire

    colone1[6] = 3, colone2[6] = 3, colone3[6] = 3, colone4[6] = 3, colone4[6] = 3, colone5[6] = 3, colone6[6] = 3, colone7[6] = 3; // permet de d'etre detecter pour les fonctions jetonJaune et jetonBleu
    printf("Bienvenu dans le jeux puissance 4 qui se joue a 2\n");
    // condition de fin
    while (verif == 0)
    {
        grille(colone1, colone2, colone3, colone4, colone5, colone6, colone7); // afficher la grille
        if (player == 0)                                                       // faire jouer le joueur 1
        {
            jetonJaune(colone1, colone2, colone3, colone4, colone5, colone6, colone7);                   // demander au joueur 1 de jouer
            player++;                                                                                    // faire en sorte de que ça change de joueur
            verif = verificationVictoire(colone1, colone2, colone3, colone4, colone5, colone6, colone7); // verifie si le joueur a gagner
        }
        else if (player == 1)
        {
            jetonBleu(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
            player--;
            verif = verificationVictoire(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
        }
    }
    grille(colone1, colone2, colone3, colone4, colone5, colone6, colone7); // afficher une derniere fois la grille finale
    if (player == 0)
    {
        printf("Bravo joueur 2 tu as gagner !\n");
    }
    else if (player == 1)
    {
        printf("Bravo joueur 1 tu as gagner !\n");
    }

    return 0;
}

// fonction qui créé la grille et l'affiche
void grille(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[])
{
    printf("numeros colonnes : 1 2 3 4 5 6 7\n\n"); // permet d'indiquer au joueur le numeros a rentrer pour la colonnes
    for (size_t i = 0; i < 6; i++)                  // boucle pour afficher toute les ligne du plateau
    {
        printf("                   %d %d %d %d %d %d %d\n", colone1[i], colone2[i], colone3[i], colone4[i], colone5[i], colone6[i], colone7[i]); // affichage de la grilles pour qu'elle tombe pille en face des numeros
    }
}

// demande au joueur un ou veut-il place sont jeton et le met a l'emplacement demander
void jetonJaune(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[])
{
    int numerosColonnes = 0;
    int remp1 = 0;
    int i;
    i = 0;

    printf("\nJoueur 1 dans quelles colonnes voulez-vous mettre votre jeton\n");
    scanf("%d", &numerosColonnes);                          // savoir ou le jeton va être place
    while (!(numerosColonnes >= 1 && numerosColonnes <= 7)) // au cas ou il ne rentre pas un numeros entre 1 er 7
    {
        printf("Veuillez choisir un nombre entre 1 et 7\n");
        scanf("%d", &numerosColonnes);
    }
    switch (numerosColonnes) // modifier le tableau a l'endroit indiquer
    {
    case 1:                // si dans la premier colonne
        while (remp1 == 0) // tant qu'il ne tombe pas sur une valeurs autre que 0 il va regarder plus ba, pour savoir la position ou il devra place le jeton
        {
            remp1 = colone1[i];
            i++; // permet de compter la position du jeton deja place le plus haut
        }
        remp1 = 0;          // reinitialiser pour qu'il retourne dans la fonction
        colone1[i - 2] = 1; // le premier -1 car le while le fait un fois a la fin, et le 2eme car l'indice d'un tableau commence a 1, et donc permet de mettre le jeton a la place demander
        break;
    case 2:
        while (remp1 == 0)
        {
            remp1 = colone2[i];
            i++;
        }
        remp1 = 0;
        colone2[i - 2] = 1;
        break;
    case 3:
        while (remp1 == 0)
        {
            remp1 = colone3[i];
            i++;
        }
        remp1 = 0;
        colone3[i - 2] = 1;
        break;
    case 4:
        while (remp1 == 0)
        {
            remp1 = colone4[i];
            i++;
        }
        remp1 = 0;
        colone4[i - 2] = 1;
        break;
    case 5:
        while (remp1 == 0)
        {
            remp1 = colone5[i];
            i++;
        }
        remp1 = 0;
        colone5[i - 2] = 1;
        break;
    case 6:
        while (remp1 == 0)
        {
            remp1 = colone6[i];
            i++;
        }
        remp1 = 0;
        colone6[i - 2] = 1;
        break;
    case 7:
        while (remp1 == 0)
        {
            remp1 = colone7[i];
            i++;
        }
        remp1 = 0;
        colone7[i - 2] = 1;
        break;

    default:
        break;
    }
}

// demande au joueur un ou veut-il place sont jeton et le met a l'emplacement demander(pour l'autre joueur)
// exactement le même docntionnement que la foncttion jetonJaune
void jetonBleu(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[])
{
    int numerosColonnes = 0;
    int remp1 = 0;
    int i;
    i = 0;

    printf("\nJoueur 2 dans quelles colonnes voulez-vous mettre votre jeton\n");
    scanf("%d", &numerosColonnes);
    while (!(numerosColonnes >= 1 && numerosColonnes <= 7))
    {
        printf("Veuillez choisir un nombre entre 1 et 7\n");
        scanf("%d", &numerosColonnes);
    }
    switch (numerosColonnes)
    {
    case 1:
        while (remp1 == 0)
        {
            remp1 = colone1[i];
            i++;
        }
        remp1 = 0;
        colone1[i - 2] = 2;
        break;
    case 2:
        while (remp1 == 0)
        {
            remp1 = colone2[i];
            i++;
        }
        remp1 = 0;
        colone2[i - 2] = 2;
        break;
    case 3:
        while (remp1 == 0)
        {
            remp1 = colone3[i];
            i++;
        }
        remp1 = 0;
        colone3[i - 2] = 2;
        break;
    case 4:
        while (remp1 == 0)
        {
            remp1 = colone4[i];
            i++;
        }
        remp1 = 0;
        colone4[i - 2] = 2;
        break;
    case 5:
        while (remp1 == 0)
        {
            remp1 = colone5[i];
            i++;
        }
        remp1 = 0;
        colone5[i - 2] = 2;
        break;
    case 6:
        while (remp1 == 0)
        {
            remp1 = colone6[i];
            i++;
        }
        remp1 = 0;
        colone6[i - 2] = 2;
        break;
    case 7:
        while (remp1 == 0)
        {
            remp1 = colone7[i];
            i++;
        }
        remp1 = 0;
        colone7[i - 2] = 2;
        break;

    default:
        break;
    }
}

// fonction de l'enfer permetant de vérifie si il y a 4 jeton alligne
int verificationVictoire(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[])
{
    int verif = 0;
    // le fonctionnement est tout simple, j'ai mis un shema ex : diagonal, qui va regarder si l'indice avec 1 de difference entre 4 colonnes sont egale, ensuite je vais le verifie n fois vers vers la droite, pour horizontal je vais regarder n fois vers le haut
    for (size_t i = 0; i < 7; i++)
    { // if pour verifier si il y a 4 a la suite dans une diagonal en comparant la position avec une identation d'ecart entre 4 colonnes
        if ((colone1[i] == 1 && colone2[i + 1] == 1 && colone3[i + 2] == 1 && colone4[i + 3] == 1) || (colone1[i] == 2 && colone2[i + 1] == 2 && colone3[i + 2] == 2 && colone4[i + 3] == 2) || (colone2[i] == 1 && colone3[i + 1] == 1 && colone4[i + 2] == 1 && colone5[i + 3] == 1) || (colone2[i] == 2 && colone3[i + 1] == 2 && colone4[i + 2] == 2 && colone5[i + 3] == 2) || (colone3[i] == 1 && colone4[i + 1] == 1 && colone5[i + 2] == 1 && colone6[i + 3] == 1) || (colone3[i] == 2 && colone4[i + 1] == 2 && colone5[i + 2] == 2 && colone6[i + 3] == 2) || (colone4[i] == 1 && colone5[i + 1] == 1 && colone6[i + 2] == 1 && colone7[i + 3] == 1) || (colone4[i] == 2 && colone5[i + 1] == 2 && colone6[i + 2] == 2 && colone7[i + 3] == 2) || (colone1[i + 1] == 1 && colone2[i + 2] == 1 && colone3[i + 3] == 1 && colone4[i + 4] == 1) || (colone1[i + 1] == 2 && colone2[i + 2] == 2 && colone3[i + 3] == 2 && colone4[i + 4] == 2) || (colone2[i + 1] == 1 && colone3[i + 2] == 1 && colone4[i + 3] == 1 && colone5[i + 4] == 1) || (colone2[i + 1] == 2 && colone3[i + 2] == 2 && colone4[i + 3] == 2 && colone5[i + 4] == 2) || (colone3[i + 1] == 1 && colone4[i + 2] == 1 && colone5[i + 3] == 1 && colone6[i + 4] == 1) || (colone3[i + 1] == 2 && colone4[i + 2] == 2 && colone5[i + 3] == 2 && colone6[i + 4] == 2) || (colone4[i + 1] == 1 && colone5[i + 2] == 1 && colone6[i + 3] == 1 && colone7[i + 4] == 1) || (colone4[i + 1] == 2 && colone5[i + 2] == 2 && colone6[i + 3] == 2 && colone7[i + 4] == 2) || (colone1[6 - i] == 1 && colone2[5 - i] == 1 && colone3[4 - i] == 1 && colone4[3 - i] == 1) || (colone1[6 - i] == 2 && colone2[5 - i] == 2 && colone3[4 - i] == 2 && colone4[3 - i] == 2) || (colone2[6 - i] == 1 && colone3[5 - i] == 1 && colone4[4 - i] == 1 && colone5[3 - i] == 1) || (colone2[6 - i] == 2 && colone3[5 - i] == 2 && colone4[4 - i] == 2 && colone5[3 - i] == 2) || (colone3[6 - i] == 1 && colone4[5 - i] == 1 && colone5[4 - i] == 1 && colone6[3 - i] == 1) || (colone3[6 - i] == 2 && colone4[5 - i] == 2 && colone5[4 - i] == 2 && colone6[3 - i] == 2) || (colone4[6 - i] == 1 && colone5[5 - i] == 1 && colone6[4 - i] == 1 && colone7[3 - i] == 1) || (colone4[6 - i] == 2 && colone5[5 - i] == 2 && colone6[4 - i] == 2 && colone7[3 - i] == 2))
        {
            verif = 1; // si la condition est verifie elle va valider la variable de victoir
            return verif;
        } // pour savoir si il y en a 4 d'alligné horizontallement
        else if ((colone1[i] == 1 && colone2[i] == 1 && colone3[i] == 1 && colone4[i] == 1) || (colone1[i] == 2 && colone2[i] == 2 && colone3[i] == 2 && colone4[i] == 2) || (colone2[i] == 1 && colone3[i] == 1 && colone4[i] == 1 && colone5[i] == 1) || (colone2[i] == 2 && colone3[i] == 2 && colone4[i] == 2 && colone5[i] == 2) || (colone3[i] == 1 && colone4[i] == 1 && colone5[i] == 1 && colone6[i] == 1) || (colone3[i] == 2 && colone4[i] == 2 && colone5[i] == 2 && colone6[i] == 2) || (colone4[i] == 1 && colone5[i] == 1 && colone6[i] == 1 && colone7[i] == 1) || (colone4[i] == 2 && colone5[i] == 2 && colone6[i] == 2 && colone7[i] == 2))
        {
            verif = 1;
            return verif;
        } // pour savoir si il y en a 4 d'alligné verticallement
        else if ((colone1[i] == 1 && colone1[i + 1] == 1 && colone1[i + 2] == 1 && colone1[i + 3] == 1) || (colone1[i] == 2 && colone1[i + 1] == 2 && colone1[i + 2] == 2 && colone1[i + 3] == 2) || (colone2[i] == 1 && colone2[i + 1] == 1 && colone2[i + 2] == 1 && colone2[i + 3] == 1) || (colone2[i] == 2 && colone2[i + 1] == 2 && colone2[i + 2] == 2 && colone2[i + 3] == 2) || (colone3[i] == 1 && colone3[i + 1] == 1 && colone3[i + 2] == 1 && colone3[i + 3] == 1) || (colone3[i] == 2 && colone3[i + 1] == 2 && colone3[i + 2] == 2 && colone3[i + 3] == 2) || (colone4[i] == 1 && colone4[i + 1] == 1 && colone4[i + 2] == 1 && colone4[i + 3] == 1) || (colone4[i] == 2 && colone4[i + 1] == 2 && colone4[i + 2] == 2 && colone4[i + 3] == 2) || (colone5[i] == 1 && colone5[i + 1] == 1 && colone5[i + 2] == 1 && colone5[i + 3] == 1) || (colone5[i] == 2 && colone5[i + 1] == 2 && colone5[i + 2] == 2 && colone5[i + 3] == 2) || (colone6[i] == 1 && colone6[i + 1] == 1 && colone6[i + 2] == 1 && colone6[i + 3] == 1) || (colone6[i] == 2 && colone6[i + 1] == 2 && colone6[i + 2] == 2 && colone6[i + 3] == 2) || (colone7[i] == 1 && colone7[i + 1] == 1 && colone7[i + 2] == 1 && colone7[i + 3] == 1) || (colone7[i] == 2 && colone7[i + 1] == 2 && colone7[i + 2] == 2 && colone7[i + 3] == 2))
        {
            verif = 1;
            return verif;
        }

        else
        {
            verif = 0;
        }
    }
    return verif;
}