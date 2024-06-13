#include <stdio.h>
#define SIZE 100

int Length(long long n);

int main()
{
    long long n;
    long long m;
    printf("Iki sany uly san girizin(2^32+):\n");
    scanf("%lld %lld", &n, &m);

    int a[SIZE];
    int b[SIZE];
    int c[SIZE];

    int i, j;
    int a_index = SIZE;
    int b_index = SIZE;

    // n sany massiwa yerleshdiryar
    for (i = SIZE - 1; i >= 0; i--)
    {
        a[i] = n % 10;
        n = n / 10;
        a_index -= 1;
        if (n == 0)
            break;
    }

    int len = Length(n);
    if (Length(n) < Length(m))
        len = Length(m);

    // m sany massiwa yerleshdiryar
    for (i = SIZE - 1; i >= 0; i--)
    {
        b[i] = m % 10;
        m = m / 10;
        b_index -= 1;
        if (m == 0)
            break;
    }

    for (i = SIZE - 1; i >= SIZE - len; i--)
    {
        c[i] = a[i] + b[i];
        if (c[i] > 9)
        {
            int t = c[i];
            c[i] = t % 10;
            a[i - 1] += t / 10;
        }
    }
    for (i = SIZE - len; i < SIZE; i++)
    {
        printf("%d", c[i]);
    }

    // Messiwin duzumini ekerana chykaryar
    // for (i = a_index; i < SIZE; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    // for (i = b_index; i < SIZE; i++)
    // {
    //     printf("%d ", b[i]);
    // }

    return 0;
}

int Length(long long n)
{
    int len = 0;
    while (n > 0)
    {
        int i = n % 10;
        n = n / 10;
        len++;
    }

    return len;
}
