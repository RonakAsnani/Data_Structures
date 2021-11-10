#include<bits/stdc++.h>
using namespace std;

vector<int> find(int** edges,int n,int st,int en,bool* &visited,vector<int> ans){
    if(st == en){
        ans.push_back(st);
        return ans;
    }
    visited[st]= true;
    ans.push_back(st);
    vector<int> v;
    for(int i=0;i<n;i++){
        if(edges[st][i] == 1 && visited[i] == 0){
            
            vector<int> x = find(edges,n,i,en,visited,ans);
            if(v.empty() || x.size() < v.size()){
                v = x;
            }
        }
    }
    
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

     int st,en;
     cin>>st>>en;
    bool* visited = new bool[n];
    vector<int> ans;
    ans = find(edges,n,st,en,visited,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}