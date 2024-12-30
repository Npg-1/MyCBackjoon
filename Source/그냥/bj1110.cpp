#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; scanf("%d", &n);

	int origin = n;
	int count = 0;

	while (true)
	{
		int umm1 = n / 10;
		int umm2 = n % 10;

		int back = (umm1 + umm2) % 10;
		n = umm2 * 10 + back;
		count++;

		if (n == origin) break;

	}

	printf("%d\n", count);


	return 0;

}
