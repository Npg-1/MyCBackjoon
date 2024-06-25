#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, target;
	scanf_s("%d", &n);
	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		scanf_s("%d", &temp);

		*(arr + i) = temp;
	}

	scanf_s("%d", &target);

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == target) count++;

	}

	printf("%d\n", count);

	return 0;

}







