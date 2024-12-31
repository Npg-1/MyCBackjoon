#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n; scanf("%d", &n);

	int** table = (int**)calloc(sizeof(int*), n + 1);
	for (int i = 1; i <= n; i++) table[i] = (int*)calloc(sizeof(int), 5 + 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++)
			scanf("%d", &(table[i][j]));
	}
	// table[i][j]: i학생이 j학년이었을 때의 반번호

	bool** visitTable = (bool**)calloc(sizeof(bool*), n + 1);
	for (int i = 1; i <= n; i++) visitTable[i] = (bool*)calloc(sizeof(bool), n + 1);

	// 내부 for문에서 학생번호를 증가시켜야함, 학생번호는 왼쪽이고, 학년은 오른쪽임
	for (int i = 1; i <= 5; i++)			// i는 학년
	{
		for (int j = 1; j <= n; j++)		// j는 학생번호
		{
			int cur = table[j][i];
			for (int k = 1; k <= n; k++)	// k는 학생번호
			{
				if (cur == table[k][i])
				{
					// k와 j가 같은 학년이었을 때 같은 반이었을 경우
					visitTable[j][k] = true;

				}
			}
		}
	}


	int maxCount = 0;
	int* countArr = (int*)calloc(sizeof(int), n + 1);
	for (int i = 1; i <= n; i++)
	{
		int count = 0;
		for (int j = 1; j <= n; j++)
		{
			if (visitTable[i][j]) count++;

		}
		countArr[i] = count;
		maxCount = count > maxCount ? count : maxCount;

	}

	for (int i = 1; i <= n; i++)
	{
		if (countArr[i] == maxCount)
		{
			printf("%d\n", i);
			break;

		}
	}

	return 0;

}

