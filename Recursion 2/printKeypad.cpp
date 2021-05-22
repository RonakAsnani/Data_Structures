/*Problem Statement: Print Keypad - String
Problem Level: HARD
Problem Description:
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf*/

#include<iostream>
#include<string>
using namespace std;

string keyvalue(int n){
    string str[]= {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return str[n];
}

void keypad(int n,string output){
    if(n ==0){
        cout<<output<<endl;
        return;
    }
    string x = keyvalue(n%10);
    for(int i=0;i<x.length();i++){
        keypad(n/10,output + x[i]);
    }
}

int main(){
    int n;
    cin>>n;
    string output = "";
    keypad(n,output);
    return 0;
}