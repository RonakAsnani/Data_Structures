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

    int** a = new int*[n+1];
    for(int i=0;i<=n;i++){
        a[i] = new int[weight+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=weight;j++){
            if(i == 0 || j==0){
                a[i][j] = 0;
            }else{
                if(j - w[i-1] >= 0){
                    a[i][j] = max(a[i-1][j-w[i-1]] + v[i-1],a[i-1][j]);
                }else{
                    a[i][j] = a[i-1][j];
                }
                
            }
           // cout<<a[i][j]<<" ";
        }
       // cout<<endl;
    }
    cout<<a[n][weight];
    return 0;
}