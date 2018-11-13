#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct element {
	char	JMBG[13 + 1];
	char	ImePrezime[40 + 1];
	float	Prihod;
	float	PlatitiPorez;
};
typedef struct element zapis;

// služi samo da bi se dobili podaci za testiranje
int prepisi(char *filenameIn, char *filenameOut) {
	FILE *fin, *fout;
	zapis z;
	int Br;

	fin = fopen(filenameIn, "r");
	fout = fopen(filenameOut, "w");

	if (fin == NULL || fout == NULL) {
		printf("pogreška prilikom prepisivanja podataka");
		return 0;
	}

	fscanf(fin, "%d\n", &Br);
	fwrite(&Br, sizeof(Br), 1, fout);

	while (fscanf(fin, "%s %[^\n] %f %f", z.JMBG, z.ImePrezime, &(z.Prihod), &(z.PlatitiPorez)) > 0) {
		fwrite(&z, sizeof(z), 1, fout);
	}

	fclose(fin);
	fclose(fout);
	return 1;
}

//1. Zadatak
zapis* Ucitaj(char *FileName, int *BrElem) {
	int		i; //lokalne varijable
	int	Br;
	FILE 	*fp;
	zapis	*Polje = NULL;
	zapis	Elem;
	FILE *f = fopen(FileName, "r");

	fseek(f, 0, SEEK_SET);
	fread(&Br, sizeof(int), 1, f);
	Polje = (zapis *)malloc(sizeof(zapis)*Br);

	//

	return Polje;
}

//2. Zadatak
int	MaxPorez(zapis *Polje, int BrElem) {
	int	i, MaxInd = 0;
	float Max;

	//Zadaća
	return MaxInd;
}

int main() {
	int	BrElem, MaxInd; //lokalne varijable
	char FileName[40] = "podaci.dat";
	zapis *Polje;
	prepisi("podaci.txt", FileName);
	Polje = Ucitaj(FileName, &BrElem);
	if (Polje != NULL) {
		MaxInd = MaxPorez(Polje, BrElem);
		printf("Najvise poreza treba platiti %s, u iznosu od %f", Polje[MaxInd].ImePrezime,
			Polje[MaxInd].PlatitiPorez);
	}
	free(Polje);
	_getch();
	return 0;
}
