#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, f;
	scanf("%d%d", &n, &f);

	// 이렇게 해서 n의 뒤의 2자리의 숫자를 뗄 수가 있음
	n /= 100;
	n *= 100;

	for (int i = 0; i < 100; i++)
	{
		if (n % f == 0)
		{
			//printf("%d\n", n % 100);

			if (n % 100 < 10)
				printf("0%d\n", n % 100);
			else
				printf("%d\n", n % 100);

			break;

		}
		n++;

	}

	return 0;

}
