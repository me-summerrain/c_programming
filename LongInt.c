#include <stdio.h>
#define SIZE 100;

int Length(long long n);
int main(void) {
    long long n;
    long long m;
    printf("Iki sany uly san girizin(2^32+):\n");
    scanf("%lld %lld", &n, &m);
    int len1 = Length(n);
    int len2 = Length(m);

    int a[len1];
    int b[len2];

    int goshmak[100];
    int ayyrmak[100];
    int i, j;

    // sanyn her bir belgisini massiwa salmak
    for (i = len1 - 1, j = len2 - 1; i >= 0, j >= 0; i--, j--) {
        a[i] = n % 10;
        n = n / 10;
        b[j] = m % 10;
        m = m / 10;
    }

    // Goshmak
    int len = len1 > len ? len1 : len2;
    if (len1 == len2)
        len = len1;
    for (int i = len - 1; i >= 0; i--) {
        goshmak[i] = a[i] + b[i];
        if (a[i] + b[i] > 9) {
            a[i - 1] += 1;
        }
    }

    printf("Massiwa yerleshdirlen gornushi\n");
    for (i = 0; i < len; i++) {
        printf("%d", goshmak[i]);
    }

    return 0;
}

int Length(long long n) {
    int len = 0;
    while (n > 0) {
        int i = n % 10;
        n = n / 10;
        len++;
    }

    return len;
}
