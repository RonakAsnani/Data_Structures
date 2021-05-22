/*Problem Statement: Binary Search (Recursive)
Problem Level: EASY
Problem Description:
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :
Line 1 : Array size
Line 2 : Array elements (separated by space)
Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5

Sample Output:
3
*/

#include<iostream>
using namespace std;

int binary(int* a,int st,int en,int x){
    int mid = (st + en)/2;
    if(x == a[mid]){
        return mid;
    }
    if(x > a[mid]){
       return  binary(a,mid+1,en,x);
    }else{
        return binary(a,st,mid-1,x);
    }
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
    cout<<binary(a,0,n-1,x);
    return 0;
}