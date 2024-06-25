#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	bool* checkArr = (bool*)calloc(sizeof(bool), 30 + 1);
	for (int i = 0; i < 28; i++)
	{
		int n;
		scanf("%d", &n);

		checkArr[n] = true;

	}

	int idx = 0;
	int answer[2];
	for (int i = 1; i < 31; i++)
	{
		if (!checkArr[i]) answer[idx++] = i;

	}

	if (answer[0] < answer[1]) printf("%d\n%d", answer[0], answer[1]);
	else printf("%d\n%d", answer[1], answer[0]);


	return 0;

}
