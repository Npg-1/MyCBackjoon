#include <stdio.h>
#include <stdlib.h>

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
	int tca; scanf("%d", &tca);

	bool* primeArr = (bool*)calloc(1000001, sizeof(bool));
	for (int i = 0; i < 1000001; i++) primeArr[i] = true;
	primeArr[1] = false;

	setSieveOfEratosthenes(primeArr);


	for (int a1 = 0; a1 < tca; a1++)
	{
		int n; scanf("%d", &n);

		int cnt = 0;
		for (int i = 2; i <= n / 2; i++)
		{
			if (primeArr[i] && primeArr[n - i])
			{
				cnt++;

			}
		}

		printf("%d\n", cnt);
	}

	return 0;

}
