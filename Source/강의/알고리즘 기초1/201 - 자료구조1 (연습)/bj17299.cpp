#include <stdio.h>
#include <stdlib.h>

typedef struct NumberA
{
	int num;
	int appearanceCount;
	int idx;

} NumberA;


void push(NumberA* stack, NumberA n, int* stackSize)
{
	if (*stackSize == 1000000) return;
	stack[*stackSize] = n;
	(*stackSize)++;

}

NumberA pop(NumberA* stack, int* stackSize)
{
	NumberA umm; umm.idx = -1; umm.num = -1;
	if (*stackSize == 0)
		return umm;

	NumberA result = stack[--(*stackSize)];
	stack[*stackSize] = umm;

	return result;

}

NumberA getTop(NumberA* stack, int* stackSize)
{
	NumberA umm; umm.idx = -1; umm.num = -1;
	if (*stackSize == 0) return umm;
	return stack[*stackSize - 1];

}


int main()
{
	int n; scanf("%d", &n);
	NumberA* arr = (NumberA*)calloc(sizeof(NumberA), n);
	int* countArr = (int*)calloc(sizeof(int), 1000001);
	int* resultArr = (int*)calloc(sizeof(int), n);

	for (int i = 0; i < n; i++)
	{
		int temp; scanf("%d", &temp);
		arr[i].num = temp;
		arr[i].idx = i;
		countArr[temp]++;

	}

	for (int i = 0; i < n; i++)
		arr[i].appearanceCount = countArr[arr[i].num];

	NumberA* stack = (NumberA*)calloc(sizeof(NumberA), n);
	int stackSize = 0;

	for (int i = 0; i < n; i++)
	{
		if (stackSize == 0) push(stack, arr[i], &stackSize);
		else
		{
			while (true)
			{
				NumberA top = getTop(stack, &stackSize);

				if (stackSize == 0 || arr[i].appearanceCount <= top.appearanceCount) break;
				else if (arr[i].appearanceCount > top.appearanceCount)
				{
					pop(stack, &stackSize);
					resultArr[top.idx] = arr[i].num;

				}
			}

			push(stack, arr[i], &stackSize);

		}
	}

	while (stackSize != 0)
	{
		NumberA umm = pop(stack, &stackSize);
		resultArr[umm.idx] = -1;

	}

	for (int i = 0; i < n; i++) printf("%d ", resultArr[i]);

	return 0;

}

