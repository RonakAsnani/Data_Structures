#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* a = new int[n+1];
    a[0] = 0;
    a[1] =1;
    a[2] = 1;
    a[3] = 1;
    for(int i=4;i<=n;i++){
        a[i] = 1 + min(a[i-1],min(a[i-2],a[i-3]));
    }
    cout<<a[n];
    return 0;
}