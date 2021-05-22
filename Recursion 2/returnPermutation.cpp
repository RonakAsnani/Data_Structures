/*Problem Statement: Return Permutations - String
Problem Level: HARD
Problem Description:
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba*/

#include<iostream>
#include<string>
using namespace std;

int permu(string s,string* output){
    if(s.empty()){
        output[0] = "";
        return 1;
    }
    int k =0;
    for(int i=0;i<s.length();i++){
        string* newout = new string[100];
    string str = s.substr(0,i) + s.substr(i+1,s.length() - i -1);
        int small = permu(str,newout);
   
        for(int j=0;j<small;j++){
            output[k] = s[i] + newout[j];
            k++;
        }
        delete []newout;

    }
    return k;
    
}

int main(){
    string s;
    cin>>s;
    string* output = new string[100];
    int count = permu(s,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}