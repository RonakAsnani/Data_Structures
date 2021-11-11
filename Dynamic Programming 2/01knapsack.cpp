#include<bits/stdc++.h>
using namespace std;

int calc(int* w,int* v,int n,int weight,int value){
    
    
    if(weight < 0 || n<0){
        return 0;
    }
    if(weight == 0 || n==0){
        return value;
    }
    if(weight - w[0] >= 0){
        return max(calc(w+1,v+1,n-1,weight,value),calc(w+1,v+1,n-1,weight-w[0],value + v[0]));
    }else{
        return calc(w+1,v+1,n-1,weight,value);
    }
    
}


int main(){
    int n;
    cin>>n;
    int* w = new int[n];
    int* v = new int[n];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int weight;
    cin>>weight;

    cout<<calc(w,v,n,weight,0);
    return 0;
}