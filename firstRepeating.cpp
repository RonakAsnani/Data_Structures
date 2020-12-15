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
        if(b[a[i]] == -1){
            b[a[i]] = i;
        }
        else if(b[a[i]] != -1){
            cout<<b[a[i]];
            return 0;
        }
    }

}