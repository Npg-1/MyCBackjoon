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

	// isInclude666() 라는 함수명도 마음에 안 들고, 함수를 좀 더 가독성 좋고 불필요한 부분은 자를 수 있을 거 같은데 아쉽네요
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
