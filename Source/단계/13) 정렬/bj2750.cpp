#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) { int temp = a; a = b; b = temp; }

void sortArrBubble(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);

		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
	{
		int umm;
		scanf("%d", &umm);
		arr[i] = umm;

	}

	sortArrBubble(arr, n);
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);

	return 0;

}
