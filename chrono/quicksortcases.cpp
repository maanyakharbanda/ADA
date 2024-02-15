#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
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
void quicksort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    else{
    int p=partition(arr,low,high);
    quicksort(arr,low,p-1);
    quicksort(arr,p+1,high);
    }
}
int main(){
    // best case
    // int arrb[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int low = 0;
    // int high = 9; // index of the last element
    // auto start = high_resolution_clock::now();
    // quicksort(arrb, low, high);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken for the best case: " << duration.count() << " microseconds" << endl;

    // // average case
    // int arra[10] = {2, 4, 6, 5, 10, 8, 1, 7, 9, 3};
    // start = high_resolution_clock::now();
    // quicksort(arra, low, high);
    // stop = high_resolution_clock::now();
    // duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken for the average case: " << duration.count() << " microseconds" << endl;

    // // worst case
    // int arrw[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // start = high_resolution_clock::now();
    // quicksort(arrw, low, high);
    // stop = high_resolution_clock::now();
    // duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken for the worst case: " << duration.count() << " microseconds" << endl;
    int arr[5]={2,4,5,3,1};
    int low=0;
    int high=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,low,high);
    for(int i=low;i<high;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}