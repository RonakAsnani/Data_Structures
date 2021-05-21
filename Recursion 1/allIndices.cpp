/*Problem Statement: All indexes of x
Problem Level: MEDIUM
Problem Description:
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
indexes where x is present in the array (separated by space)

Constraints :
1 <= N <= 10^3

Sample Input :
5
9 8 10 8 8
8

Sample Output :
1 3 4*/

#include<iostream>
using namespace std;

void find(int* a,int n,int x,int ans = 0){
    if(n ==0){

        return ;
    }
    if(a[0] == x){
        cout<<ans<<" ";

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