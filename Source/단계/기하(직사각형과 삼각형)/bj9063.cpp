#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int left = 100000, top = -100000, right = -100000, bottom = 100000;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);

		if (x < left) left = x;
		if (x > right) right = x;
		if (y < bottom) bottom = y;
		if (y > top) top = y;

	}

	printf("%d", (right - left) * (top - bottom));

	return 0;

}
