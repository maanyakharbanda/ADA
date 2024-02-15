#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;
int power(int a,int b){
    int y=b;
    int ans=1;
    int x=a;
    while(y>0){
        if(y%2==0){
            x=x*x;
            y=y/2;
        }
        else{
            ans=ans*x;
            y=y-1;
        }
    }
    return ans;
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
    return avg;
}
int main(){
    int a;
    int b;
    cout<<"Enter a and b"<<endl;
    cin>>a>>b;
    cout<<"Answer is: "<<power(a,b)<<endl;
    cout<<"Average time taken: "<<evaluate(a,b)<<endl;
}