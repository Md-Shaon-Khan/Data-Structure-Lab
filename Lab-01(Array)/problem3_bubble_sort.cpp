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
    cout<<"Enter how many numbers: ";
    int n;
    cin >> n;

    int arr[n];
    cout<<"Enter the numbers: ";
    takeInput(arr, n);
    bubbleSort(arr, n);
    cout<<"After sorting:";
    printArray(arr, n);
    return 0;
}
