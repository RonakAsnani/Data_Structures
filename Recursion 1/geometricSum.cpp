/*Chapter Assignment
Problem Statement: Geometric Sum
Problem Level: MEDIUM
Problem Description:
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

using recursion.
Input format :
Integer k

Output format :
Geometric sum

Constraints :
0 <= k <= 1000

Sample Input 1 :
3

Sample Output 1 :
1.875

Sample Input 2 :
4

Sample Output 2 :
1.93750
*/

#include<iostream>
using namespace std;

double power(double x,double n){
    if(n ==1){
        return x;
    }
    return x*power(x,n-1);
}

double sum(double k){
    if(k == 0){
        return 1;
    }
    double x = power(0.5,k);

    return x + sum(k-1);
}

int main(){
    double k;
    cin>>k;
    cout<<sum(k);
    return 0;
}