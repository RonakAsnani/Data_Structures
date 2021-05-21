/*Problem Statement: First Index
Problem Level: EASY
Problem Description:
Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
first index or -1

Constraints :
1 <= N <= 10^3

Sample Input :
4
9 8 10 8
8

Sample Output :
1
*/
#include<iostream>
using namespace std;

void find(int* a,int n,int x,int ans = 0){
    if(n ==0){
        return ;
    }
    if(a[0] == x){
        cout<<ans<<endl;
        return;
    }
    ans++;
    return find(a+1,n-1,x,ans);

}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    int ans = 0;
find(a,n,x,ans);
    return 0;
}