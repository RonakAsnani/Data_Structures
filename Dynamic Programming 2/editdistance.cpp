#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int a = s1.length(),b = s2.length();
    int** arr = new int*[a+1];
    for(int i=0;i<=a;i++){
        arr[i] = new int[b+1];
    }
    for(int i=0;i<=a;i++){
        arr[i][0] = i;
    }
    for(int i=0;i<=b;i++){
        arr[0][i] == i;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            int x = INT_MAX,y= INT_MAX,z= INT_MAX;
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = arr[i-1][j-1];
            }else{
                arr[i][j] = 1 + min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1]));
            }
        }
    }
    cout<<arr[a][b];
    return 0;
}