#include <iostream>
using namespace std;

void takeInput(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    takeInput(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
