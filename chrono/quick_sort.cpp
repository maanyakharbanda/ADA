#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
    while(arr[i]<=pivot && i<=high-1){
        i++;
    }
    while(arr[j]>pivot && j>=low+1){
        j--;
    }
    if(i<j){
        swap(arr[i],arr[j]);
    }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    else{
    int p_index=partition(arr,low,high);
    quicksort(arr,low,p_index-1);
    quicksort(arr,p_index+1,high);
    }
}
int main(){
    int arr[5]={2,3,1,5,4};
    int low=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,low,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}