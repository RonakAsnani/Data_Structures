/*Problem Statement: Remove X
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.

Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc

Sample Input 3 :
xx

Sample Output 3:*/

#include<iostream>
#include<string>
using namespace std;

string removeX(string s){
    if(s.length() == 0){
        return "";
    }
    if(s[0] == 'x'){
        return removeX(s.substr(1));
    }
    return s[0] + removeX(s.substr(1));
}

int main(){
    string s;
    cin>>s;
    cout<<removeX(s);
    return 0;
}