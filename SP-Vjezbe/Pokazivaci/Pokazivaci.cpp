#include <stdio.h>

void funkcija(int *p)
{
	*p = *p * 2;
}

void main() {

	int a = 5;
	int *b = &a;
	printf("Adresa a: %d %d", &a, a);
	printf("\n*b = %d", *b);
	printf("sdad");
	funkcija(&a);
	printf("\n%d", a);
	getchar();
	//test
}