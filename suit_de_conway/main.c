#include <stdio.h>

int main(int argc, char const *argv[])
{
    int suit[2000] = {1}, suitTransi[2000] = {0}; // nombre de caractère possible
    int combien = 0;
    int nombre1 = 0, nombre2 = 0, nombre3 = 0; // variable des nombres qui se suivent dans la suite
    int a = 0, b = 0, c = 0;                   // variable compteur

    printf("combien de terme(s) de la suite de conway voulez-vous voir ?\n");
    scanf("%d", &combien);
    printf("\n\n");

    if (combien == 1) // pour que ça n'affiche que le 1 car je savais pas comment le mettre ^^'
    {
        printf("%d\n", suit[0]);
    }
    else if (combien > 1)
    {
        printf("%d\n", suit[0]);                 // pour afficher le 1
        for (size_t i = 0; i < combien - 1; i++) // pour savoir combien affihcer de terme
        {
            do
            {
                nombre1 = suit[a];     // correspond au premier terme de la partie etudier
                nombre2 = suit[a + 1]; // correspond au deuxieme terme de la suite etudier
                nombre3 = suit[a + 2]; // correspond au troisieme term de la suite etudier
                // tout les if vont examiner toutes possibilite ex :
                if (nombre1 == nombre2 && nombre1 == nombre3 && nombre1 == 1) // si tout les termes sont egaux et egal a 1
                {
                    suitTransi[b] = 3;     // le premier des 2 termes
                    suitTransi[b + 1] = 1; // le deuxieme des 2 termes
                    a += 3;                // comme on a utiliser 3 termes on etudie les 3 d'après
                }
                else if (nombre1 == nombre2 && nombre1 == nombre3 && nombre1 == 2)
                {
                    suitTransi[b] = 3;
                    suitTransi[b + 1] = 2;
                    a += 3;
                }
                else if (nombre1 == nombre2 && nombre1 == nombre3 && nombre1 == 3)
                {
                    suitTransi[b] = 3;
                    suitTransi[b + 1] = 3;
                    a += 3;
                }
                else if (nombre1 == nombre2 && nombre1 == 1 && nombre1 != nombre3)
                {
                    suitTransi[b] = 2;
                    suitTransi[b + 1] = 1;
                    a += 2; // comme on a utiliser 2 termes on etudie les 2 d'après
                }
                else if (nombre1 == nombre2 && nombre1 == 2 && nombre1 != nombre3)
                {
                    suitTransi[b] = 2;
                    suitTransi[b + 1] = 2;
                    a += 2;
                }
                else if ((nombre1 == nombre2) && (nombre1 == 3) && (nombre1 != nombre3))
                {
                    suitTransi[b] = 2;
                    suitTransi[b + 1] = 3;
                    a += 2;
                }
                else if (nombre1 == 1 && nombre1 != nombre2)
                {
                    suitTransi[b] = 1;
                    suitTransi[b + 1] = 1;
                    a++; // comme on a utiliser 1 terme on etudie le terme d'après
                }
                else if (nombre1 == 2 && nombre1 != nombre2)
                {
                    suitTransi[b] = 1;
                    suitTransi[b + 1] = 2;
                    a++;
                }
                else if (nombre1 == 3 && nombre1 != nombre2)
                {
                    suitTransi[b] = 1;
                    suitTransi[b + 1] = 3;
                    a++;
                }
                b += 2;             // comme a chaque fois nous utilison 2 termes pour ecrire ce que nous avons etudier
            } while (suit[a] != 0); // un simple while aurrais suffit. et nous nous arretons quand le a est sur un 0 c'est a dire une valeur qui n'est pas de la suite

            for (size_t i = 0; i < b; i++) // permet d'associer les termes de la suite qui etait en cours de création a la suite principale pour que ca soit elle qui soit etudier par la suite
            {
                suit[i] = suitTransi[i];
                printf("%d", suit[i]); // afficher le terme en question
            }

            printf("\n"); // pour ecrire un terme par ligne
            b = 0;        // reinitialisation des valeurs
            a = 0;
        }
    }

    return 0;
}
