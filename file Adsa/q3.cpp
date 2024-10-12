#include <iostream>
using namespace std;

void sortArray(int arr[], int size) {
    int low = 0, mid = 0, high = size - 1;

    // Traverse the array and sort it
    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap arr[low] and arr[mid]
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            // Simply move mid to the next element
            mid++;
        }
        else if (arr[mid] == 2) {
            // Swap arr[mid] and arr[high]
            int temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;
            high--;
        }
    }
}

int main() {
    int arr[] = {2, 0, 1, 2, 1, 0, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, size);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
