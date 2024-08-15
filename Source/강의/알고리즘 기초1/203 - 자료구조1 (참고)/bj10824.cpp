#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char num1[15], num2[8], num3[15], num4[8];
	scanf("%s%s%s%s", num1, num2, num3, num4);

	strcat(num1, num2);
	strcat(num3, num4);

	printf("%lld\n", atoll(num1) + atoll(num3));

}
