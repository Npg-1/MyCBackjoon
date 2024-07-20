#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int* sortArr, int l, int m, int r);
void mergeSort(int* arr, int* sortArr, int l, int r);

int main()
{
	int arr[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &(arr[i]));
		sum += arr[i];

	}

	int sortArr[5];
	mergeSort(arr, sortArr, 0, 4);

	printf("%d\n%d", sum / 5, arr[2]);

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

