#include <stdio.h>
#include <string.h>

int main()
{
	while (true)
	{
		char arr[100];
		char* umm = fgets(arr, 100, stdin);
		if (umm == NULL) return 0;

		printf("%s", arr);

	}

	return 0;

}
