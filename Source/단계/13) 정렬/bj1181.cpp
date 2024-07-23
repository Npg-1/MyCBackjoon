#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char** arr, char** sortArr, int l, int m, int r);
void mergeSort(char** arr, char** sortArr, int l, int r);

void deleteDuplication(char** arr, int size);

int main()
{
	int n;
	scanf("%d", &n);

	char** arr = (char**)calloc(sizeof(char*), n + 1);
	char** sortArr = (char**)calloc(sizeof(char*), n + 1);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)calloc(sizeof(char), 51);
		sortArr[i] = (char*)calloc(sizeof(char), 51);
		scanf("%s", arr[i]);

	}
	arr[n] = (char*)calloc(sizeof(char), 51);
	sortArr[n] = (char*)calloc(sizeof(char), 51);


	mergeSort(arr, sortArr, 0, n - 1);

	deleteDuplication(arr, n);

	for (int i = 0; i < n; i++)
	{
		if (strcmp(arr[i], "") == 0) break;
		printf("%s\n", arr[i]);

	}

	return 0;
}


void merge(char** arr, char** sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (strlen(arr[i]) < strlen(arr[j]))
		{
			for (int a = 0; a < strlen(arr[i]); a++)
				sortArr[k][a] = arr[i][a];

			sortArr[k][strlen(arr[i])] = arr[i][strlen(arr[i])];
			k++; i++;

		}
		else if (strlen(arr[i]) > strlen(arr[j]))
		{
			for (int a = 0; a < strlen(arr[j]); a++)
				sortArr[k][a] = arr[j][a];

			sortArr[k][strlen(arr[j])] = arr[j][strlen(arr[j])];
			k++; j++;

		}
		else
		{
			if (strcmp(arr[i], arr[j]) < 0)
			{
				for (int a = 0; a < strlen(arr[i]); a++)
					sortArr[k][a] = arr[i][a];

				sortArr[k][strlen(arr[i])] = arr[i][strlen(arr[i])];
				k++; i++;

			}
			else
			{
				for (int a = 0; a < strlen(arr[j]); a++)
					sortArr[k][a] = arr[j][a];

				sortArr[k][strlen(arr[j])] = arr[j][strlen(arr[j])];
				k++; j++;

			}
		}
	}

	while (i <= m)
	{
		for (int a = 0; a < strlen(arr[i]); a++)
			sortArr[k][a] = arr[i][a];

		sortArr[k][strlen(arr[i])] = arr[i][strlen(arr[i])];
		i++; k++;
	}
	while (j <= r)
	{
		for (int a = 0; a < strlen(arr[j]); a++)
			sortArr[k][a] = arr[j][a];

		sortArr[k][strlen(arr[j])] = arr[j][strlen(arr[j])];
		j++; k++;
	}

	for (int a = l; a <= r; a++)
	{
		for (int b = 0; b <= strlen(sortArr[a]); b++)
			arr[a][b] = sortArr[a][b];

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

void deleteDuplication(char** arr, int size)
{
	char** tempArr = (char**)calloc(sizeof(char*), size);
	for (int i = 0; i < size; i++) tempArr[i] = (char*)calloc(sizeof(char), 51);

	bool isNotDuplicate = true;
	int idx = 0;
	for (int i = 0; i < size; i++)
	{
		isNotDuplicate = true;
		for (int j = 0; strcmp(tempArr[j], "") != 0; j++)
		{
			if (strcmp(arr[i], tempArr[j]) == 0)
			{
				isNotDuplicate = false;
				break;

			}
		}

		if (isNotDuplicate)
			strcpy(tempArr[idx++], arr[i]);

	}

	for (int i = 0; i < idx; i++) strcpy(arr[i], tempArr[i]);
	strcpy(arr[idx], "");

}


