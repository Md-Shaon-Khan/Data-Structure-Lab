#include<bits/stdc++.h>
using namespace std;

void medianArray(int array[],int n){
    if(n%2==0){
        int median = ((array[(n-1)/2]) + (array[((n-1)/2)+1]))/2;
        cout<<"Median number is "<<median<<endl;
    }
    else{
        int median = array[(n-1)/2];
        cout<<"Median number is "<<median<<endl;
    }
}

void inputArray(int array[],int n){

    int value;

    cout<<"Enter the elements:";
     for(int i=0;i<n;i++)
     {
        cin>>array[i];
     }

}

void sortArray(int array[],int n){
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void displayArray(int array[], int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;

    cout<<"How many number for you want to calculate the median:";
    cin>>n;

    int array[n];
    inputArray(array,n);
    cout<<"Before sorting"<<endl;
    displayArray(array,n);

    sortArray(array,n);
    cout<<"After sorting"<<endl;
    displayArray(array,n);

    medianArray(array,n);



}
