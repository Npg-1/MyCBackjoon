#include <stdio.h>

int main()
{
	int tca;
	scanf("%d", &tca);

	for (int a1 = 0; a1 < tca; a1++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		if (a % 10 == 0)
		{
			// a�� 10�̸� �������� �ϵ� 1�� �ڸ��� ���ڰ� 0�̹Ƿ� 10�� �����
			printf("10\n");
			continue;
		}


		int multipleNum = a;
		if (multipleNum > 10) multipleNum %= 10;

		int num1 = 1;

		for (int i = 0; i < b; i++)
		{
			num1 *= multipleNum;
			if (num1 > 10) num1 %= 10;

		}

		printf("%d\n", num1);

	}

	return 0;

}

