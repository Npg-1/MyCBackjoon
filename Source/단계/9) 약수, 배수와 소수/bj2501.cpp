#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	int* arr = (int*)calloc(sizeof(int), a);
	int idx = 0;
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0)
			arr[idx++] = i;

	}

	printf("%d\n", arr[b - 1]);

	return 0;

}
