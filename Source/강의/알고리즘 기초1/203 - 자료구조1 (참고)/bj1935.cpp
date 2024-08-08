#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(double* stack, double n, int* stackSize)
{
	if (*stackSize == 100000) return;
	stack[*stackSize] = n;
	(*stackSize)++;

}

double pop(double* stack, int* stackSize)
{
	if (*stackSize == 0) return -1;

	double result = stack[*stackSize - 1];
	stack[--(*stackSize)] = 0;

	return result;

}

int main()
{
	int n; scanf("%d", &n);
	char notation[101]; scanf("%s", notation);

	int* arr = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
	{
		int temp; scanf("%d", &temp);
		arr[i] = temp;

	}

	int alphabets[26];
	for (int i = 0; i < strlen(notation); i++)
	{
		if (notation[i] >= 'A' && notation[i] <= 'Z')
		{
			int idx = notation[i] - 'A';
			alphabets[idx] = arr[idx];

		}
	}


	double* numStack = (double*)calloc(sizeof(double), 101);
	int* operatorStack = (int*)calloc(sizeof(int), 101);
	int numStackSize = 0, operatorStackSize = 0;

	for (int i = 0; i < strlen(notation); i++)
	{
		if (notation[i] >= 'A' && notation[i] <= 'Z')
		{
			push(numStack, (double)(alphabets[notation[i] - 'A']), &numStackSize);


		}
		else
		{
			double a = pop(numStack, &numStackSize);
			double b = pop(numStack, &numStackSize);

			switch (notation[i])
			{
			case '+':
			{
				push(numStack, b + a, &numStackSize);
				break;

			}
			case '-':
			{
				push(numStack, b - a, &numStackSize);
				break;

			}
			case '*':
			{
				push(numStack, b * a, &numStackSize);
				break;

			}
			case '/':
			{
				push(numStack, b / a, &numStackSize);
				break;

			}
			}
		}
	}


	printf("%.2lf\n", pop(numStack, &numStackSize));

	return 0;

}
