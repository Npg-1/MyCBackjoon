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


	int m, n; scanf("%d%d", &m, &n);
	for (int i = m; i <= n; i++)
	{
		if (primeNumArr[i]) printf("%d\n", i);

	}

	return 0;
}

