#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

struct zapis {
	int mbr;
	char ime[40 + 1];
	char spol[1 + 1];
};

// funkcija vraća dohvaćeni zapis
struct zapis dohvati_brisi(FILE* direktna, int mbr) {  
	struct zapis z, z1;

	fseek(direktna, sizeof(zapis) * mbr, SEEK_SET);
	fread(&z, sizeof(z), 1, direktna);

	z1.mbr = 0;
	fseek(direktna, sizeof(zapis) * mbr, SEEK_SET);
	fwrite(&z1, sizeof(z1), 1, direktna);

	return z;
}

int main() {
	struct zapis z;
	int mbr, i;
	FILE *slijedna, *direktna;
	if (!(slijedna = fopen("studenti.txt", "r"))) {
		printf("\nNema ulazne dateke studenti.txt\n");
		return 1;
	}
	// Stvaranje direktne neformatirane datoteke iz slijedne formatirane 
	if (!(direktna = fopen("studenti.dat", "w+b"))) {
		printf("\nNe mogu otvoriti direkltnu datoteku studenti.dat\n");
		fclose(slijedna);
		return 1;
	}

	// Pražnjenje direktne datoteke
	z.mbr = 0;
	for (i = 0; i <= 999; i++) fwrite(&z, sizeof(z), 1, direktna);

	// Prijepis iz slijedne formatirane u direktnu neformatiranu
	while (fscanf(slijedna, "%3d%s%s", &z.mbr, z.ime, z.spol) != EOF) {

		printf("Procitan zapis %d %s %s\n", z.mbr, z.ime, z.spol);

		fseek(direktna, z.mbr * sizeof(struct zapis), SEEK_SET);

		fwrite(&z, sizeof(z), 1, direktna);
	}

	// Dohvat i brisanje
	while (1) {
		printf("\nUpisite mbr >");
		scanf("%d", &mbr);
		z = dohvati_brisi(direktna, mbr);
		if (z.mbr) {
			printf("Izbrisan zapis: %d %s %s", z.mbr, z.ime, z.spol);
		}
		else {
			printf("\nNema zapisa s mbr = %d\n", mbr);
			break;
		}
	}

	_getch();
	return 0;
}
