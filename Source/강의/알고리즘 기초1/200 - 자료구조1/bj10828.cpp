#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size(int* stack);
void push(int* stack, int n);
int pop(int* stack);
int empty(int* stack);
int top(int* stack);

void excuteCommand(char* command, int* stack);

int main()
{
    int n; scanf("%d", &n);
    char** commands = (char**)calloc(sizeof(char*), n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        char temp[13]; fgets(temp, 13, stdin);
        commands[i] = (char*)calloc(sizeof(char), 13);
        strcpy(commands[i], temp);

        int j = 0;
        for (j = 0; commands[i][j] != NULL; j++) {}
        commands[i][j - 1] = NULL;

    }

    int stack[10001] = { 0, };
    for (int i = 0; i < n; i++) excuteCommand(commands[i], stack);

    return 0;
}


void excuteCommand(char* command, int* stack)
{
    switch (command[0])
    {
    case 'p':
    {
        if (command[1] == 'u')  // push
        {
            char str[7] = { 0, };
            int i = 0;
            for (i = 5; command[i] != NULL; i++)
            {
                str[i - 5] = command[i];
            }
            str[i - 5] = NULL;
            int num = atoi(str);
            push(stack, num);

        }
        else    // pop
        {
            printf("%d\n", pop(stack));

        }

        break;
    }
    case 's':   // size
    {
        printf("%d\n", size(stack));
        break;

    }
    case 'e':   // empty
    {
        printf("%d\n", empty(stack));
        break;

    }
    case 't':   // top
    {
        printf("%d\n", top(stack));
        break;

    }
    }
}


void push(int* stack, int n)
{
    int length = size(stack);

    //if (length >= 10000) return;
    if (length == 10000) return;
    stack[length] = n;

}


int pop(int* stack)
{
    int length = size(stack);
    if (length == 0) return -1;

    int result = stack[length - 1];
    stack[length - 1] = 0;

    return result;

}


int size(int* stack)
{
    int size = 0; while (stack[size] != 0) size++;
    return size;

}


int empty(int* stack)
{
    if (size(stack) == 0) return 1;
    return 0;

}


int top(int* stack)
{
    if (size(stack) == 0) return -1;
    return stack[size(stack) - 1];

}



