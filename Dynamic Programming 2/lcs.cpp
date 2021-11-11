#include<bits/stdc++.h>
using namespace std;

int lcs(string s,string t){
    if(s.empty() || t.empty()){
        return 0;
    }

    if(s[0] == t[0]){
        return 1 + lcs(s.substr(1),t.substr(1));
    }else{
        int x,y,z;
        x = lcs(s.substr(1),t);
        y = lcs(s,t.substr(1));
        z = lcs(s.substr(1),t.substr(1));
        return max(x,max(y,z));
    }
}

int main(){
    string s,t;
    cin>>s>>t;

    cout<<lcs(s,t);
    return 0;
}