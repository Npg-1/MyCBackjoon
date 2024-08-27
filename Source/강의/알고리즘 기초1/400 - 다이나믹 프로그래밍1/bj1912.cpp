#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n; scanf("%d", &n);
	int* arr = (int*)calloc(n + 1, sizeof(int));

	for (int i = 1; i < n + 1; i++)
		scanf("%d", &(arr[i]));


	int* dp = (int*)calloc(n + 1, sizeof(int));
	for (int i = 0; i <= n; i++)
	{
		dp[i] = -1000;

	}

	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] >= 0)
		{
			if (dp[i - 1] <= 0) dp[i] = arr[i];
			else dp[i] = dp[i - 1] + arr[i];

		}
		else
		{
			if (dp[i - 1] + arr[i] < 0) dp[i] = arr[i];
			else dp[i] = dp[i - 1] + arr[i];

		}
	}

	int result = -9999;
	for (int i = 1; i <= n; i++)
	{
		result = (dp[i] > result) ? dp[i] : result;

	}

	printf("%d\n\n", result);

	free(arr);
	free(dp);


	return 0;

}

