#include <stdio.h>
#include <stdlib.h>

int fillSquare(int len, int dp[])
{
	if (len == 0) return 1;
	else if (len < 0) return 0;
	else if (dp[len] != 0) return dp[len];

	return dp[len] = (fillSquare(len - 1, dp) + fillSquare(len - 2, dp) + fillSquare(len - 2, dp)) % 10007;

}


int main()
{
	int len; scanf("%d", &len);
	int* dp = (int*)calloc(1001, sizeof(int));

	printf("%d\n\n", fillSquare(len, dp));


	return 0;

}
