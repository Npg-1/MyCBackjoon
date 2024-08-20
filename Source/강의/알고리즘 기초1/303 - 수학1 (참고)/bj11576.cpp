#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, m; scanf("%d%d%d", &a, &b, &m);

	int arr[30];
	for (int i = 0; i < 30; i++) arr[i] = -1;

	int num10 = 0;
	for (int i = 0; i < m; i++)
	{
		int temp; scanf("%d", &temp);
		arr[i] = temp;

	}

	for (int i = 0; i < m; i++)
	{
		int mul = 1;
		for (int j = 0; j < m - i - 1; j++)
			mul *= a;

		num10 += mul * arr[i];

	}

	int temp = num10, degree = 0;
	while (temp != 0)
	{
		temp /= b;
		degree++;

	}
	degree--;

	while (num10 != 0)
	{
		int divide = (int)pow(b, degree);
		int umm = num10 / divide;

		printf("%d ", umm);

		num10 -= umm * divide;
		degree--;

	}

	while (degree >= 0)
	{
		printf("0 ");
		degree--;

	}

	return 0;
}
