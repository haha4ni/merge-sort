#include <stdio.h>
#include <stdlib.h>


void merge_sort_haha(int* arr, int* reg, int start, int end)
{
    if (start >= end)
        return;
    int len = end - start;
    int mid = len / 2 + start;

    int start1 = start;
    int start2 = mid + 1;
    int end1 = mid;
    int end2 = end;

    merge_sort_haha(arr, reg, start1, end1);
    merge_sort_haha(arr, reg, start2, end2);

    int index = start;
    while (start1 <= end1 && start2 <= end2)
        reg[index++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[index++] = arr[start1++];
    while (start2 <= end2)
        reg[index++] = arr[start2++];

    for (int i = start;i <= end;i++)
        arr[i] = reg[i];
}




void merge_sort(int* arr, const int len) {
    int *reg =  (int*)malloc(4*len);
    merge_sort_haha(arr, reg, 0, len - 1);
}


int main()
{
    int array[10] = { 5, 8, 7, 6, 3, 4, 0, 9, 2, 1 };
    merge_sort(array, 10);


    for (int i = 0;i < 10;i++)
        printf("%d ", array[i]);

    return 0;
}