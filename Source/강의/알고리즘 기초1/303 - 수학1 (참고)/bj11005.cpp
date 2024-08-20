#include <stdio.h>
#include <math.h>

int main()
{
	long long n; int b;
	scanf("%lld%d", &n, &b);

	int maxDegree = 0;
	long long temp = 1;
	while (temp <= n)
	{
		temp *= b;
		maxDegree++;

	}
	maxDegree--;

	int degree = maxDegree;
	while (n != 0)
	{
		long long divide = (int)pow(b, degree);
		int umm = n / divide;

		if (umm > 9) printf("%C", umm - 10 + 'A');
		else printf("%d", umm);

		n -= umm * divide;
		degree--;

	}


	while (degree >= 0)
	{
		printf("0");
		degree--;

	}

	return 0;

}
