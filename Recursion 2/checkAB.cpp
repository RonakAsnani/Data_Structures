/*Problem Statement: Check AB
Problem Level: MEDIUM
Problem Description:
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S

Output format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
abb

Sample Output 1 :
true

Sample Input 2 :
abababa

Sample Output 2 :
false*/

#include<iostream>
#include<string>
using namespace std;

bool  check(string s){
    if(s.length() ==1 || s.length() == 0){
        return true;
    }
    if(s[1] == 'b' && s.length() == 2){
        return false;
    }
    if(s.length()>= 3 && s[0] == 'a' && s[1] == 'b' && s[2] == 'a'){
        return false;
    }
    return check(s.substr(1));
    

}

int main(){
    string s;
    cin>>s;
    if(s[0] != 'a'){
        cout<<false;
        return 0;
    } 
    cout<<check(s);
    return 0;
}