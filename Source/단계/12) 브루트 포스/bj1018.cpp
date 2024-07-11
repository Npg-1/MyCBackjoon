#include <stdio.h>
#include <stdlib.h>

int main()
{
	int width, height;
	scanf("%d%d", &height, &width);

	char** board = (char**)calloc(sizeof(char*), height);
	for (int y = 0; y < height; y++)
	{
		board[y] = (char*)calloc(sizeof(char), width);
		for (int x = 0; x < width; x++)
		{
			char temp;
			scanf("%c", &temp);

			if (temp == '\n') scanf("%c", &temp);
			board[y][x] = temp;

		}
	}

	int min = 1000000000;
	for (int startY = 0; startY <= height - 8; startY++)
	{
		for (int startX = 0; startX <= width - 8; startX++)
		{
			// 스타팅 포인트가 Black인 경우
			bool isBlack = true;
			int countB = 0;
			for (int y = startY; y < startY + 8; y++)
			{
				for (int x = startX; x < startX + 8; x++)
				{
					if (isBlack && board[y][x] == 'W') countB++;
					else if (!isBlack && board[y][x] == 'B') countB++;

					isBlack = !isBlack;
				}
				isBlack = !isBlack;
			}

			bool isWhite = true;
			int countW = 0;
			for (int y = startY; y < startY + 8; y++)
			{
				for (int x = startX; x < startX + 8; x++)
				{
					if (isWhite && board[y][x] == 'B') countW++;
					else if (!isWhite && board[y][x] == 'W') countW++;

					isWhite = !isWhite;
				}
				isWhite = !isWhite;
			}

			int temp = countB > countW ? countW : countB;
			min = temp < min ? temp : min;

		}
	}

	printf("%d", min);

	return 0;

}
