#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;

    int n = s.length(),m = t.length();
    int** a = new int*[n+1];
    for(int i=0;i<=n;i++){
        a[i] = new int[m+1];
        for(int j=0;j<=m;j++){
            a[i][j] =0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
         
             
          
                if(s[i-1] == t[j-1]){
                    a[i][j] = 1 + a[i-1][j-1];
                }else{
                    a[i][j] = max(a[i-1][j],max(a[i-1][j-1],a[i][j-1]));
                }

        }
    }
    cout<<a[n][m];
    return 0;
}