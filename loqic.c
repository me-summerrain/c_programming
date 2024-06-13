#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool hasAlternatingBits(int n) {
    int a[100], i = 0;
    while (n > 0) {
        a[i] = n % 2;
        n = n / 2;
        i++;
    }
    int len = i;
    bool res = true;

    for (i = 0; i < len - 1; i++) {
        if (a[i] == a[i + 1]) {
            res = false;
            break;
        }
    }

    return res;
}

int main() {
    bool a = hasAlternatingBits(5);
    printf("%d", a);
    return 0;
}