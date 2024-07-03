#include <stdio.h>

int main()
{
	int xArr[4] = { 0, };
	int yArr[4] = { 0, };

	for (int i = 0; i < 3; i++)
	{
		scanf("%d%d", &xArr[i], &yArr[i]);

	}

	if (xArr[0] == xArr[1]) printf("%d ", xArr[2]);
	else if (xArr[0] == xArr[2]) printf("%d ", xArr[1]);
	else if (xArr[1] == xArr[2]) printf("%d ", xArr[0]);

	if (yArr[0] == yArr[1]) printf("%d ", yArr[2]);
	else if (yArr[0] == yArr[2]) printf("%d ", yArr[1]);
	else if (yArr[1] == yArr[2]) printf("%d ", yArr[0]);

	return 0;

}
