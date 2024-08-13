#include <stdio.h>
#include <string.h>

int main()
{
	bool isBreak = false;

	while (true)
	{
		int small = 0, big = 0, num = 0, space = 0;
		while (true)
		{
			char ch = getchar();
			if (ch == '\n') break;
			else if (ch == EOF)
			{
				isBreak = true;
				break;
			}
			else if (ch >= 'A' && ch <= 'Z') big++;
			else if (ch >= 'a' && ch <= 'z') small++;
			else if (ch >= '0' && ch <= '9') num++;
			else if (ch == ' ')space++;

		}

		if (isBreak) break;

		printf("%d %d %d %d\n", small, big, num, space);
	}

	return 0;
}
