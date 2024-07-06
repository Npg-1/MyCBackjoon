#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	bool isFind = false;
	for (int i = 1; i <= n; i++)
	{
		int sum = i;
		int temp = i;
		while (temp != 0)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == n)
		{
			printf("%d\n\n", i);
			isFind = true;
			break;

		}
	}

	if (!isFind) printf("0\n\n");
	return 0;

}
