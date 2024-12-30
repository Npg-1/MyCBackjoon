#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 0번 줄에는 짝수
	// 1번 줄에는 홀수
	// ... 
	// 짝수번 줄에는 짝수번
	// 홀수번 줄에는 홀수번임

	int result = 0;
	for (int i = 0; i < 8; i++)
	{
		char* str = (char*)calloc(sizeof(char), 9);
		scanf("%s", str);

		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j += 2)
			{
				if (str[j] == 'F') result++;

			}
		}
		else
		{
			for (int j = 1; j < 8; j += 2)
			{
				if (str[j] == 'F') result++;

			}
		}
	}

	printf("%d\n", result);


	return 0;

}
