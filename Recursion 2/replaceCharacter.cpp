/*Problem Statement: Replace character recursively
Problem Level: EASY
Problem Description:
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)

Output Format :
Updated string

Constraints :
1 <= Length of String S <= 10^6

Sample Input :
abacd
a x

Sample Output :
xbxcd*/

#include<iostream>
#include<string>
using namespace std;

string update(string s,char c1, char c2){
    if(s.length() == 0){
        return s;
    }
    if(s[0] == c1){
        s[0] = c2;
    }
    return s[0] + update(s.substr(1),c1,c2);
    
}


int main(){
    string s;
    char c1,c2;
    cin>>s;
    cin>>c1>>c2;
    cout<<update(s,c1,c2);

    return 0;
}