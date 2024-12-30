#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	// 다음번에는 HashMap을 사용해서 하자..

	char strArr[10][7] = { "black", "brown", "red", "orange", "yellow", "green",
		"blue", "violet", "grey", "white" };

	char* str0 = (char*)calloc(sizeof(char), 7);
	char* str1 = (char*)calloc(sizeof(char), 7);
	char* str2 = (char*)calloc(sizeof(char), 7);

	scanf("%s%s%s", str0, str1, str2);

	if (strcmp(str0, "black") == 0)
	{
		if (strcmp(str1, "black") == 0)
		{
			// 0 0 00...
			printf("0");

		}
		else
		{
			// 0 ? 00...
			for (int i = 0; i < 10; i++)
			{
				if (strcmp(str1, strArr[i]) == 0)
					printf("%d", i);

			}


			for (int i = 0; i < 10; i++)
			{
				if (strcmp(str2, strArr[i]) == 0)
				{
					for (int j = 0; j < i; j++) printf("0");

				}
			}

		}
	}
	else
	{
		// ? ? ...
		for (int i = 0; i < 10; i++)
		{
			if (strcmp(str0, strArr[i]) == 0)
				printf("%d", i);

		}

		for (int i = 0; i < 10; i++)
		{
			if (strcmp(str1, strArr[i]) == 0)
				printf("%d", i);

		}


		for (int i = 0; i < 10; i++)
		{
			if (strcmp(str2, strArr[i]) == 0)
			{
				for (int j = 0; j < i; j++) printf("0");

			}
		}
	}


	printf("\n");


	return 0;

}