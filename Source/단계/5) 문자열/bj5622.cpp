#include <stdio.h>
#include <string.h>

int getNum(char c)
{
	int n = c - 'A';
	if (n < 15) { return n / 3 + 2; }

	if (n < 19) return 7;
	else if (n < 22) return 8;
	else if (n < 26) return 9;

	return 0;
}

int main()
{
	char arr[15];
	scanf("%s", arr);

	int sum = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		sum += getNum(arr[i]) + 1;
	}

	printf("%d\n", sum);

	return 0;

}
