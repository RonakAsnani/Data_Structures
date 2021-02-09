#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[1000];
    for(int i=0;i<1000;i++){
        b[i] = -1;
    }
    for(int i=0;i<n;i++){
        if(a[i] > 0){
            b[a[i]] = a[i];
        }
    }
    for(int j=1;j<1000;j++){
        if(b[j] == -1){
            cout<<j;
            return 0;
        }
    }
}