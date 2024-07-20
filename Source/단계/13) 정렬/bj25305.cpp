#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int* sortArr, int l, int m, int r);
void mergeSort(int* arr, int* sortArr, int l, int r);

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
	{
		int temp; scanf("%d", &temp); arr[i] = temp;
	}

	int* sortArr = (int*)calloc(sizeof(int), n);
	mergeSort(arr, sortArr, 0, n - 1);
	printf("%d\n", arr[n - k]);

	return 0;

}


void merge(int* arr, int* sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (arr[i] < arr[j]) sortArr[k++] = arr[i++];
		else sortArr[k++] = arr[j++];

	}

	while (i <= m) sortArr[k++] = arr[i++];
	while (j <= r) sortArr[k++] = arr[j++];

	for (int a = l; a <= r; a++)
	{
		arr[a] = sortArr[a];

	}
}

void mergeSort(int* arr, int* sortArr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, sortArr, l, m);
		mergeSort(arr, sortArr, m + 1, r);
		merge(arr, sortArr, l, m, r);

	}
}


