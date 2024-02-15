#include<iostream>
#include<algorithm>// for swap (you can add this header file (it's choice)).
#include<cstdlib>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
int min_index(vector<int>&arr, int i, int j) {
    if (i == j) {
        return i; // only one element exists, that means that element will be the least element
    }
    int k = min_index(arr, i + 1, j);
    return (arr[i] < arr[k]) ? i : k;
}

void selection_sort(vector<int>&arr, int n, int index) {
    // base case
    if (index == n) {
        return;
    }
    // recursive case
    int k = min_index(arr, index, n - 1);
    if (k != index) {
        swap(arr[k], arr[index]);
    }
    selection_sort(arr, n, index + 1);
}

void random_generator(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        arr[i]=rand();
    }
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=10;i<1e4;i+=1000){
    vector<int>arr(i);
    int index=0;
    int t=0;
    int avg=0;
    random_generator(arr,i);
    for(int m=0;m<10;m++){
        auto start=high_resolution_clock::now();
        selection_sort(arr,i,index);
        auto stop=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(stop-start);
        t+=duration.count();
    }
    avg=t/10;
    store.push_back({i,avg});
    }
}
int main(){
    vector<pair<int,int>>store;
    evaluate(store);
    cout<<"Number of Inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}