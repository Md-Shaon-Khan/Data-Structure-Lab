#include <iostream>
using namespace std;

void takeInput(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

bool search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return true;
    return false;
}

int main() {
    int n, key;
    cin >> n;
    int arr[n];
    takeInput(arr, n);
    cin >> key;
    if (search(arr, n, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}