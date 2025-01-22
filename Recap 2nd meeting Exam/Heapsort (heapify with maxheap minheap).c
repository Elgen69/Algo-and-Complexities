#include <stdio.h>

// Function to heapify a subtree rooted at index i (for max-heap)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;       // Assume root is the largest
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not the root, swap and heapify the affected subtree
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapifyMax(arr, n, largest);
    }
}

// Function to heapify a subtree rooted at index i (for min-heap)
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;      // Assume root is the smallest
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // Check if left child exists and is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // Check if right child exists and is smaller than current smallest
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not the root, swap and heapify the affected subtree
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        // Recursively heapify the affected subtree
        heapifyMin(arr, n, smallest);
    }
}

// Heapsort using max-heap
void heapSortMax(int arr[], int n) {
    // Build max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max-heapify on the reduced heap
        heapifyMax(arr, i, 0);
    }
}

// Heapsort using min-heap
void heapSortMin(int arr[], int n) {
    // Build min-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call min-heapify on the reduced heap
        heapifyMin(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to demonstrate max-heap and min-heap heapsort
int main() {
    int arrMax[] = {12, 11, 13, 5, 6, 7};
    int arrMin[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arrMax) / sizeof(arrMax[0]);

    printf("Original array:\n");
    printArray(arrMax, n);

    // Sort using max-heap
    heapSortMax(arrMax, n);
    printf("Sorted array (Max-Heap Heapsort):\n");
    printArray(arrMax, n);

    // Sort using min-heap
    heapSortMin(arrMin, n);
    printf("Sorted array (Min-Heap Heapsort):\n");
    printArray(arrMin, n);

    return 0;
}
