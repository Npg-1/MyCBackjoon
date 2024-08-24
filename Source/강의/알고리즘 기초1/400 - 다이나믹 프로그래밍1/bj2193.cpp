#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; scanf("%d", &n);
	long long** dp = (long long**)calloc(n + 1, sizeof(long long*));

	for (int i = 0; i < n + 1; i++)
		dp[i] = (long long*)calloc(2, sizeof(long long));


	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];

	}

	printf("%lld\n\n", dp[n][0] + dp[n][1]);

	for (int i = 0; i < n + 1; i++)
		free(dp[i]);

	free(dp);

	return 0;

}
