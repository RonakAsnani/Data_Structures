#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s1;
    int x;
    cin>>x;
    for(int i=0;i<x;i++){
        int t;
        cin>>t;
        s1.push(t);
    }

    
    stack<int> s2;
    for(int i=0;i<x;i++){
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t = s2.top();
        s2.pop();
        
        while(!s2.empty()){
            s1.push(s2.top());
                s2.pop();
        }
        s1.push(t);
        
    }
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    return 0;
}