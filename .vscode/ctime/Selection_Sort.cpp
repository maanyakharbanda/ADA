#include<bits/stdc++.h>
#include<ctime>
#include<vector>
using namespace std;
void selection_sort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        int didSwap=0;
    int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    if(i!=min){
        swap(arr[i],arr[min]);
        didSwap=1;
    }
    if(didSwap==0){
        break;
    }
    }
}
void input_generator(vector<pair<int,int>>&store){
    for(int i=10;i<=1e4;i+=1000){
        vector<int>arr(i);
        generate(arr.begin(),arr.end(),rand);
        clock_t time_req;
        int t=0;
        for(int m=0;m<10;m++){
            time_req=clock();
            selection_sort(arr,i);
            time_req=clock()-time_req;
            t+=time_req;
        }
        t=(t/10);
        store.push_back({i,t});
    }
}
void display(vector<int>arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    vector<pair<int,int>>store;
    input_generator(store);
    cout<<"Number of Inputs "<<"     "<<"Time "<<endl;
    for(auto i:store){
        cout<<i.first<<"                    "<<i.second<<endl;
    }
    // clock_t time_req;
    // random number generate
    // int n;
    // cout<<"How many numbers you want to generate?"<<endl;
    // cin>>n;
// vector<int>r(n);
//  generate(r.begin(),r.end(),rand);
//     cout<<"Random Numbers"<<endl;
    //  for(auto i:r)
    //  cout<<i<<" ";
    //  cout<<endl;

//             time_req=clock();
//             selection_sort(arr,i);
//             time_req=clock()-time_req;
//             selection_sort(r,n);
// cout<<"Time taken by selection sort: "<<(float)time_req/CLOCKS_PER_SEC<<endl;
// cout<<"After Sorting"<<endl;
// display(r,n);
return 0;
}