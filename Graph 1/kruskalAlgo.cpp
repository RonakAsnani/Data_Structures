#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int weight;
    int source;
    int dest;
};

bool comp(Edge &e1,Edge &e2){
    return e1.weight < e2.weight;
}

int par(int x,int* parent){
    while(x != parent[x]){
        x = parent[x];
    }
    return x;
}

int main(){
    int n,e;
    cin>>n>>e;
    Edge* input = new Edge[e];
    for(int i=0;i<e;i++){
        int x,y,z;
        cin>>x>>y>>z;
        input[i].weight =z;
        input[i].source = x;
        input[i].dest = y;
    }

    sort(input,input+e,comp);

    int count = 0;
    int i=0;
    int* parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    while(count < n-1){
        Edge curr = input[i];
        i++;
        int x = curr.source;
       int y = curr.dest;
       int p1 = par(x,parent);
       int p2 = par(y,parent);
       if(p1 != p2){
           edges[x][y] = curr.weight;
           edges[y][x] = curr.weight;
           cout<<x<<" "<<y<<" "<<curr.weight<<endl;
           parent[x] = min(p1,p2);
           parent[y] = min(p1,p2);
           count++;
       } 
    }


    return 0;
}