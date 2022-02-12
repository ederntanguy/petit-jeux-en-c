#include <stdio.h>

void grille(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);
void jetonJaune(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);
void jetonBleu(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);
int verificationVictoire(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[]);

int main(int argc, char const *argv[])
{
	int colone1[7] = {0}, colone2[7] = {0}, colone3[7] = {0}, colone4[7] = {0}, colone5[7] = {0}, colone6[7] = {0}, colone7[7] = {0};
	int player = 0, verif = 0;

	colone1[6] = 3, colone2[6] = 3, colone3[6] = 3, colone4[6] = 3, colone4[6] = 3, colone5[6] = 3, colone6[6] = 3, colone7[6] = 3;

	while (verif == 0)
	{
		grille(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
		if (player == 0)
		{
			jetonJaune(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
			player++;
			verif = verificationVictoire(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
			printf("verif = %d\n", verif);
		}
		else if (player == 1)
		{
			jetonBleu(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
			player--;
			verif = verificationVictoire(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
			printf("verif = %d\n", verif);
		}
	}
	grille(colone1, colone2, colone3, colone4, colone5, colone6, colone7);
	return 0;
}

void grille(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[])
{
	printf("numeros colonnes : 1 2 3 4 5 6 7\n\n");
	for (size_t i = 0; i < 6; i++)
	{
		printf("                   %d %d %d %d %d %d %d\n", colone1[i], colone2[i], colone3[i], colone4[i], colone5[i], colone6[i], colone7[i]);
	}
}

void jetonJaune(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[])
{
	int numerosColonnes = 0;
	int remp1 = 0;
	int i;
	i = 0;

	printf("\nJoueur 1 dans quelles colonnes voulez-vous mettre votre jeton\n");
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
		colone1[i - 2] = 1;
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

int verificationVictoire(int colone1[], int colone2[], int colone3[], int colone4[], int colone5[], int colone6[], int colone7[])
{
	int verif = 0;
	for (size_t i = 0; i < 7; i++)
	{
		if ((colone1[i] == 1 && colone2[i + 1] == 1 && colone3[i + 2] == 1 && colone4[+3] == 1) || (colone1[i] == 2 && colone2[i + 1] == 2 && colone3[i + 2] == 2 && colone4[+3] == 2) || (colone2[i] == 1 && colone3[i + 1] == 1 && colone4[i + 2] == 1 && colone5[i + 3] == 1) || (colone2[i] == 2 && colone3[i + 1] == 2 && colone4[i + 2] == 2 && colone5[i + 3] == 2) || (colone3[i] == 1 && colone4[i + 1] == 1 && colone5[i + 2] == 1 && colone6[i + 3] == 1) || (colone3[i] == 2 && colone4[i + 1] == 2 && colone5[i + 2] == 2 && colone6[i + 3] == 2) || (colone4[i] == 1 && colone5[i + 1] == 1 && colone6[i + 2] == 1 && colone7[i + 3] == 1) || (colone4[i] == 2 && colone5[i + 1] == 2 && colone6[i + 2] == 2 && colone7[i + 3] == 2))
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