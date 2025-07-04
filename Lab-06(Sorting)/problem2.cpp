#include<bits/stdc++.h>
using namespace std;
 
int partition(int arr[], int start, int end)
{
    int index = start - 1;
    int pivot = arr[end];

    for(int j = start; j < end; j++)
    {
        if(arr[j] <= pivot)
        {
            index++;
            int temp = arr[j];
            arr[j] = arr[index];
            arr[index] = temp;
        }
    }

    index++;
    int temp = arr[index];
    arr[index] = arr[end];
    arr[end] = temp;

    return index;
}
 
void quickSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int pivotIndex = partition(arr, start, end);

        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}
 
int main()
{
    int arr[] = {12, 3, 45, 23, 78, 1, 94};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}