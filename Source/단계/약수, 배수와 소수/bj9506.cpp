#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 정답은 맞지만 코드가 너무 지저분하고 좀 비효율적인 것 같음, 찾아보니까 완전수를 구하는 공식이 있는 것 같은데
	// 그걸 사용해서 코드를 좀 줄이고 가독성을 높일 수 있을 지도 모름, 암튼 뭔가 석연찮으니 나중에 한번 더 짬나면 해보기

	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == -1) break;

		int* arr = (int*)calloc(sizeof(int), n);
		int idx = 0;

		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				arr[idx++] = i;
			}

		}

		int sum = 0;
		for (int i = 0; arr[i] != 0; i++)
		{
			sum += arr[i];
		}

		if (sum - n == n)
		{
			int umm = 0;
			for (int i = 0; i < n; i++) if (arr[i] == n) umm = i - 1;

			printf("%d = ", n);
			for (int i = 0; i < umm; i++)
				printf("%d + ", arr[i]);
			printf("%d\n", arr[umm]);

		}
		else printf("%d is NOT perfect.\n", n);

	}

	return 0;

}
