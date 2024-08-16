#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(char** arr, char** sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		int umm = strcmp(arr[i], arr[j]);
		if (umm < 0)
		{
			strcpy(sortArr[k++], arr[i++]);

		}
		else
		{
			strcpy(sortArr[k++], arr[j++]);

		}
	}

	while (i <= m) strcpy(sortArr[k++], arr[i++]);
	while (j <= r) strcpy(sortArr[k++], arr[j++]);

	for (int a = l; a <= r; a++)
	{
		strcpy(arr[a], sortArr[a]);

	}
}

void mergeSort(char** arr, char** sortArr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, sortArr, l, m);
		mergeSort(arr, sortArr, m + 1, r);
		merge(arr, sortArr, l, m, r);

	}
}

int main()
{
	// 이 코드에서 suffixArr과 sortArr은 병합정렬 하는 2차원 배열인데, 2차원 배열의 각 요소
	// 즉, 1차원 배열을 원래는 문자열 크기에 딱 맞게 동적 메모리 할당을 했었지만 그렇게 하니까
	// merge()하는 과정에서 길이가 긴 1차원배열에서 길이가 짧은 1차원배열로 strcpy()를 하는 데에서 문제가 발생함
	// 그래서 64, 65번줄의 메모리 길이를 1001로 넉넉하게 줌 배열 크기가 다 같아져서 strcpy()에서 문제가 안 생김

	// 이번 문제는 무지성하게 동적할당을 딱 맞게 하려는 버릇때문에 생긴 문제니까 다음부터는 
	// 또 이번과 비슷한 문제 (런타임 에러 (Segfault))가 발생하면 동적할당 부분부터 먼저 살펴보고 동적할당의 공간은 좀 더 신중히 하자

	// 그리고 calloc()은 '요소 크기', '배열 길이' 순서가 아니라 '배열 길이', '요소 크기' 순서임

	char str[1001]; scanf("%s", str);
	char** suffixArr = (char**)calloc(strlen(str), sizeof(char*));
	char** sortArr = (char**)calloc(strlen(str), sizeof(char*));

	for (int i = 0; i < strlen(str); i++)
	{
		suffixArr[i] = (char*)calloc(1000, sizeof(char));
		sortArr[i] = (char*)calloc(1000, sizeof(char));
		for (int j = i; j < strlen(str); j++)
		{
			suffixArr[i][j - i] = str[j];

		}

		suffixArr[i][strlen(str) - i] = NULL;

	}

	mergeSort(suffixArr, sortArr, 0, strlen(str) - 1);

	for (int i = 0; i < strlen(str); i++)
	{
		printf("%s\n", suffixArr[i]);

	}
}
