#include <stdio.h>
#include <string.h>

int main()
{
	int tca;
	scanf("%d", &tca);

	for (int i = 0; i < tca; i++)
	{
		char arr[1000];
		scanf("%s", arr);

		printf("%c%c\n", arr[0], arr[strlen(arr) - 1]);

	}

	return 0;

}