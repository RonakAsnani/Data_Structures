#include<bits/stdc++.h>
using namespace std;

void printDFS(int** edges,int n,int sv,bool* visited){
    cout<< sv<<endl;
    visited[sv] = 1;
    for(int i=0;i<n;i++){
        if(edges[sv][i] == 1){
            if(sv == i){
                continue;
            }
            if(visited[i] == 1) continue;

            printDFS(edges,n,i,visited);
        }
    }
}

void printBFS(int** edges,int n,int sv,bool* &visited){

    visited[sv] = true;
    queue<int> q;
    q.push(sv);
    while(!q.empty()){
        int front = q.front();
        cout<<front<<endl;
        q.pop();
        visited[front] = true;
        for(int i=0;i<n;i++){
            if(edges[front][i] == 1 && visited[i] == 0){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
 void DFS(int** edges,int n){
     bool*visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            printDFS(edges,n,i,visited);
        }
    }
    delete [] visited;
 }

 void BFS(int**edges,int n){
     bool*visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
    }
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
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
    cout<<"BFS"<<endl;
    BFS(edges,n);
    cout<<"DFS"<<endl;
    DFS(edges,n);
    return 0;
}