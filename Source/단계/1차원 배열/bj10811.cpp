#include <stdio.h>
#include <stdlib.h>

void reverse(int* arr, int l, int r)
{
	int* temp = (int*)calloc(sizeof(int), r - l + 1);

	// r을 포함해서 <=임
	for (int i = l; i <= r; i++) { temp[i - l] = arr[i]; }
	for (int i = l; i <= r; i++) { arr[i] = temp[r - i]; }

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

		reverse(arr, a - 1, b - 1);

	}

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);

	return 0;

}