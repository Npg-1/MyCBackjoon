#include <stdio.h>
#include <math.h>

int recursion(int n, int cnt)
{
	if (n <= 1) return cnt;
	return fmin(recursion(n / 2, cnt + (n % 2) + 1), recursion(n / 3, cnt + (n % 3) + 1));

}


int main()
{
	// ...? �� ���̳��� ���α׷��� �ƹ��͵� �� �� �� ������ �̰� �� �³�?

	int n; scanf("%d", &n);
	printf("%d\n", recursion(n, 0));


	return 0;

}
