#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* str = (char*)calloc(sizeof(char), 100001);
    scanf("%s", str);

    int n = 0;
    int result = 0;
    int temp = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            n++;
        }
        else    // str[i] == ')'
        {
            n--;
            if (str[i - 1] == '(')
            {
                result += (n + temp);
                temp = 0;

            }
            else
            {
                temp++;
            }
        }
    }

    result += temp;
    printf("%d\n", result);

    return 0;

}

