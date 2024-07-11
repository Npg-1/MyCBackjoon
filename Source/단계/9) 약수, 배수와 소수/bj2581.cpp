#include <stdio.h>
#include <stdlib.h>

void sieveOfEratosthenes(bool* primeArr)
{
	for (int i = 2; i <= 5000; i++)
	{
		for (int j = i * 2; j <= 10000; j += i)
		{
			primeArr[j] = false;
		}
	}

}

int main()
{
	bool primeArr[10001] = { true, };
	for (int i = 2; i < 10001; i++) primeArr[i] = true;

	sieveOfEratosthenes(primeArr);

	int m, n;
	scanf("%d%d", &m, &n);

	int sum = 0;
	int min = 0;
	for (int i = m; i <= n; i++)
	{
		if (primeArr[i])
		{
			sum += i;
			if (min == 0) min = i;
		}
	}

	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, min);

	return 0;

}
