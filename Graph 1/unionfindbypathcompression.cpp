#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int parent;
    int rank;
};

vector<node> dsuf;

int find(int v){
    if(dsuf[v].parent == v){
        return v;
    }
    return dsuf[v].parent = find(dsuf[v].parent);
}

void union_op(int fromP,int toP){
    if(dsuf[fromP].rank > dsuf[toP].rank){
        dsuf[toP].parent = fromP;
    }else if(dsuf[fromP].rank < dsuf[toP].rank){
        dsuf[fromP].parent = toP;
    }else{
        dsuf[fromP].parent = toP;
        dsuf[toP].rank++ ;
    }
}


bool isCyclic(vector<pair<int,int>> &edge_list){
    for(int i=0;i<edge_list.size();i++){
        int fromP = find(edge_list[i].first);
        int toP = find(edge_list[i].second);

        if(fromP == toP){
            return true;
        }
        union_op(fromP,toP);
    }
    return false;
}


int main(){
    int v,e;
    cin>>v>>e;

    dsuf.resize(v);
    for(int i=0;i<v;i++){
        dsuf[i].parent = i;
        dsuf[i].rank = 0;
    }

    vector<pair<int,int>> edge_list;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        edge_list.push_back({x,y});
    }

    if(isCyclic(edge_list)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
      
    return 0;
}