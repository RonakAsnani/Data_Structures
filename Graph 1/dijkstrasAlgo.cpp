#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges[x][y] = z;
        edges[y][x]= z;
    }

    int st = 0;
    bool* visited = new bool[n];
    int* dist = new int[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
        dist[i] = INT_MAX;
    }
    dist[st] = 0;
    while(st != -1){
        visited[st] = 1;
        for(int i=0;i<n;i++){
            if(edges[st][i] != 0 && visited[i] == 0){
                if(dist[i] > dist[st] + edges[i][st]){
                    dist[i] = dist[st] + edges[i][st];
                }
            }
        }
        int next = -1;
        int nex = INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[i] == 0 && nex > dist[i]){
                nex = dist[i];
                next = i;
            }
        }

        st = next;
    }
    cout<<"ans"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;
}