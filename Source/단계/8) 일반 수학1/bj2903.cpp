#include <stdio.h>

int main()
{
	int count[16] = { 0, };
	count[0] = 2;
	for (int i = 1; i < 16; i++)
	{
		count[i] = count[i - 1] * 2 - 1;
	}

	int n;
	scanf("%d", &n);
	printf("%d\n", count[n] * count[n]);

	return 0;

}