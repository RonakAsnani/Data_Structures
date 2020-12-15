#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m = INT_MIN;
    for(int i=0;i<n;i++){
        
        if(i<n-1){
            if(a[i] > a[i+1] && a[i] > m){
            cout<<i<<" ";
        }
        }
        else if(i == n-1){
            if(a[i] > m){
            cout<<i<<" ";
        }
        }
        
        m = max(a[i],m);
    }
    
    return 0;
}