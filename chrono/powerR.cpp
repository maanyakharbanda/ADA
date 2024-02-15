#include<iostream>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;
int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=power(a,b/2);
    if(b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
int evaluate(int a,int b){
    int t=0;
    int avg=0;
    for(int m=0;m<10;m++){
        auto start=high_resolution_clock::now();
        power(a,b);
        auto stop=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(stop-start);
        t+=duration.count();
    }
    avg=t/10;
}
int main(){
    int a,b;
    cout<<"Enter a and b: "<<endl;
    cin>>a>>b;
    cout<<"Power: "<<power(a,b)<<endl;
    cout<<"Time Taken: "<<evaluate(a,b)<<endl;
}