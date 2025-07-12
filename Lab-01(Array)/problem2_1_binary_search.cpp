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

bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    int n, key;
    cout<<"Enter how many number:";
    cin >> n;
    int arr[n];
    cout<<"Enter the numbers:";
    takeInput(arr, n);
    cout<<"Enter the search item:";
    cin >> key;
    bubbleSort(arr, n);
    if (binarySearch(arr, n, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}
