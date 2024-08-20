#include <stdio.h>
#include <string.h>

int main()
{
	char nArr[30]; int b;
	scanf("%s%d", nArr, &b);

	int len = strlen(nArr);
	int result = 0;

	for (int i = 0; i < len; i++)
	{
		int mul = 1;
		for (int j = 0; j < len - i - 1; j++)
			mul *= b;

		if (nArr[i] >= 'A' && nArr[i] <= 'Z')
			result += mul * (nArr[i] - 'A' + 10);
		else
			result += mul * (nArr[i] - '0');
	}


	printf("%d\n\n", result);


	return 0;
}
