#include <stdio.h>

// Bottom-Up Bubble Sort
void bubbleSortBottomUp(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  // Loop from start to end
        for (int j = 0; j < n - i - 1; j++) {  // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {  // Swap if out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Top-Down Bubble Sort
void bubbleSortTopDown(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {  // Loop backward
        for (int j = n - 1; j > n - i - 1; j--) {  // Compare backward
            if (arr[j - 1] > arr[j]) {  // Swap if out of order
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr1[] = {5, 3, 8, 6, 2};
    int arr2[] = {5, 3, 8, 6, 2};
    int n = 5;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Bottom-Up Bubble Sort
    bubbleSortBottomUp(arr1, n);
    printf("Sorted array (Bottom-Up): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Top-Down Bubble Sort
    bubbleSortTopDown(arr2, n);
    printf("Sorted array (Top-Down): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
