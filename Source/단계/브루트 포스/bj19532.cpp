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

	// �� ���� ������������ ������ Ǯ� x, y�� ���ߴµ� �̰� Ʋ�� 0���� ���� �����ٴ�
	// ��Ÿ�� ������ �߻��ϴµ� �װ� ��� ������ �� ������ �������.. 
	// �׷��� �Ʒ� �������� ���� �� ǰ..
	int y = (a * f - d * c) / (a * e - b * d);
	int x = (c - b * y) / a;

	return 0;

}
