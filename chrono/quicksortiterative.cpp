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
        while(arr[j]>=pivot && j>=low+1){
            j--;
        }
        if(i<j){
        swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quick_sort_iterative(int arr[],int l,int h){
    int stack[h-l+1];
    int top=-1;
    stack[++top]=l;
    stack[++top]=h;
    while(top>=0){
        h=stack[top--];
        l=stack[top--];
        int p=partition(arr,l,h);
        if(p-l>1){
            stack[++top]=l;
            stack[++top]=p-1;
        }
        if(p+1<h){
            stack[++top]=p+1;
            stack[++top]=h;
        }
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[5]={5,3,2,4,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int h=n-1;
    print(arr,n);
    quick_sort_iterative(arr,l,h);
    print(arr,n);
}