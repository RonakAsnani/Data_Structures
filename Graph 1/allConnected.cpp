#include<bits/stdc++.h>
using namespace std;

vector<int> find(int** edges,int n,int st,bool* &visited){
    visited[st] = 1;
    vector<int> v;
    
    for(int i=0;i<n;i++){
        if(edges[st][i] == 1 && visited[i] == 0){
            vector<int> x = find(edges,n,i,visited);
            if(!x.empty()) v =x;
        }
    }
    v.push_back(st);
    return v;
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
    for(int i =0;i<n;i++){
       visited[i] = 0;
    }
    vector<vector<int>> ans;
    for(int i =0;i<n;i++){
        if(visited[i] == 0){
            vector<int> x =find(edges,n,i,visited);
            
            ans.push_back(x);
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}