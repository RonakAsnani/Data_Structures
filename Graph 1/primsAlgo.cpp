#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;

    int** a = new int*[n];
    for(int i=0;i<n;i++){
        a[i] = new int[n];
        for(int j=0;j<n;j++){
            a[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y] = z;
        a[y][x] = z;
    }
    bool* visited = new bool[n];
    int* weight = new int[n];
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
        weight[i] = INT_MAX;
        parent[i] = -1;
    }

    int st = 0;
    weight[st] = 0;

    while(st != -1){
        visited[st] = true;
        for(int i=0;i<n;i++){
            if(a[st][i] !=0 && visited[i] == 0){
                if(weight[i] > a[st][i]){
                    //cout<<"uibiu"<<endl;
                    weight[i] = a[st][i];
                    parent[i] = st;
                }
            }
        }
        int minIndex = -1;
        int minw = INT_MAX;
        for(int i=0;i<n;i++){
            if(minw > weight[i] && visited[i] == 0){
                minw = weight[i];
                minIndex = i;
            }
        }

    st = minIndex;
    //cout<<st<<endl;
    }

    for(int i=0;i<n;i++){
        if(parent[i] != -1){
            cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weight[i]<<endl;
        }
    }


    
    



    return 0;
}