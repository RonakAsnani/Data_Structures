/*Problem Statement: Return all codes - String
Problem Level: HARD
Problem Description:
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string

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

int codes(string s,string* output){
    if(s.empty()){
        output[0] ="";
        return 1;
    }
    int num = s[0] - 48;
    char ch = 'a' + num -1;
    if(s.length() == 1){
        output[0] = s[0] - '0' + 'a' -1;
        return 1;
    }
    int x = codes(s.substr(2),output);

    if((s[0] - '0')*10 + (s[1] - '0') <=26 ){
        
    }

}

int main(){
    string s;
    cin>>s;
    string* output = new string[];
    int count = codes(s,output);
    for(int i=0;i<count;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}