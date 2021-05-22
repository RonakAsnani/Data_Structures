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
    int size = 0;
    int small = codes(s.substr(1),output);
    for(int i=0;i<small;i++){
        output[i] = ch + output[i];
    }
    size += small;
    if(s.length() >= 2){
             int num1 = s[1] - 48;
    int x = num*10 + num1;
    char ch1 = 'a' + x -1;
    string* newout = new string[100];
    if(x>=10 && x<= 26){
        string* newout = new string[100];
        int small1 = codes(s.substr(2),newout);
        for(int i=0;i<small1;i++){
            output[small +i] = ch1 + newout[i];
        }
        size += small1;
    }
    }
   
    return size;


}

int main(){
    string s;
    cin>>s;
    string* output = new string[100];
    int count = codes(s,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}