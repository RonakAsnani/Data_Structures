/*Problem Statement: Does s contain t ?
Problem Level: EASY
Problem Description:
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = â€œabchjsgsuohhdhyrikkknddgâ€ contains all characters of t=â€codingâ€ in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
true or false

Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding

Sample Output 1 :
true

Sample Input 2 :
abcde
aeb

Sample Output 2 :
false*/

#include<iostream>
#include<string>
using namespace std;

void check(string s,string t){
    if(t.empty()){
        cout<<"true"<<endl;
        return;
    }
    if(s.empty()){
        cout<<"false"<<endl;
        return;
    }
    if(s[0] == t[0]){
        return check(s.substr(1),t.substr(1));
    }else{
        return check(s.substr(1),t);
    }
    return;

}

int main(){
    string s,t;
    cin>>s>>t;
    check(s,t);
    return 0;
}