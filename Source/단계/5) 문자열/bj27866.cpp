#include <stdio.h>

int main()
{
	char str[1000];

	scanf("%s", str);

	int idx;
	scanf("%d", &idx);
	printf("%c", str[idx - 1]);

	return 0;

}