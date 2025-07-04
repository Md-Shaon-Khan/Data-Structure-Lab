#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {

    // Calculate sizes of two subarrays
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Create temporary arrays
    int left[len1];
    int right[len2];

    // Copy data to temp arrays left[] and right[]
    for (int i = 0; i < len1; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < len2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[start..end]
    int i = 0;  // Initial index of left[]
    int j = 0;  // Initial index of right[]
    int k = start;  // Initial index of merged subarray

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    display(arr, n);

    return 0;
}