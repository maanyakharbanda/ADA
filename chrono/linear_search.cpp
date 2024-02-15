#include<bits/stdc++.h>
#include<vector>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;
bool linear_search(vector<int>&arr,int n,int key){
    if(n==0){
        return false;
    }
    if(arr[n-1]==key){
        return true;
    }
    return linear_search(arr,n-1,key);
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=10;i<1e4;i+=1000){
        vector<int>arr(i);
        generate_n(arr.begin(),i,rand);
        int t=0;
        int avg=0;
        uniform_int_distribution<int> distribution(0, i - 1);
        mt19937 engine; // Mersenne Twister 19937 generator
        for(int m=0;m<10;m++){
            auto start=high_resolution_clock::now();
            linear_search(arr, i, arr[distribution(engine)]);
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
    cout<<"Number of inputs"<<" "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<" "<<i.second<<endl;
    }
}