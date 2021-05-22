/////////////   PRINT SUBSEQUENCE   ///////////////////

#include<iostream>
#include<string>
using namespace std;

void subs(string s, string output){
    if(s.length() == 0){
        cout<<output<<endl;
        return ;
    }
    subs(s.substr(1),output + s[0]);
    subs(s.substr(1),output);


}

int main(){
    string s;
    cin>>s;
    string output ="";
    subs(s,output);
    return 0;
}