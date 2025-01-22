/*Shifting:

Finds the correct position for the current element (key).
Moves all larger elements one step ahead to make space.
Fewer write operations, so it's often more efficient than swapping.
Swapping:

Moves the current element into its correct position by repeatedly swapping it with its predecessor.
Performs multiple swaps for each misplaced element.
Simpler to implement but involves more write operations.*/
#include <stdio.h>

// Insertion Sort with Shifting
void insertionSortShifting(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Shift elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Insert the key into its correct position
    }
}

// Insertion Sort with Swapping
void insertionSortSwapping(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            // Swap the elements if they are out of order
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
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

    // Insertion Sort with Shifting
    insertionSortShifting(arr1, n);
    printf("Sorted array (Shifting): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Insertion Sort with Swapping
    insertionSortSwapping(arr2, n);
    printf("Sorted array (Swapping): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
