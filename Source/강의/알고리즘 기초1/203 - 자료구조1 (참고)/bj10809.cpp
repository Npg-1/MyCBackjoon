#include <stdio.h>
#include <string.h>

int main()
{
	char str[101]; scanf("%s", str);
	int alphabetIdxArr[26];
	for (int i = 0; i < 26; i++)
	{
		alphabetIdxArr[i] = -1;

	}

	for (int i = 0; i < strlen(str); i++)
	{
		if (alphabetIdxArr[str[i] - 'a'] == -1)
		{
			alphabetIdxArr[str[i] - 'a'] = i;

		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", alphabetIdxArr[i]);

	}

	return 0;

}
