#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size(char* stack);
void push(char* stack, char n);
char pop(char* stack);

int main()
{
    int n; scanf("%d", &n);
    getchar();

    char stack[1001] = { 0, };

    for (int i = 0; i < n; i++)
    {
        char temp[21] = { 0, };
        scanf("%s", temp);
        int whiteSpace = getchar();
        if (whiteSpace == ' ')
        {
            i--;
        }

        for (int i = 0; i < strlen(temp); i++)
        {
            push(stack, temp[i]);
        }

        for (int i = 0; i < strlen(temp); i++)
        {
            printf("%c", pop(stack));
        }

        printf(" ");

        if (whiteSpace == '\n') printf("\n");
    }



    return 0;
}


void push(char* stack, char n)
{
    int length = size(stack);

    if (length == 10000) return;
    stack[length] = n;

}


char pop(char* stack)
{
    int length = size(stack);
    if (length == 0) return -1;

    int result = stack[length - 1];
    stack[length - 1] = 0;

    return result;

}


int size(char* stack)
{
    int size = 0; while (stack[size] != 0) size++;
    return size;

}

