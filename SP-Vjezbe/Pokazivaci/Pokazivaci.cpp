#include <stdio.h>

void funkcija(int *p)
{
	*p = *p * 2;
	*p = 10;
}

void main() {

	int a = 5;
	int *b = &a;
	printf("Adresa a: %d %d", &a, a);
	printf("\n*b = %d", *b);
	funkcija(&a);
	printf("\n%d", a);
	getchar();
}