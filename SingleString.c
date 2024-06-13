#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isUnique(char *astr)
{
    int i, j;
    bool isUnq = true;
    int len = strlen(astr);
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (astr[j] == astr[i])
            {
                isUnq = false;
                break;
            }
        }
    }

    return isUnq;
}

int main()
{
    bool tf = isUnique("abc");
    printf("%d\n", tf);

    return 0;
}