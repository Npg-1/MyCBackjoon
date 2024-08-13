#include <stdio.h>
#include <string.h>

int main()
{
	char input[101]; scanf("%s", input);
	char alphabet[26] = { 0, };
	for (int i = 0; i < strlen(input); i++)
	{
		alphabet[input[i] - 'a']++;

	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", alphabet[i]);

	}


	return 0;

}
