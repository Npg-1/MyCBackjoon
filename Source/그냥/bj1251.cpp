#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* str = (char*)calloc(sizeof(char), 51);
	scanf("%s", str);

	int len = strlen(str);

	char* result = (char*)calloc(sizeof(char), len + 1);
	for (int i = 0; i < len; i++) result[i] = 'z';

	for (int i = 0; i <= len - 3; i++)
	{
		for (int j = i + 1; j <= len - 2; j++)
		{
			// 0부터 i까지, i+1부터 j까지, j+1부터 len-1 까지
			char* temp = (char*)calloc(sizeof(char), len + 1);

			for (int a1 = 0; a1 <= i; a1++)
				temp[i - a1] = str[a1];

			for (int a1 = i + 1; a1 <= j; a1++)
				temp[j - (a1 - i - 1)] = str[a1];

			for (int a1 = j + 1; a1 <= len - 1; a1++)
				temp[(len - 1) - (a1 - j - 1)] = str[a1];

			if (strcmp(temp, result) < 0) strcpy(result, temp);

		}
	}

	printf("%s\n", result);


	return 0;

}
