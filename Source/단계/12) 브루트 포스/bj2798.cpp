#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int* arr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
	{
		int umm;
		scanf("%d", &umm);
		arr[i] = umm;

	}

	int max = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] <= m)
				{
					max = (arr[i] + arr[j] + arr[k] > max) ? (arr[i] + arr[j] + arr[k]) : max;

				}
			}
		}
	}

	printf("%d\n", max);

	return 0;

}
