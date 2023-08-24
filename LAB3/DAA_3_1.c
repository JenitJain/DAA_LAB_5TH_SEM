#include <stdio.h>

int binary_search(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            // If the element is found at mid, then its leftmost appearance
            // is at mid itself.
            return mid;
        } else if (arr[mid] > x) {
            // The element cannot be present in the right half of the array.
            high = mid - 1;
        } else {
            // The element cannot be present in the left half of the array.
            low = mid + 1;
        }
    }
    return -1;
}

int find_leftmost_appearance(int arr[], int n, int x) {
    int index = binary_search(arr, 0, n - 1, x);
    if (index == -1) {
        printf("Element %d not found in the array.\n", x);
    } else {
        printf("Element %d found at index position %d.\n", x, index);
        int count = 0;
        while (arr[index] == x) {
            index++;
            count++;
        }
        printf("Number of comparisons made: %d\n", count);
    }
    return 0;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter the key to be searched: ");
    scanf("%d", &x);
    find_leftmost_appearance(arr, n, x);
    return 0;
}

