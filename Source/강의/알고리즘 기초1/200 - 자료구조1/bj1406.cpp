#include <stdio.h>
#include <stdlib.h>

void push(char* stack, int* cursor, char num)
{
    if (*cursor == 600000 || num == 0) return;

    stack[*cursor] = num;
    (*cursor)++;

}

char pop(char* stack, int* cursor)
{
    if (*cursor == 0) return 0;

    (*cursor)--;
    char result = stack[*cursor];
    stack[*cursor] = 0;

    return result;

}



int main()
{
    char* str = (char*)calloc(sizeof(char), 100001); scanf("%s", str);
    char whiteSpace = getchar();

    int n; scanf("%d", &n);
    whiteSpace = getchar();


    int length = 0; char* temp = str;
    while (temp[length] != NULL) { length++; }

    char* leftStack = (char*)calloc(sizeof(char), 600001);
    char* rightStack = (char*)calloc(sizeof(char), 600001);

    int leftCursor = 0, rightCursor = 0;
    for (int i = 0; i < length; i++)
    {
        push(leftStack, &leftCursor, str[i]);

    }


    for (int i = 0; i < n; i++)
    {
        char command = getchar();
        whiteSpace = getchar();

        switch (command)
        {
        case 'P':
        {
            char ch = getchar(); whiteSpace = getchar();
            push(leftStack, &leftCursor, ch);
            break;

        }
        case 'B':
        {
            pop(leftStack, &leftCursor);
            break;

        }
        case 'L':
        {
            char ch = pop(leftStack, &leftCursor);
            push(rightStack, &rightCursor, ch);
            break;

        }
        case 'D':
        {
            char ch = pop(rightStack, &rightCursor);
            push(leftStack, &leftCursor, ch);
            break;

        }
        }
    }

    while (rightStack[0] != 0)
    {
        char ch = pop(rightStack, &rightCursor);
        push(leftStack, &leftCursor, ch);

    }


    for (int i = 0; leftStack[i] != 0; i++)
    {
        printf("%c", leftStack[i]);

    }

    return 0;
}


