#include <stdio.h>
#include <stdlib.h>

int getG(int a, int b)
{
	if (a % b == 0) return b;
	return getG(b, a % b);

}

int main()
{
	int tca; scanf("%d", &tca);

	for (int a = 0; a < tca; a++)
	{
		int n; scanf("%d", &n);
		int* arr = (int*)calloc(n, sizeof(int));

		for (int b = 0; b < n; b++)
		{
			int temp; scanf("%d", &temp);
			arr[b] = temp;

		}

		long long sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += getG(arr[i], arr[j]);

			}
		}

		printf("%lld\n", sum);
	}

	return 0;
}
