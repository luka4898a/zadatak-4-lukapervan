#include "Header.h"

int upis(FILE *f, int adr, zapis pom)
{
	zapis pretinac[C];

	int poc = adr;
	int i;
	i = poc;

	do {
		fseek(f, i * BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j = 0; j < C; j++) {
			if (pretinac[j].sifra == pom.sifra) {
				return 0;
			}if (pretinac[j].sifra == 0) {
				pretinac[j] = pom;
				fseek(f, i * BLOK, SEEK_SET);
				fwrite(pretinac, sizeof(pretinac), 1, f);
				return 1;
			}
		}
		i = (i + 1) % M;
	} while (i != poc);
	return 0;
}

void prepisi(char *izlaz, char *ulaz)
{
	FILE *fizlaz, *fulaz;
	if ((fizlaz = fopen(izlaz, "wb+")) == NULL)
		return;
	if ((fulaz = fopen(ulaz, "r")) == NULL)
		return;

	//Format
	zapis pret[C];
	fseek(fizlaz, 0, SEEK_SET);
	for (int i = 0; i < C; i++)
		pret[i].sifra = 0;

	for (int i = 0; i < M; i++) {
		fseek(fizlaz, i*BLOK, SEEK_SET);
		fwrite(pret, sizeof(pret), 1, fizlaz);
	}

	zapis pom;
	int adr;
	while (fscanf(fulaz, "%d,%[^,],%f", &pom.sifra, &pom.naziv, &pom.cijena) != EOF)
	{
		adr = pom.sifra % M;
		printf("\n%d %d %s %.2f %d", adr, pom.sifra, pom.naziv, pom.cijena, M);
		upis(fizlaz, adr, pom);
	}

	fclose(fizlaz);
	fclose(fulaz);
}