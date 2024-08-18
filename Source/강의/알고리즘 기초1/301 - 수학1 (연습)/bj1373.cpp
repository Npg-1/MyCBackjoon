#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int* stack, int ch, int* stackSize)
{
	if (*stackSize == 1000000) return;
	stack[*stackSize] = ch;
	(*stackSize)++;

}

int pop(int* stack, int* stackSize)
{
	if (*stackSize == 0) return -1;

	int result = stack[*stackSize - 1];
	stack[--(*stackSize)] = 0;

	return result;

}

int conversion2To8(char c0, char c1, char c2)
{
	return (4 * (c0 - '0') + 2 * (c1 - '0') + (c2 - '0'));

}

int main()
{
	char* input = (char*)calloc(1000001, sizeof(char));
	int* stack = (int*)calloc(333334, sizeof(int));
	int stackSize = 0;
	scanf("%s", input);

	int i = 0;
	for (i = strlen(input) - 1; i >= 2; i -= 3)
	{
		int umm = conversion2To8(input[i - 2], input[i - 1], input[i]);
		push(stack, umm, &stackSize);;

	}

	if (i == 0)
	{
		int umm = conversion2To8('0', '0', input[i]);
		push(stack, umm, &stackSize);

	}
	else if (i == 1)
	{
		int umm = conversion2To8('0', input[i - 1], input[i]);
		push(stack, umm, &stackSize);

	}

	while (stackSize != 0)
	{
		printf("%d", pop(stack, &stackSize));

	}

	free(input);
	return 0;

}
