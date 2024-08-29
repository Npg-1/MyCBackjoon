#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; scanf("%d", &n);

	if (n < 4) printf("%d\n\n", n);
	else
	{
		int* dp = (int*)calloc(n + 1, sizeof(int));
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;

		for (int i = 2; i * i <= n; i++) dp[i * i] = 1;
		for (int i = 5; i <= n; i++)
		{
			int min = 100001;
			for (int j = 2; j * j <= i; j++)
			{
				int umm = dp[j * j] + dp[i - (j * j)];
				min = umm < min ? umm : min;

			}

			dp[i] = min;

		}

		printf("%d\n\n", dp[n]);
		free(dp);

	}

	return 0;

}

