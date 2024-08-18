#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getG(int a, int b)
{
	if (a % b == 0) return b;
	return getG(b, a % b);

}

int main()
{
	int n, s; scanf("%d%d", &n, &s);
	int* brotherPosition = (int*)calloc(n + 1, sizeof(int));
	int* difference = (int*)calloc(n + 1, sizeof(int));

	for (int i = 1; i <= n; i++)
	{
		int temp; scanf("%d", &temp);
		brotherPosition[i] = temp;
		difference[i] = abs(s - brotherPosition[i]);

	}

	int result = difference[1];
	for (int i = 2; i <= n; i++)
	{
		result = getG(result, difference[i]);

	}

	printf("%d\n", result);


	free(brotherPosition);
	return 0;

}
