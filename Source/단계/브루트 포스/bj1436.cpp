#include <stdio.h>

bool isInclude666(int n)
{
	bool isInclude = false;
	int len = 0;
	int temp = n;
	while (temp != 0)
	{
		len++;
		temp /= 10;
	}


	temp = n;
	while (temp != 0)
	{
		if (temp % 10 == 6)
		{
			temp /= 10;
			if (temp % 10 == 6)
			{
				temp /= 10;
				if (temp % 10 == 6)
				{
					isInclude = true;
					break;

				}
			}

		}
		temp /= 10;

	}

	return isInclude;

}

int main()
{
	int n;
	scanf("%d", &n);

	// isInclude666() ��� �Լ��� ������ �� ���, �Լ��� �� �� ������ ���� ���ʿ��� �κ��� �ڸ� �� ���� �� ������ �ƽ��׿�
	int count = 0;
	for (int i = 666; i <= 10000000; i++)
	{
		if (isInclude666(i))
		{
			count++;
			if (count == n)
			{
				printf("%d\n", i);
				break;

			}
		}
	}

	return 0;

}
