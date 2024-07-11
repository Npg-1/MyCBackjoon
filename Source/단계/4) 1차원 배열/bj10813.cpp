#include <stdio.h>
#include <stdlib.h>

void swap(int* arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;

}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++) arr[i] = i + 1;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		a--;
		b--;
		swap(arr, a, b);

	}

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);


	return 0;

}
