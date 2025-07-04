#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void display(int arr[],int n){
    
    cout<<"Sorted elements are: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

int main(){
    int size;
    cout<<"Enter the array size: ";
    cin>>size;
    
    int arr[size];
    cout<<"Enter the elements: ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
    insertionSort(arr,size);
    display(arr,size);

    return 0;
    
}