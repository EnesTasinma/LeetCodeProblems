#include "stdio.h"

int find_Zero(int arr[], int left, int right){
    if(left == right){
        if(arr[left] == 0){
            return left;
        } else {
            return -1;
        }
    }
    int mid = left + (right - left) / 2;
    if(arr[mid] == 0){
        return mid;
    } else if(arr[mid] > 0){
        return find_Zero(arr, left, mid - 1);
    } else {
        return find_Zero(arr, mid + 1, right);  
    }
}

int main() {
    int arr[] = {-3, -1, 0, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = find_Zero(arr, 0, size - 1);
    if(index != -1){
        printf("Zero found at index: %d\n", index);
    } else {
        printf("Zero not found in the array.\n");
    }
    return 0;
}
