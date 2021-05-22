/////////////  RETURN SUBSEQUENCES OF A STRING  ////////////////////////


#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int subs(string input, string* output){
    if(input.length() == 0){
        output[0] ="";
        return 1;
    }
    int x = subs(input.substr(1),output);
    for(int i=0;i<x;i++){
        output[x + i] = input[0] + output[i];
    }
    return 2*x;
}


int main(){
    string s;
    cin>>s;
    int size = pow(2,s.length());
    string* output = new string[size];
    int count = subs(s, output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}