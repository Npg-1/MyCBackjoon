#include <stdio.h>

int main()
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if (a * x + b * y == c && d * x + e * y == f)
			{
				printf("%d %d", x, y);
				return 0;

			}
		}
	}

	// 두 개의 연립방정식의 수식을 풀어서 x, y를 구했는데 이건 틀림 0으로 값을 나눈다는
	// 런타임 에러가 발생하는데 그걸 어떻게 방지할 수 있을지 몰루겠음.. 
	// 그래서 아래 수식으로 문제 못 품..
	int y = (a * f - d * c) / (a * e - b * d);
	int x = (c - b * y) / a;

	return 0;

}
