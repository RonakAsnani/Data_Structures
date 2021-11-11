#include<bits/stdc++.h>
using namespace std;

long long calc(int** a,int i,int j,int n,int m){
    if(i == n-1 && j == m-1){
        return a[i][j];
    }
    // if(i < 0 || j< 0 || i >n || j > m){
    //     return INT_MAX;
    // }
    int x = INT_MAX,y = INT_MAX, z = INT_MAX;
    if(i+1 < n){
        x = calc(a,i+1,j,n,m);
    }
    if(j+1 < m){
        y = calc(a,i,j+1,n,m);
    }
    if(i+1 < n && j+1 < m){
        z = calc(a,i+1,j+1,n,m);
    }
    int t = min(x,min(y,z));
    // if(t == INT_MAX){
    //     return INT_MAX;
    // }
    return a[i][j] + min(x,min(y,z));
}

int main(){
    int n,m;
    cin>>n>>m;
    int** a = new int*[n];
    for(int i=0;i<n;i++){
        a[i] = new int[m];
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    cout<<calc(a,0,0,n,m);

    return 0;
}