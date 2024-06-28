#include <stdio.h>
#include <string.h>

int main()
{
	char arr[100];
	scanf("%s", arr);

	int count = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == 'c')
		{
			if (i + 1 < strlen(arr))
			{
				if (arr[i + 1] == '=' || arr[i + 1] == '-') { i++; }

			}
		}
		else if (arr[i] == 'd')
		{
			if (i + 1 < strlen(arr))
			{
				if (arr[i + 1] == '-') { i++; }
				else if (i + 2 < strlen(arr) && arr[i + 1] == 'z' && arr[i + 2] == '=') { i += 2; }

			}
		}
		else if (arr[i] == 'l')
		{
			if (i + 1 < strlen(arr) && arr[i + 1] == 'j') { i++; }

		}
		else if (arr[i] == 'n')
		{
			if (i + 1 < strlen(arr) && arr[i + 1] == 'j') { i++; }

		}
		else if (arr[i] == 's')
		{
			if (i + 1 < strlen(arr) && arr[i + 1] == '=') { i++; }

		}
		else if (arr[i] == 'z')
		{
			if (i + 1 < strlen(arr) && arr[i + 1] == '=') { i++; }

		}

		count++;

	}

	printf("%d\n", count);


	return 0;

}