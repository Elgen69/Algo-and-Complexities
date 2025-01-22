#include <stdio.h>

// Function to sift up for max-heap
void siftUpMax(int arr[], int n) {
    int i = n;  // Index of the newly inserted element
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        // Swap parent with child if parent is smaller
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;

        // Move up to the parent index
        i = (i - 1) / 2;
    }
}

// Function to sift up for min-heap
void siftUpMin(int arr[], int n) {
    int i = n;  // Index of the newly inserted element
    while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
        // Swap parent with child if parent is larger
        int temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;

        // Move up to the parent index
        i = (i - 1) / 2;
    }
}

// Function to build a max-heap by inserting elements
void buildMaxHeap(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        siftUpMax(arr, i);  // Insert element and restore max-heap property
    }
}

// Function to build a min-heap by inserting elements
void buildMinHeap(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        siftUpMin(arr, i);  // Insert element and restore min-heap property
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to demonstrate insert-all-elements for max-heap and min-heap
int main() {
    int arrMax[] = {12, 11, 13, 5, 6, 7};
    int arrMin[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arrMax) / sizeof(arrMax[0]);

    printf("Original array:\n");
    printArray(arrMax, n);

    // Build max-heap by inserting elements
    buildMaxHeap(arrMax, n);
    printf("Max-Heap after inserting all elements:\n");
    printArray(arrMax, n);

    // Build min-heap by inserting elements
    buildMinHeap(arrMin, n);
    printf("Min-Heap after inserting all elements:\n");
    printArray(arrMin, n);

    return 0;
}
