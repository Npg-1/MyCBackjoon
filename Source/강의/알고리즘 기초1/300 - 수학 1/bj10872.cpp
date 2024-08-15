#include <stdio.h>

long long getFactorial(long long n)
{
	if (n == 1) return n;
	return n * getFactorial(n - 1);

}

int main()
{
	int n; scanf("%d", &n);

	if (n == 0) printf("1\n");
	else printf("%lld\n", getFactorial(n));

	return 0;

}
