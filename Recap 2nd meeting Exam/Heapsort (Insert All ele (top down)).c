#include <stdio.h>

// Function to "sift up" an element to maintain the heap property
void siftUp(int arr[], int n) {
    int i = n - 1; // Start from the last inserted element
    while (i > 0) {
        int parent = (i - 1) / 2; // Find parent index

        printf("Compare %d and %d\n", arr[i], arr[parent]);
        if (arr[i] > arr[parent]) { // If child is larger than parent
            printf("Swap %d and %d\n", arr[i], arr[parent]);
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;

            i = parent; // Move up to the parent
        } else {
            break; // Heap property is satisfied
        }
    }
}

// Build a heap by inserting elements one by one
void buildHeapByInsertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        siftUp(arr, i + 1);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Building heap by inserting elements (Top-Down)...\n");
    buildHeapByInsertion(arr, n);

    printf("Heap after building:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
