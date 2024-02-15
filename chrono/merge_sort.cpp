#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high){
    int temp[5];
    int index=0;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp[index++]=arr[left];
            left++;
        }
        else{
            temp[index++]=arr[right];
            right++;
        }
    }
        while(left<=mid){
            temp[index++]=arr[left];
            left++;
        }
        while(right<=high){
            temp[index++]=arr[right];
            right++;
        }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int arr[5]={2,3,1,5,4};
    int low=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,low,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}