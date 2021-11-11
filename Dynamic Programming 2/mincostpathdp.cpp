#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int** a = new int*[n];
    int** b = new int*[n];
    for(int i=0;i<n;i++){
        b[i] = new int[m];
    }
    for(int i=0;i<n;i++){
 
        a[i] = new int[m];
        for(int j=0;j<m;j++){
     
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0){
                b[i][j] = a[i][j];
            }else{
                int x= 999999, y=999999, z= 999999;
                if(i-1 >= 0){
                    x = b[i-1][j];

                }
                if(j-1>=0){
                    y = b[i][j-1];
                }
                if(i-1 >= 0 && j-1 >= 0){
                    z = b[i-1][j-1];
                }
                b[i][j] = a[i][j] + min(x,min(y,z));
            }
            
        }
    }
    cout<<b[n-1][m-1];
    return 0;
}