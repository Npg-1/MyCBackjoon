#include <stdio.h>
#include <stdlib.h>

bool andCheck(char** board, int b, int a, int n, int m)
{
	for (int i = 0; i < a; i++) // a, b의 왼쪽
	{
		if (board[b][i] == 'X') return true;
	}

	for (int i = a + 1; i < m; i++) // a, b의 오른쪽
	{
		if (board[b][i] == 'X') return true;
	}

	for (int i = 0; i < b; i++) // a, b의 위쪽
	{
		if (board[i][a] == 'X') return true;
	}

	for (int i = b + 1; i < n; i++)   // a, b의 아래쪽
	{
		if (board[i][a] == 'X') return true;
	}

	return false;
}

bool orCheck(char** board, int b, int a, int n, int m)
{
	bool isHang = false;
	for (int i = 0; i < a; i++)	// a, b의 왼쪽
	{
		if (board[b][i] == 'X') isHang = true;
	}

	for (int i = a + 1; i < m; i++)	// a, b의 오른쪽
	{
		if (board[b][i] == 'X') isHang = true;
	}

	if (!isHang) return false;

	bool isYul = false;
	for (int i = 0; i < b; i++)	// a, b의 위쪽
	{
		if (board[i][a] == 'X') isYul = true;
	}

	for (int i = b + 1; i < n; i++)	// a, b의 아래쪽
	{
		if (board[i][a] == 'X') isYul = true;
	}

	return isYul;

}

int main()
{
	int n, m; scanf("%d%d", &n, &m);

	char** board = (char**)calloc(sizeof(char*), n);
	for (int i = 0; i < n; i++) board[i] = (char*)calloc(sizeof(char), m);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);

	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '.' && !andCheck(board, i, j, n, m))
			{
				board[i][j] = 'X';
				count++;

			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '.' && !orCheck(board, i, j, n, m))
			{
				board[i][j] = 'X';
				count++;

			}
		}
	}

	printf("%d\n", count);


	return 0;

}
