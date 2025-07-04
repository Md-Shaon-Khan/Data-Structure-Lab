#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int i)
{
    int largest = i;          
    int left = 2 * i + 1;       
    int right = 2 * i + 2;      

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        // Manual swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    // One by one extract elements from heap
    for (int i = size - 1; i >= 1; i--)
    {
        // Manual swap arr[0] with arr[i]
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {4, 23, 4, 56, 1, 93, 56};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
