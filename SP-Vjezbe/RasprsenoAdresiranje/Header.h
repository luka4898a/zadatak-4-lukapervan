#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Struktura
typedef struct {
	int sifra;
	char naziv[50 + 1];
	float cijena;
}zapis;

#define MAX 500

//Parametri
#define MAXZAPIS 1000
#define BLOK 512
#define C (int)(BLOK/sizeof(zapis))
#define M (int) ((MAXZAPIS/C) * 1.3)


void prepisi(char *izlaz, char *ulaz);
int upis(int adresa, zapis pom);
int pronadji(int adresa, int sifra, zapis *tmp);