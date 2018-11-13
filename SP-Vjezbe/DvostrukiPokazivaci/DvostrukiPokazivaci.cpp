#include <stdio.h>
#include <conio.h>

void preusmjeri(int *b, int **p)
{
	*p = b;
}

int main() {
	int a = 5, b = 6;
	int *pa = &a;

	//pa = &b;
	printf("a=%d, b=%d, *pa = %d", a, b, *pa);
	preusmjeri(&b, &pa);

	printf("\na=%d, b=%d, *pa = %d", a, b, *pa);

	_getch();
	return 1;
}