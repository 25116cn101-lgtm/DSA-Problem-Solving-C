#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
    int i, k = 1;

    if (numsSize == 0)
        return 0;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k - 1])
            nums[k++] = nums[i];
    }

    return k;
}

int main(void) {
    int nums[100], n, i, k;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 0 || n > 100)
        return 0;

    printf("Enter sorted elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    k = removeDuplicates(nums, n);

    printf("Number of unique elements: %d\n", k);
    printf("Array after removing duplicates: ");

    for (i = 0; i < k; i++)
        printf("%d ", nums[i]);

    printf("\n");
    return 0;
}
