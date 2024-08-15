#include <stdio.h>
#include <string.h>

int main()
{
	char str[101];
	fgets(str, 101, stdin);

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] + 13 > 'Z') str[i] -= 13;
			else str[i] += 13;

		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] + 13 > 'z') str[i] -= 13;
			else str[i] += 13;

		}
	}

	printf("%s\n", str);
}