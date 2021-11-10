#include<bits/stdc++.h>
using namespace std;

bool find(int** edges,int n,int st,int en,bool* &visited){
    if(st == en){
        return true;
    }
    visited[st]= true;
    bool ans = false;
    for(int i=0;i<n;i++){
        if(edges[st][i] == 1 && visited[i] == 0){
            ans = ans || find(edges,n,i,en,visited);
        }
    }
    return ans;
}

int main(){
    int n;
    int e;
    cin>>n>>e;

    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

     int st,en;
     cin>>st>>en;
    bool* visited = new bool[n];
    cout<<find(edges,n,st,en,visited);
    return 0;
}