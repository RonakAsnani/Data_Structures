#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* a = new int[n+1];
    a[0] =  0;
    a[1] =1;
    a[2] = 2;
    a[3] = 2;
    for(int i=4;i<=n;i++){
        int x = sqrt(i);
        int j =1;
        a[i] = INT_MAX;
        while(j<=x){
            a[i] = min(a[i],1+ a[i - j*j]);
            j++;
        }

    }
    cout<<a[n];
    return 0;
}