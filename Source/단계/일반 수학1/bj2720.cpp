#include <stdio.h>

int main()
{
	const int QUARTER = 25;
	const int DIME = 10;
	const int NICKEL = 5;
	const int PENNY = 1;

	int tca;
	scanf("%d", &tca);

	for (int a1 = 0; a1 < tca; a1++)
	{
		int num;
		scanf("%d", &num);

		int q = 0, d = 0, n = 0, p = 0;
		q = num / QUARTER;
		num -= q * QUARTER;

		d = num / DIME;
		num -= d * DIME;

		n = num / NICKEL;
		num -= n * NICKEL;

		p = num / PENNY;

		printf("%d %d %d %d\n", q, d, n, p);

	}

	return 0;
}
