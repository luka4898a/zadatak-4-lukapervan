#include "Header.h"

int brojZapisa(FILE *f) 
{
	zapis pretinac[C];
	int br = 0;
	for (int i = 0; i < M; i++)
	{
		fseek(f, i*BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j=0; j<C; j++)
		{
			if (pretinac[j].sifra != 0)
				br++;
		}
	}
	return br;
}

int adresa(int sifra) {
	return sifra % M;
}

int pronadji(FILE *f, int sifra) {
	int i = adresa(sifra);
	int poc = i;

	zapis pom[C];
	do {
		fread(pom, sizeof(pom), 1, f);
		for (int j = 0; j < C; j++)
		{
			if (pom[j].sifra == sifra)
				return 1;
		}
		poc = (poc + 1) % M;
	} while (poc != i);
	return 0;
}

float gustoca(const char *ime_datoteke)
{
	return 0.0;
}

void format(FILE *f)
{
	zapis pom[C];

	for (int j = 0; j < C; j++)
		pom[j].sifra = 0;

	for (int i = 0; i < M; i++)
	{
		fseek(f, i*BLOK, SEEK_SET);
		fwrite(pom, sizeof(pom), 1, f);
	}
	return;
}

//Zadaća
//1. Zadatak
zapis tablica[MAX];
int upis(int adresa, zapis pom)
{
	return -1;
}

//2. Zadatak
int pronadji(int adresa, int sifra, char *naziv)
{
	return -1;
}

int main()
{
	char fin[] = "artikli.txt";
	char fout[] = "artikli.dat";
	prepisi(fout, fin);

	FILE *f = fopen(fout, "r+");
	if (f == NULL)
		return -1;

	//format(f);
	int br = brojZapisa(f);
	

	_getch();
	return 1;
}