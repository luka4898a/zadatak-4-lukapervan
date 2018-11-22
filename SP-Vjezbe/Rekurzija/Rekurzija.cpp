#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


//Ispis brojeva od 100 do 1
void funkcija(int n) {
	if (n <= 100) {
		funkcija(n + 1);
		printf("\n%d", n);
	}
}

//Ispis brojeva od 1 do 100
void funkcija2(int n) {
	if (n <= 100) {
		printf("\n%d", n);
		funkcija2(n + 1);
	}
}

//Ispis brojeva od 1 do 100 i 100 do 1
void funkcija3(int n) {
	if (n <= 100) {
		printf("\n%d", n);
		funkcija3(n + 1);
		printf("\n%d", n);
	}
}

//Suma brojeva od [a] do [b]
int suma(int a, int b) {
	if (a <= b) {
		int r = suma(a + 1, b);
		return r + a;
	}
	return 0;
}

void f2(int n) {
	if (n > 0) {
		int z = n % 10;
		printf("%d", z);
		f2(n / 10);
	}
}

//Ispiši niz znakova obrnutim redolijedom
void obrnuto(char *niz, int d) {
	if (d > 0) {
		printf("%c", niz[d - 1]);
		obrnuto(niz, d - 1);
	}
}

//Ispiši niz znakova obrnutim redolijedom
void obrnuto2(char *niz)
{
	if (*niz != '\0') {
		obrnuto2(niz + 1);
		printf("%c", *niz);
	}
}

//Zadaća. Provjeri je li riječ palindrom?
int palindrom(char *niz ) {
	return 1;
}


int main() {
	
	//funkcija(1);
	//funkcija2(1);
	//funkcija3(1);
	//int a = 2, b = 5;
	//printf("Suma brojeva od [%d - %d] je %d", a, b, suma(a, b));
	char niz[] = "Strukture";
	//obrnuto(niz, strlen(niz));
	obrnuto2(niz);
	_getch();
}