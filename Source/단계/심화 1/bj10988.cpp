#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	bool isPalindrome = true;

	char arr[100];
	scanf("%s", arr);

	int len = strlen(arr);
	char* temp = (char*)calloc(sizeof(char), len / 2);
	for (int i = 0; i < len / 2; i++)
		temp[i] = arr[i];

	for (int i = 0; i < len / 2; i++)
	{
		if (temp[i] != arr[len - 1 - i])
		{
			isPalindrome = false;
			break;
		}

	}

	if (isPalindrome) printf("1\n");
	else printf("0\n");

	return 0;

}
