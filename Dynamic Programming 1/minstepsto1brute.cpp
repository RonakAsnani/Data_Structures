#include<bits/stdc++.h>
using namespace std;

int calc(int n){
    if(n ==1 || n==2  || n== 3){
        return 1;
    }
    return 1 + min(calc(n-1),min(calc(n-2),calc(n-3)));
}

int main(){
    int n;
    cin>>n;
    //int steps = 0;
    cout<<calc(n);
    return 0;
}