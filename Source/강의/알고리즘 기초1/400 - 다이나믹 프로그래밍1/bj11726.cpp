#include <stdio.h>
#include <stdlib.h>

int fillSquare(int len, int dp[])
{
	if (len == 0) return 1;
	else if (len < 0) return 0;
	else if (dp[len] != 0) return dp[len];

	return dp[len] = (fillSquare(len - 1, dp) + fillSquare(len - 2, dp)) % 10007;
}

int main()
{
	int n; scanf("%d", &n);
	int* dp = (int*)calloc(1001, sizeof(int));

	printf("%d\n\n", fillSquare(n, dp));


	return 0;

}
