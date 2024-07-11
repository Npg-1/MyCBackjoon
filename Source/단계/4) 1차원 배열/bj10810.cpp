#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m;
	scanf_s("%d%d", &n, &m);

	int* arr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf_s("%d%d%d", &a, &b, &c);

		for (int j = a - 1; j <= b - 1; j++)
		{
			arr[j] = c;
		}

	}

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);



	return 0;

}







