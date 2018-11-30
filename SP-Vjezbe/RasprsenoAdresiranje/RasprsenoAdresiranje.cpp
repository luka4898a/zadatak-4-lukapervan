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
/*Napisati funkciju za upis šifre (cijeli broj) i naziva (20+1) u memorijski rezidentnu tablicu raspršenih adresa s 
500 pretinaca. Pretinac sadrži jedan zapis. Ako je pretinac popunjen, prelazi se ciklički na susjedni. Ulazni argumenti su 
već izračunata adresa pretinca, šifra i naziv. Funkcija vraća vrijednost 1 ako je upis obavljen, 0 ako podatak već postoji, 
a -1 ako je tablica popunjena pa se podatak nije mogao upisati.*/
zapis tablica[MAX];
int upis(int adresa, zapis pom)
{
	for (int i = 0; i < MAX; i++)
	{
		if (tablica[i].sifra == pom.sifra)
			return 0;

		if else (tablica[i].sifra == 0)
		{
			tablica[adresa].sifra = pom.sifra;
			return 1;
		}

		if else
			continue;

		else
			return -1;

	}

}

//2. Zadatak
/*Napisati funkciju za pronalaženje šifre (cijeli broj) i naziva poduzeća (30+1) iz memorijski rezidentne tablice raspršenih 
adresa s 200 pretinaca. Pretinac sadrži jedan zapis. Ako je pretinac popunjen, a ne sadrži traženu vrijednost ključa, 
prelazi se ciklički na susjedni. Ulazni argumenti su već izračunata adresa pretinca i šifra. Izlazni argument je naziv 
poduzeća. Funkcija vraća vrijednost 1 ako je zapis pronađen, a 0 ako nije.*/
int pronadji(int adresa, int sifra, char *naziv)
{

	for (int i = 0; i < MAX; i++)
	{

		if((adresa=i)&&(sifra[i]!=0)==0)
			return 1;
		else
		{
			printf("Podatak ne postoji!");
			return 0;
		}

	}

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