/*Problem Statement: Print all Codes - String
Problem Level: HARD
Problem Description:
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw*/

#include<iostream>
#include<string>
using namespace std;

void print(string s,string output){
    if(s.empty()){
        cout<<output<<endl;
        return;
    }
    int num = s[0] - 48;
    char ch = 'a' + num - 1 ;
    print(s.substr(1),output + ch);
    if(s.length() >= 2){
        int num1 = num*10 + (s[1] - 48);
        char ch1 = num1 -1 + 'a';
        if(num1 >= 10 && num1 <= 26){
            print(s.substr(2),(output + ch1));
        }

    }
    return ;
}

int main(){
    string s;
    cin>>s;
    string output ="";
    print(s,output);
    return 0;
}