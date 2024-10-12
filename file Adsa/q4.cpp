#include <iostream>
using namespace std;

void moveZeroesToEnd(int arr[], int size) {
    int nonZeroIndex = 0;  // Pointer to track the position of the next non-zero element

    // Traverse the array and move non-zero elements to the front
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex++;
        }
    }

    // Fill the remaining positions with zeroes
    while (nonZeroIndex < size) {
        arr[nonZeroIndex] = 0;
        nonZeroIndex++;
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    moveZeroesToEnd(arr, size);

    // Output the modified array
    cout << "Array after moving zeroes: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
