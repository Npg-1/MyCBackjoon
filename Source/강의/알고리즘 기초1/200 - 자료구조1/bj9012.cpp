#include <stdio.h>
#include <string.h>

int main()
{
    int n; scanf("%d", &n);

    for (int a = 0; a < n; a++)
    {
        char str[51]; scanf("%s", str);
        int count = 0;
        bool isWrong = false;

        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == '(') count++;
            else if (str[j] == ')')
            {
                if (count == 0)
                {
                    isWrong = true;
                    break;

                }
                count--;

            }
        }

        if (count != 0) isWrong = true;

        if (isWrong) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}


