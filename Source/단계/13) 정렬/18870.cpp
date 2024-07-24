#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int value;
	int order;
	int smallerThenMeNumber;

}Number;

void merge(Number* arr, Number* sortArr, int l, int m, int r);
void mergeSort(Number* arr, Number* sortArr, int l, int r);

void orderMerge(Number* arr, Number* sortArr, int l, int m, int r);
void orderMergeSort(Number* arr, Number* sortArr, int l, int r);

int main()
{
	int n;
	scanf("%d", &n);

	Number* arr = (Number*)calloc(sizeof(Number), n);
	Number* sortArr = (Number*)calloc(sizeof(Number), n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		arr[i].value = temp;
		arr[i].order = i;

	}

	mergeSort(arr, sortArr, 0, n - 1);

	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		int add = 0;
		int curValue = arr[i].value;
		while (curValue == arr[i + add].value)
		{
			arr[i + add].smallerThenMeNumber = idx;
			add++;

		}
		i += add - 1;
		idx++;

	}

	orderMergeSort(arr, sortArr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i].smallerThenMeNumber);

	}
	printf("\n");

	return 0;
}

void merge(Number* arr, Number* sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (arr[i].value < arr[j].value) sortArr[k++] = arr[i++];
		else sortArr[k++] = arr[j++];

	}

	while (i <= m) sortArr[k++] = arr[i++];
	while (j <= r) sortArr[k++] = arr[j++];

	for (int a = l; a <= r; a++)
	{
		arr[a] = sortArr[a];

	}
}

void mergeSort(Number* arr, Number* sortArr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, sortArr, l, m);
		mergeSort(arr, sortArr, m + 1, r);
		merge(arr, sortArr, l, m, r);

	}
}

void orderMerge(Number* arr, Number* sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (arr[i].order < arr[j].order) sortArr[k++] = arr[i++];
		else sortArr[k++] = arr[j++];

	}

	while (i <= m) sortArr[k++] = arr[i++];
	while (j <= r) sortArr[k++] = arr[j++];

	for (int a = l; a <= r; a++)
	{
		arr[a] = sortArr[a];

	}
}

void orderMergeSort(Number* arr, Number* sortArr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		orderMergeSort(arr, sortArr, l, m);
		orderMergeSort(arr, sortArr, m + 1, r);
		orderMerge(arr, sortArr, l, m, r);

	}
}



