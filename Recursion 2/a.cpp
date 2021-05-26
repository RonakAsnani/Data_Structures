#include<iostream>
#include<string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include<unordered_map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        unordered_map<string,int> m;
        int type;
        cin>>type;
        if(type == 1){
            string s;
            cin>>s;
            int marks;
            cin>>marks;
            m[s] = marks;
            continue;
        
        }else 
        if(type == 2){
            string s2;
            cin>>s2;
            m[s2] = 0;
            continue;
                
        }else 
        if(type == 3){
            string s3;
            cin>>s3;
            cout<<m["Jess"]<<endl;
            continue;
        }
        
    } 
    return 0;
}