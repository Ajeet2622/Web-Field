#include <iostream>
using namespace std;

void findMaxMin(int arr[], int size, int &max, int &min) {
    max = arr[0];
    min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
}

int main() {
    int arr[] = {23, 56, 12, 89, 2, 45, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, size, max, min);

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;

    return 0;
}
