#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n; scanf("%d", &n);

	char** strArr = (char**)calloc(sizeof(char*), n);
	for (int i = 0; i < n; i++)
	{
		strArr[i] = (char*)calloc(sizeof(char), 51);
		scanf("%s", strArr[i]);
	}

	int len = strlen(strArr[0]);
	char* result = (char*)calloc(sizeof(char), 51);
	for (int i = 0; i < len; i++)
	{
		bool isAllSame = true;
		char ch = strArr[0][i];

		for (int j = 1; j < n; j++)
		{
			if (strArr[j][i] != ch)
			{
				isAllSame = false;
				break;
			}
		}

		if (isAllSame) result[i] = ch;
		else result[i] = '?';

	}

	printf("%s\n", result);


	return 0;

}