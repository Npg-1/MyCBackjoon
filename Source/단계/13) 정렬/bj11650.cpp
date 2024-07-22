#include <stdio.h>
#include <stdlib.h>

void merge(int** arr, int** sortArr, int l, int m, int r);
void mergeSort(int** arr, int** sortArr, int l, int r);

int main()
{
	int n;
	scanf("%d", &n);

	int** arr = (int**)calloc(sizeof(int*), n);
	int** sortArr = (int**)calloc(sizeof(int*), n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)calloc(sizeof(int), 2);
		sortArr[i] = (int*)calloc(sizeof(int), 2);
		scanf("%d%d", &(arr[i][0]), &(arr[i][1]));

	}

	mergeSort(arr, sortArr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i][0], arr[i][1]);

	return 0;
}

void merge(int** arr, int** sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (arr[i][0] < arr[j][0])
		{
			sortArr[k][0] = arr[i][0];
			sortArr[k++][1] = arr[i++][1];

		}
		else if (arr[i][0] > arr[j][0])
		{
			sortArr[k][0] = arr[j][0];
			sortArr[k++][1] = arr[j++][1];

		}
		else
		{
			if (arr[i][1] < arr[j][1])
			{
				sortArr[k][0] = arr[i][0];
				sortArr[k++][1] = arr[i++][1];

			}
			else
			{
				sortArr[k][0] = arr[j][0];
				sortArr[k++][1] = arr[j++][1];

			}
		}
	}

	while (i <= m)
	{
		sortArr[k][0] = arr[i][0];
		sortArr[k][1] = arr[i][1];
		k++; i++;

	}
	while (j <= r)
	{
		sortArr[k][0] = arr[j][0];
		sortArr[k][1] = arr[j][1];
		k++; j++;

	}

	for (int a = l; a <= r; a++)
	{
		arr[a][0] = sortArr[a][0];
		arr[a][1] = sortArr[a][1];

	}
}

void mergeSort(int** arr, int** sortArr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, sortArr, l, m);
		mergeSort(arr, sortArr, m + 1, r);
		merge(arr, sortArr, l, m, r);

	}
}

