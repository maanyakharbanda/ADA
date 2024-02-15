#include<bits/stdc++.h>
#include<ctime>
#include<vector>
using namespace std;
bool binary_search(int arr[],int s,int e,int key){
        if(s>e){
            return false;
        }
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            return true;;
        }
        else if(arr[mid]<key){
            return binary_search(arr,mid+1,e,key);
        }
        else{
            return binary_search(arr,s,mid-1,key);
        }
}
void input_generator(vector<pair<int,int>>&store){
    for(int i=10;i<1e4;i+=1000){
        vector<int>arr(i);
        generate(arr.begin(),arr.end(),rand);
        sort(arr.begin(),arr.end());
        clock_t time_req;
        int t=0;
        for(int m=0;m<10;m++){
            time_req=clock();
            binary_search(arr.data(),0, i - 1, arr[rand() % i]);
            time_req=clock()-time_req;
            t+=time_req;
        }
        t=t/10;
        store.push_back({i,t});
    }
}
int main(){
    vector<pair<int,int>>store;
    input_generator(store);
    cout<<"Number of Inputs"<<"  "<<"Time"<<endl;
    for(auto i:store){
        cout<<i.first<<"  "<<i.second<<endl;
    }
return 0;
}