#include<bits/stdc++.h>
using namespace std;

vector<int> find(int** edges,int n,int st,int en,bool* &visited){
    visited[st] = 1;
    queue<int> q;
    q.push(st);
    int ans = -1;
    unordered_map<int,int> m;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(front == en){
            ans = en;
            break;
        }
        for(int i=0;i<n;i++){
            if(edges[front][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                m[i] = front;
                q.push(i);
            }
        }
    }
    vector<int> v;
    if(ans == -1){
        return v;
    }
    while(ans != st){
        v.push_back(ans);
        ans = m[ans];
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

     int st,en;
     cin>>st>>en;
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){{
        visited[i] = 0;
    }}
    vector<int> ans;
    ans = find(edges,n,st,en,visited);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
} 