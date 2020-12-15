
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
    int ans;
    for(int i=0;i<n;i++){
        m = max(m,a[i]);
        cout<<m<<" ";
    }
    return 0;
}