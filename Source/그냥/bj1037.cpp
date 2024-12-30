#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		scanf("%d", &(arr[i]));

	int min = 2000000, max = 0;
	for (int i = 0; i < n; i++)
	{
		min = arr[i] < min ? arr[i] : min;
		max = arr[i] > max ? arr[i] : max;

	}

	printf("%d\n", min * max);

	return 0;

}
