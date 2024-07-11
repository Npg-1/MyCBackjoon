#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int matrixA[100][100] = { 0, };
	int matrixB[100][100] = { 0, };

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int a;
			scanf("%d", &a);
			matrixA[y][x] = a;
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int a;
			scanf("%d", &a);
			matrixB[y][x] = a;
		}
	}

	int result[100][100];
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			result[y][x] = matrixA[y][x] + matrixB[y][x];
		}
	}


	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			printf("%d ", result[y][x]);
		}
		printf("\n");
	}

	return 0;

}