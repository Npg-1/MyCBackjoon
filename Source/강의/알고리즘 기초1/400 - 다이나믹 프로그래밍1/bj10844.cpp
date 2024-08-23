#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; scanf("%d", &n);
	int** dp = (int**)calloc(n + 1, sizeof(int*));
	for (int i = 0; i < n + 1; i++)
	{
		dp[i] = (int*)calloc(10, sizeof(int));

	}


	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	const int DIVIDE = 1000000000;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % DIVIDE;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % DIVIDE;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % DIVIDE;
		dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % DIVIDE;
		dp[i][4] = (dp[i - 1][3] + dp[i - 1][5]) % DIVIDE;
		dp[i][5] = (dp[i - 1][4] + dp[i - 1][6]) % DIVIDE;
		dp[i][6] = (dp[i - 1][5] + dp[i - 1][7]) % DIVIDE;
		dp[i][7] = (dp[i - 1][6] + dp[i - 1][8]) % DIVIDE;
		dp[i][8] = (dp[i - 1][7] + dp[i - 1][9]) % DIVIDE;
		dp[i][9] = (dp[i - 1][8]) % DIVIDE;

	}

	long long result = 0;
	for (int i = 0; i < 10; i++)
	{
		result = (result + dp[n][i]) % DIVIDE;

	}

	printf("%d\n\n", result);

	for (int i = 0; i < n + 1; i++) free(dp[i]);
	free(dp);


	return 0;

}
