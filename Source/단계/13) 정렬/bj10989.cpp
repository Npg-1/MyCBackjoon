#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);

	int countArr[10001] = { 0, };
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		countArr[temp]++;

	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < countArr[i]; j++)
		{
			printf("%d\n", i);

		}
	}

	return 0;

}

