#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(char** arr, char** sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		int umm = strcmp(arr[i], arr[j]);
		if (umm < 0) strcpy(sortArr[k++], arr[i++]);
		else strcpy(sortArr[k++], arr[j++]);
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
	// 이 코드 틀렸음.. 근데 예외가 발생해서 틀린 문제 "baakjoon"처럼 글자수가 좀 적으면 괜찮은데 글자수가 100개가 넘어가면 중단점 예외가 발생함
	// 근데 이 예외를 못 잡아서 일단 보류.. 일단 기브업


	char str[1001]; scanf("%s", str);
	char** suffixArr = (char**)calloc(strlen(str), sizeof(char*));
	char** sortArr = (char**)calloc(strlen(str), sizeof(char*));

	for (int i = 0; i < strlen(str); i++)
	{
		suffixArr[i] = (char*)calloc(strlen(str) - i + 1, sizeof(char));
		sortArr[i] = (char*)calloc(strlen(str) - i + 1, sizeof(char));
		for (int j = i; j < strlen(str); j++)
		{
			suffixArr[i][j - i] = str[j];

		}
	}

	mergeSort(suffixArr, sortArr, 0, strlen(str) - 1);

	for (int i = 0; i < strlen(str); i++)
	{
		printf("%s\n", suffixArr[i]);

	}

}
