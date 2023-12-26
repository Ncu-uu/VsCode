#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // 初始化有序数组
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    printf("\n目标值为 ");
    scanf("%d", &target);

    int index = binarySearch(arr, size, target);

    if (index != -1) {
        printf("目标值 %d 在数组中的下标为 %d\n", target, index);
    } else {
        printf("目标值 %d 不存在于数组中\n", target);
    }

    return 0;
}
