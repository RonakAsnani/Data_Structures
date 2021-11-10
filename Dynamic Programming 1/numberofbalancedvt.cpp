#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
    int n;
    cin>>n;
    int* a = new int[n+1];
    a[0] = 0;
    a[1] = 1;
    a[2] = 3;
    for(int i=3;i<=n;i++){
        a[i] = ((a[i-1]*a[i-1])%mod + (2*a[i-1]*a[i-2])%mod)%mod; 
    }
    cout<<a[n];
    return 0;
}