/*Problem Statement: Pair star
Problem Level: MEDIUM
Problem Description:
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
aaaa

Sample Output 2 :
a*a*a*a*/

#include<iostream>
#include<string>
using namespace std;

void con(string s,string& str){
    if(s.length() == 0 || s.length() == 1){
        str += s;
        return ;
    }
    str += s[0];
    if(s[0] == s[1]){
        str += '*';
    }
    con(s.substr(1),str);
}

int main(){
    string s;
    cin>>s;
    string x ="";
    con(s,x);
    cout<<x;
    return 0;
}