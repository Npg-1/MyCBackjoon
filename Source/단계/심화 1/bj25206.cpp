#include <stdio.h>
#include <stdlib.h>

double getAlphabet(char* temp)
{
    switch (temp[0])
    {
    case 'A':
        if (temp[1] == '+') return 4.5;
        else return 4.0;

    case 'B':
        if (temp[1] == '+') return 3.5;
        else return 3.0;

    case 'C':
        if (temp[1] == '+') return 2.5;
        else return 2.0;

    case 'D':
        if (temp[1] == '+') return 1.5;
        else return 1.0;

    case 'F':
        return 0.0;

    }
}

int main()
{
    double sumScoreNGrade = 0;
    double sumScore = 0;

    for (int i = 0; i < 20; i++)
    {
        char thisIsNotUse[100];
        scanf("%s", thisIsNotUse);

        double score;
        char alphabet[3];

        scanf("%lf", &score);
        scanf("%s", alphabet);

        if (alphabet[0] == 'P') continue;

        double grade = getAlphabet(alphabet);

        sumScoreNGrade += score * grade;
        sumScore += score;

    }

    printf("%.6lf", sumScoreNGrade / sumScore);

    return 0;

}