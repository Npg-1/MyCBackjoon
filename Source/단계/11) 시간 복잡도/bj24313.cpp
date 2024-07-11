#include <stdio.h>

int main()
{
    int a1, a0, c, n0;
    scanf("%d%d%d%d", &a1, &a0, &c, &n0);

    bool isTrue = true;
    for (int i = n0; i <= 100; i++)
    {
        if (a1 * i + a0 > c * i)
        {
            isTrue = false;
            break;
        }
    }


    if (isTrue)
        printf("1");
    else
        printf("0");

    return 0;

}
