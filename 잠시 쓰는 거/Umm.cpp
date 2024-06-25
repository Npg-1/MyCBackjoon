#include <stdio.h>

int main()
{
	for (int i = 1; i < 31; i++)
	{
		if (i == 29 || i == 30) continue;

		printf("%d\n", i);

	}

	return 0;

}


