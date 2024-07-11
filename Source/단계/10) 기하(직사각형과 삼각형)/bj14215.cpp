#include <stdio.h>

void swap(int* arr, int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;

}

int main()
{
	int arr[3] = { 0, };
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);

	if (arr[0] < arr[1]) swap(arr, 0, 1);
	if (arr[0] < arr[2]) swap(arr, 0, 2);
	if (arr[1] < arr[2]) swap(arr, 1, 2);

	if (arr[0] >= arr[1] + arr[2]) printf("%d\n", arr[1] + arr[2] + (arr[1] + arr[2] - 1));
	else printf("%d\n", arr[0] + arr[1] + arr[2]);

	return 0;

}
