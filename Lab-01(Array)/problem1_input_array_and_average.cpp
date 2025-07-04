#include <iostream>
using namespace std;

void takeInput(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

double average(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (double)sum / n;
}

int main() {
    int n;
    cout<<"Enter how many numbers: ";
    cin >> n;
    cout<<"Enter the numbers: ";
    int arr[n];
    takeInput(arr, n);
    cout << "Average: " << average(arr, n) << endl;
    return 0;
}
