/* Heapify vs. Insert All Elements Heapify: Build a heap from the bottom up in
 𝑂 ( 𝑛 ) O(n) time. Insert All Elements: Insert elements one by one into a heap,
 taking 𝑂 ( 𝑛 log ⁡ 𝑛 ) O(nlogn) time.

Key Differences Between Heapify Sorting and Insert-All-Elements
Heapify Sorting:

The entire array is treated as a heap.
Uses a bottom-up approach: first builds the heap by heapifying nodes starting from the last non-leaf node up to the root.
Applies the heap property to extract the root and sort the array.
Insert All Elements:

Elements are inserted one at a time into an initially empty heap.
After each insertion, the heap property is restored by sifting up (moving the new element up until it's in the right spot).
This is more of a top-down approach.

 */

#include <stdio.h>

// Function to "heapify" a subtree rooted at index `i`
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // Compare root with left child
    if (left < n && arr[left] > arr[largest]) {
        printf("Compare %d and %d\n", arr[left], arr[largest]);
        largest = left;
    }

    // Compare largest so far with right child
    if (right < n && arr[right] > arr[largest]) {
        printf("Compare %d and %d\n", arr[right], arr[largest]);
        largest = right;
    }

    // If root is not largest, swap and continue heapifying
    if (largest != i) {
        printf("Swap %d and %d\n", arr[i], arr[largest]);
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Build a heap using heapify
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Building heap using heapify (Bottom-Up)...\n");
    buildHeap(arr, n);

    printf("Heap after building:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


