/*Problem Statement: Check Palindrome (recursive)
Problem Level: MEDIUM
Problem Description:
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar

Sample Output 1:
true

Sample Input 2 :
ninja

Sample Output 2:
false*/

#include<iostream>
#include<string>
using namespace std;
bool check(string s){
    
    int l = s.length();
    if(l == 1 || l ==0){
        return true;
    }
    if(s[0] == s[l-1]){
        return check(s.substr(1,l-2));
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    cout<<check(s);
    return 0;
}