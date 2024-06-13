#include <stdio.h>
#include <stdlib.h>

/**
 * N: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    returnSize = (int *)malloc(4 * sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[j] + nums[i] == target)
            {
                returnSize[0] = i;
                returnSize[1] = j;
            }
        }
    }
    return returnSize;
}

int main()
{
    int a[4] = {2, 7, 11, 15};
    int target = 9;
    int b[2];
    int *ar = twoSum(a, 4, target, b);
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", ar[i]);
    }
    free(ar);

    return 0;
}
