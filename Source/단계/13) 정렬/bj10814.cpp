#include <stdio.h>
#include <stdlib.h>

typedef struct Member
{
	int age;
	int order;
	char name[101];

}Member;

void merge(Member* arr, Member* sortArr, int l, int m, int r);
void mergeSort(Member* arr, Member* sortArr, int l, int r);

int main()
{
	int n;
	scanf("%d", &n);

	Member* memberArr = (Member*)calloc(sizeof(Member), n);

	for (int i = 0; i < n; i++)
	{
		memberArr[i].order = i;
		scanf("%d%s", &(memberArr[i].age), memberArr[i].name);

	}

	Member* sortArr = (Member*)calloc(sizeof(Member), n);
	mergeSort(memberArr, sortArr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", memberArr[i].age, memberArr[i].name);
	}

	return 0;
}

void merge(Member* arr, Member* sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (arr[i].age < arr[j].age) sortArr[k++] = arr[i++];
		else if (arr[i].age > arr[j].age) sortArr[k++] = arr[j++];
		else
		{
			if (arr[i].order < arr[j].order) sortArr[k++] = arr[i++];
			else sortArr[k++] = arr[j++];

		}
	}

	while (i <= m) sortArr[k++] = arr[i++];
	while (j <= r) sortArr[k++] = arr[j++];

	for (int a = l; a <= r; a++) arr[a] = sortArr[a];
}

void mergeSort(Member* arr, Member* sortArr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, sortArr, l, m);
		mergeSort(arr, sortArr, m + 1, r);
		merge(arr, sortArr, l, m, r);

	}
}

