/*
Chapter Assignment
Problem Statement: Print Subsets of Array
Problem Level: HARD
Problem Description:
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12*/

#include<iostream>
using namespace std;

void print(int * a,int st,int en,int* output,int m){
    if(st > en){
        for(int i=0;i<m;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int x = a[st];
    int* newout = new int[m+1];
    
    for(int i=0;i<m;i++){
        newout[i] = output[i];
    }
    newout[m] = x;
    print(a,st+1,en,output,m);
    print(a,st+1,en,newout,m+1);
    return;
}


int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int*output = new int[1];
    int m =0;
    print(a,0,n-1,output,m);
    return 0;
}