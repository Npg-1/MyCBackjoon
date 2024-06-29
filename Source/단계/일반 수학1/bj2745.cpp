#include <stdio.h>
#include <string.h>

int main()
{
	char num[100];
	int nSystem;
	scanf("%s%d", num, &nSystem);

	int sum = 0;
	int index = strlen(num) - 1;
	for (int i = 0; num[i] != NULL; i++)
	{
		int umm = 1;
		for (int j = 0; j < index; j++)
			umm *= nSystem;

		index--;
		if (num[i] >= 'A' && num[i] <= 'Z')
			sum += (int)(num[i] - 'A' + 10) * umm;
		else
			sum += (int)(num[i] - '0') * umm;
	}

	printf("%d\n", sum);



	return 0;

}
