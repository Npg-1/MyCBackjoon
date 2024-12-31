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
	// table[i][j]: i�л��� j�г��̾��� ���� �ݹ�ȣ

	bool** visitTable = (bool**)calloc(sizeof(bool*), n + 1);
	for (int i = 1; i <= n; i++) visitTable[i] = (bool*)calloc(sizeof(bool), n + 1);

	// ���� for������ �л���ȣ�� �������Ѿ���, �л���ȣ�� �����̰�, �г��� ��������
	for (int i = 1; i <= 5; i++)			// i�� �г�
	{
		for (int j = 1; j <= n; j++)		// j�� �л���ȣ
		{
			int cur = table[j][i];
			for (int k = 1; k <= n; k++)	// k�� �л���ȣ
			{
				if (cur == table[k][i])
				{
					// k�� j�� ���� �г��̾��� �� ���� ���̾��� ���
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

