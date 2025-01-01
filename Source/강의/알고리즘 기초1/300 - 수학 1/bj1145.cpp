#include <stdio.h>

int getG(int a, int b)
{
	if (a % b == 0) return b;
	return getG(b, a % b);

}

int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &(arr[i]));

	}

	int gla[10] = { 0 };
	int idx = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				int a = arr[i], b = arr[j], c = arr[k];

				int mul = 1;
				int divideNum = 2;
				while (true)
				{
					if (divideNum > a || divideNum > b || divideNum > c) break;

					if (a % divideNum == 0 && b % divideNum == 0 && c % divideNum == 0)
					{
						a /= divideNum;
						b /= divideNum;
						c /= divideNum;
						mul *= divideNum;
						divideNum--;

					}
					divideNum++;
				}

				int divideAB = 2;
				while (true)
				{
					if (divideAB > a || divideAB > b) break;

					if (a % divideAB == 0 && b % divideAB == 0)
					{
						a /= divideAB;
						b /= divideAB;
						mul *= divideAB;
						divideAB--;

					}
					divideAB++;

				}

				int divideAC = 2;
				while (true)
				{
					if (divideAC > a || divideAC > c) break;

					if (a % divideAC == 0 && c % divideAC == 0)
					{
						a /= divideAC;
						c /= divideAC;
						mul *= divideAC;
						divideAC--;

					}
					divideAC++;

				}

				int divideBC = 2;
				while (true)
				{
					if (divideBC > b || divideBC > c) break;

					if (b % divideBC == 0 && c % divideBC == 0)
					{
						b /= divideBC;
						c /= divideBC;
						mul *= divideBC;
						divideBC--;

					}
					divideBC++;

				}

				gla[idx] = a * b * c * mul;
				idx++;
			}
		}
	}

	int min = 1000000000;
	for (int i = 0; i < 10; i++)
	{
		min = gla[i] < min ? gla[i] : min;

	}
	printf("%d\n", min);

	return 0;

}
