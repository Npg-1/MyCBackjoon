#include <stdio.h>
#include <stdlib.h>

int getSize(int* stack);
void push(int* stack, int n);
int pop(int* stack);
int getTop(int* stack);

int main()
{
    int n; scanf("%d", &n);

    int stack[100001] = { 0, };
    char result[200001] = { 0, };
    int idx = 0;
    int highNum = 0;
    bool isWrong = false;
    for (int i = 0; i < n; i++)
    {
        int a; scanf("%d", &a);

        if (a < getTop(stack))
            isWrong = true;


        for (int j = highNum + 1; j <= a; j++)
        {
            push(stack, j);
            result[idx++] = '+';

        }
        pop(stack);
        highNum = a > highNum ? a : highNum;

        result[idx++] = '-';

    }

    if (isWrong) printf("NO\n");
    else
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("%c\n", result[i]);

        }
    }

    return 0;

}

void push(int* stack, int n)
{
    int length = getSize(stack);

    if (length == 100000) return;
    stack[length] = n;

}


int pop(int* stack)
{
    int length = getSize(stack);
    if (length == 0) return -1;

    int result = stack[length - 1];
    stack[length - 1] = 0;

    return result;

}


int getSize(int* stack)
{
    int size = 0; while (stack[size] != 0) size++;
    return size;

}


int getTop(int* stack)
{
    if (getSize(stack) == 0) return -1;
    return stack[getSize(stack) - 1];

}
