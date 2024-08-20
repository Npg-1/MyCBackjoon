#include <stdio.h>
#include <stdlib.h>

int getNumCnt(int n, int dp[])
{
	if (n == 0) return 1;
	else if (n < 0) return 0;
	else if (dp[n] != 0) return dp[n];

	return getNumCnt(n - 1, dp) + getNumCnt(n - 2, dp) + getNumCnt(n - 3, dp);

}


int main()
{
	int tca; scanf("%d", &tca);

	for (int i = 0; i < tca; i++)
	{
		int n; scanf("%d", &n);
		int* dp = (int*)calloc(12, sizeof(int));

		printf("%d\n", getNumCnt(n, dp));

	}

	return 0;

}
