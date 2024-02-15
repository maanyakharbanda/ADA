#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
void partition(int arr[],int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j){
        swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[6]={2,3,4,5,1,6};
    int n=6;
    int low=0;
    int high=6-1;
    partition(arr,low,high);
    display(arr,n);
}