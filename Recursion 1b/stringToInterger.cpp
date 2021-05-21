/*Problem Statement: String to Integer
Problem Level: MEDIUM
Problem Description:
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
1231

Sample Output 1 :
1231

Sample Input 2 :
12567

Sample Output 2 :
12567*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int convert(string s){

    int l = s.length();
    if(l ==0){
        return 0;
    }
    int x = s[0] - '0';
    return x*pow(10,l-1) + convert(s.substr(1));

}

int main(){
    string s;
    cin>>s;
    cout<<convert(s);
    return 0;
}