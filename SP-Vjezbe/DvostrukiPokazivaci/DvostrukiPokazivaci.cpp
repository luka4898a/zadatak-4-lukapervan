#include <stdio.h>


void preusmjeri(int *b, int **p)
{
	*p = b;
}

int main() {
	int a = 5, b = 6;
	int *pa = &a;

	//pa = &b;
	preusmjeri(&b, &pa);

	printf("%d", *pa);
}