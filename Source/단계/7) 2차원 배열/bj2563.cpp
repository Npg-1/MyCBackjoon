#include <stdio.h>

int main()
{
	bool board[101][101] = { false, };

	int amount;
	scanf("%d", &amount);

	for (int i = 0; i < amount; i++)
	{
		int startX, startY;
		scanf("%d%d", &startX, &startY);

		for (int y = startY; y < startY + 10; y++)
		{
			for (int x = startX; x < startX + 10; x++)
			{
				board[y][x] = true;
			}
		}
	}

	int res = 0;
	for (int y = 0; y < 101; y++)
	{
		for (int x = 0; x < 101; x++)
		{
			if (board[y][x]) res++;
		}
	}

	printf("%d\n", res);

	return 0;

}
