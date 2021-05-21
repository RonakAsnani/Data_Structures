/*Problem Statement: Replace pi (recursive)
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

Sample Input 3 :
pip

Sample Output :
3.14p*/

#include<iostream>
#include<string>
using namespace std;

string pi(string s){
    if(s.length() == 1 || s.length() == 0){
        return s;
    }
    if(s[0] == 'p' && s[1] == 'i'){
        s[0] = 3.;
        s[1] = 14;
        return "3.14" + pi(s.substr(2));
        
    }else{
        return s[0] + pi(s.substr(1));
    }

}

int main(){
    string s;
    cin>>s;
    cout<<pi(s);
    return 0;
}