#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int d1,d2;
    int m = INT_MIN;
    int counter =0;
    for(int i=0;i<n;i++){
        d1 = a[i] - a[i+1];
        d2 = a[i+1] - a[i+2];
        if(d1 == d2){
            counter++;
            m = max(counter,m);
        }
        if(d1 != d2){
            counter =0;
        }
    }
    cout<<m+2;
    return 0;
}