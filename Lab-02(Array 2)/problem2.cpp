#include<bits/stdc++.h>
using namespace std;

void insertElements(int array[], int &n, int item, int pos){
    for(int i=n-1;i>=pos;i--){
        array[i+1] = array[i];
    }
    array[pos] = item;

    n++;
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

int main(){
    int array[100];
    int n;

    inputArray(array,n);
    displayArray(array,n);

    int item,pos;
    cout<<"Enter item to insert: ";
    cin>>item;
    cout<<"Enter position to insert: ";
    cin>>pos;

    if(pos<0 || pos>n){
        cout<<"Invalid positional!";
        cout<<endl;

        return 0;
    }

    insertElements(array,n,item,pos);
    displayArray(array,n);

    return 0;
}