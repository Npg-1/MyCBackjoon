#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char* stack, char n, int* stackSize)
{
    if (*stackSize == 100000) return;
    stack[*stackSize] = n;
    (*stackSize)++;

}

char pop(char* stack, int* stackSize)
{
    if (*stackSize == 0) return -1;

    char result = stack[*stackSize - 1];
    stack[--(*stackSize)] = 0;

    return result;

}

int main()
{
    char* stack = (char*)calloc(sizeof(char), 100001);
    int stackSize = 0;
    char* str = (char*)calloc(sizeof(char), 100001);
    fgets(str, 100001, stdin);

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<')
        {
            while (str[i] != '>')
            {
                printf("%c", str[i]);
                i++;
            }
            printf("%c", str[i]);


        }
        else if (str[i] == ' ') printf("%c", ' ');
        else
        {
            while (i < strlen(str) && str[i] != ' ' && str[i] != '<')
            {
                push(stack, str[i++], &stackSize);

            }

            while (stackSize != 0)
            {
                char temp = pop(stack, &stackSize);
                if (temp == '\n') continue;
                else printf("%c", temp);

            }

            if (str[i] == ' ') printf(" ");
            else i--;

        }
    }

    return 0;

}
