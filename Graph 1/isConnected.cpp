#include<bits/stdc++.h>
using namespace std;

bool find(int** edges,int n,bool* &visited){
    int st = 0;
    queue<int> q; 
    q.push(st);
    visited[st] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(int i=0;i<n;i++){

            if(edges[front][i] == 1 && visited[i] == 0){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        //cout<<i<<" "<<visited[i]<<endl;
        if(visited[i] == 0){
            //cout<<i<<endl;
            return false;
        }
    }
    return true;
    
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

    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    bool ans = false;
    ans = find(edges,n,visited);
    cout<<ans<<endl;
    return 0;
}