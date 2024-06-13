#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    bool res = false;
    int arr[10];
    int len = 0, i = 0, j;

    // san belgilerini massiwa salmak
    if (x % 10 != 0) {
        while (x > 0) {
            arr[i] = x % 10;
            x /= 10;
            i++;
        }
        len = i;
        int mid = len / 2;

        // barlag gechirmek
        if (x < 0)
            res = false;
        else
            for (i = 0, j = len - 1; i <= mid, j >= mid; i++, j--) {
                if (arr[i] == arr[j])
                    res = true;
                else {
                    res = false;
                    break;
                }
            }
    } else if (x == 0)
        res = true;
    else
        res = false;

    return res;
}

int main() {
    int x;
    scanf("%d", &x);
    bool res = isPalindrome(x);
    printf("%d\n", res);

    return 0;
}
