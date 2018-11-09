#include <stdio.h>
#include <stdlib.h>

char *datum(char *jmbg) //DD.MM.GG.
{
	return NULL;
	//Datum
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

void main()
{
	//Datum
	printf("Pretvorba datuma:\n");
	char jmbg[14] = "0308964384007";

	int  p = kontrola(&jmbg[0]);

	if (p == 0) {
		printf("Matièni broj je pogrešan!");
		return;
	}

	char *pom = datum(jmbg);
	printf("%s", pom);

	getchar();
}