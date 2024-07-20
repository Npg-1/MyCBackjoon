#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int* sortArr, int l, int m, int r);
void mergeSort(int* arr, int* sortArr, int l, int r);

int main()
{
	int n;
	scanf("%d", &n);

	int arr[10] = { -1, };
	int len = 0;
	for (int i = 0; n != 0; i++)
	{
		arr[i] = n % 10;
		n /= 10;
		len++;

	}

	int* sortArr = (int*)calloc(sizeof(int), len);
	mergeSort(arr, sortArr, 0, len - 1);

	for (int i = 0; i < len; i++) printf("%d", arr[i]);
	printf("\n");

	return 0;

}

void merge(int* arr, int* sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (arr[i] > arr[j]) sortArr[k++] = arr[i++];
		else sortArr[k++] = arr[j++];
	}

	while (i <= m) sortArr[k++] = arr[i++];
	while (j <= r) sortArr[k++] = arr[j++];

	for (int a = l; a <= r; a++) arr[a] = sortArr[a];
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

