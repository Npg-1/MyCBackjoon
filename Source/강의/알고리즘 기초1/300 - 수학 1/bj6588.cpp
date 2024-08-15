#include <stdio.h>

void setSieveOfEratosthenes(bool primeNumArr[])
{
	for (int i = 2; i < 500000; i++)
	{
		if (primeNumArr[i])
		{
			for (int j = i * 2; j < 1000001; j += i)
				primeNumArr[j] = false;

		}
	}
}

int main()
{
	bool primeNumArr[1000001];
	for (int i = 0; i < 1000001; i++) primeNumArr[i] = true;
	primeNumArr[1] = false;

	setSieveOfEratosthenes(primeNumArr);

	while (true)
	{
		int n; scanf("%d", &n);
		if (n == 0) break;

		for (int i = 2; i < n / 2 + 1; i++)
		{
			if (primeNumArr[i] && primeNumArr[n - i])
			{
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}

		}
	}

	return 0;
}
