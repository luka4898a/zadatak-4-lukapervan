#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char *datum(char *jmbg) //DD.MM.GG.
{
	char *datum = (char *) malloc(sizeof(char)*10);
	int dd, mm, gg, pp;
	sscanf(jmbg, "%2d%2d%1d%2d", &dd, &mm, &pp, &gg);
	sprintf(datum, "%02d.%02d.%02d.",dd, mm, gg);
	return datum;
}

int kontrola(char *jmbg)
{
	char p[12 + 1] = "765432765432";

	int ZZZ = 0, OST, RAZ, K;
	K = jmbg[12] - '0';
	for (int i = 0; i < 12; i++)
		ZZZ += (jmbg[i] - '0') * (p[i] - '0');
	OST = ZZZ % 11;
	RAZ = 11 - OST;

	if (OST == 1)
		return 0;
	else if (OST == 0 && K == 0)
		return 1;
	else if (OST > 1 && OST < 11 && K == RAZ)
		return 1;
	else
		return 0;
}

int main()
{
	//Datum
	printf("Pretvorba datuma:\n");
	char jmbg[14] = "0308964384007";

	int  p = kontrola(&jmbg[0]);

	if (p == 0) {
		printf("Matièni broj je pogrešan!");
		return -1;
	}

	char *pom = datum(jmbg);
	printf("%s", pom);

	_getch();

	return 1;
}