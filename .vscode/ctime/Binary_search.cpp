#include<bits/stdc++.h>
#include<vector>
#include<ctime>
#include<numeric>
using namespace std;
bool binary_search(vector<int>arr,int s,int e,int key){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return false;
}
void evaluate(vector<pair<int,int>>&store){
    for(int i=10;i<1e4;i+=1000){
    vector<int>arr(i);
    generate_n(arr.begin(),i,rand);
    sort(arr.begin(),arr.end());
    clock_t time_req=clock();
    int t=0;
    uniform_int_distribution<int> distribution(0, i - 1);
    mt19937 engine; // Mersenne Twister 19937 generator 
    for(int m=0;m<10;m++){
        time_req=clock();
        binary_search(arr,0,i-1,arr[distribution(engine)]);
        time_req=clock()-time_req;
        t+=time_req;
    }
    t=t/10;
    store.push_back({i,t});
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