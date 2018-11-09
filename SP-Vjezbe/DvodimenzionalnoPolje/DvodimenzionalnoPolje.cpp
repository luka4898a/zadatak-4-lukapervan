#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define MAXRED 8
#define MAXSTUP 10

int zbroj(int *polje, int red, int stup)
{
	//Zadatak
	return 1;
}

void main()
{
	int red, stup;
	int polje[MAXRED][MAXSTUP];

	FILE *f;
	f = fopen("UlazZaDvodimenzionalnoPolje.txt", "r");
	if (f == NULL) {
		printf("Greška! Datoteka se ne moze otvoriti!");
		return;
	}
	fscanf(f, "%d %d", &red, &stup);

	for (int i = 0; i < red; i++)
		for (int j = 0; j < stup; j++)
			fscanf(f, "%d", &polje[i][j]);

	int zb = zbroj(&polje[0][0], red, stup);
	printf("Zbroj je: %d", zb);
}

