#include<bits/stdc++.h>
using namespace std;

void deletePosition(int array[], int &n, int pos)
{
    for(int i=pos;i<n;i++){
        array[i] = array[i+1]; 
    }

    n--;
}
void inputArray(int array[],int &n){
    cout<<"Enter the number of elements:";
    cin>>n;

    cout<<"Enter n elements:";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
}

void displayArray(int array[], int n){
    cout<<"Array elements are:";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int array[100];
    int n;

    inputArray(array,n);
    displayArray(array,n);

    int pos;
    cout<<"Enter the position to delete:";
    cin>>pos;

    deletePosition(array,n,pos);
    displayArray(array,n);

}