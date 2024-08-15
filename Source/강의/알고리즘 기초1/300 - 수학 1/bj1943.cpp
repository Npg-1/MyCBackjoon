#include <stdio.h>

int getG(int a, int b)
{
	if (a % b == 0) return b;
	return getG(b, a % b);

}

int main()
{
	int n; scanf("%d", &n);
	for (int a1 = 0; a1 < n; a1++)
	{
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", a * b / getG(a, b));

	}

	return 0;
}
