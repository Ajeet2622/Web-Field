#include <iostream>
using namespace std;

// Swap function to manually swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function similar to QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Select the last element as pivot
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Manually swap elements
        }
    }
    swap(arr[i + 1], arr[high]);  // Manually swap pivot to its correct position
    return i + 1;
}

// Quickselect function to find the Kth smallest element
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        // Partition the array
        int pivotIndex = partition(arr, low, high);

        // If pivotIndex matches K-1, return the element
        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        // If K is smaller, search the left side
        if (pivotIndex > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);

        // If K is larger, search the right side
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
    return -1;  // This condition should never occur if K is valid
}

// Function to find Kth smallest element
int findKthSmallest(int arr[], int size, int k) {
    return quickSelect(arr, 0, size - 1, k);
}

// Function to find Kth largest element (by finding the (n-k+1)th smallest)
int findKthLargest(int arr[], int size, int k) {
    return quickSelect(arr, 0, size - 1, size - k + 1);
}

int main() {
    int arr[] = {23, 56, 12, 89, 2, 45, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;  // Let's find the 3rd smallest and 3rd largest elements

    cout << "Kth smallest element: " << findKthSmallest(arr, size, k) << endl;
    cout << "Kth largest element: " << findKthLargest(arr, size, k) << endl;

    return 0;
}
