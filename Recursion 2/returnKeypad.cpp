/*Problem Statement: Return Keypad - String
Problem Level: HARD
Problem Description:
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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
    string str[]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return str[n];
}

int keypad(int n, string*  output){
    if(n == 0 ){
        output[0] ="";
        return 1;
    }
    int small = keypad(n/10,output);
    string x = keyvalue(n%10 -2);

    for(int i=0;i<small*x.length();i++){
        output[small + i] = output[i%small];
    }
    int i=0;
    for(int j=0;j<x.length();j++)
    {
        for(;i<small*(j+1);i++)
            output[i]=output[i]+x[j];
    }
    return small*x.length();

}

int main(){
    int n;
    cin>>n;
    string* output = new string[1000];
    int count = keypad(n,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}