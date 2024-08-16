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
	// �� �ڵ忡�� suffixArr�� sortArr�� �������� �ϴ� 2���� �迭�ε�, 2���� �迭�� �� ���
	// ��, 1���� �迭�� ������ ���ڿ� ũ�⿡ �� �°� ���� �޸� �Ҵ��� �߾����� �׷��� �ϴϱ�
	// merge()�ϴ� �������� ���̰� �� 1�����迭���� ���̰� ª�� 1�����迭�� strcpy()�� �ϴ� ������ ������ �߻���
	// �׷��� 64, 65������ �޸� ���̸� 1001�� �˳��ϰ� �� �迭 ũ�Ⱑ �� �������� strcpy()���� ������ �� ����

	// �̹� ������ �������ϰ� �����Ҵ��� �� �°� �Ϸ��� ���������� ���� �����ϱ� �������ʹ� 
	// �� �̹��� ����� ���� (��Ÿ�� ���� (Segfault))�� �߻��ϸ� �����Ҵ� �κк��� ���� ���캸�� �����Ҵ��� ������ �� �� ������ ����

	// �׸��� calloc()�� '��� ũ��', '�迭 ����' ������ �ƴ϶� '�迭 ����', '��� ũ��' ������

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
