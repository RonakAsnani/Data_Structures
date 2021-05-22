/*Problem Statement: Print Subset Sum to K
Problem Level: HARD
Problem Description:
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:
3 3
5 1*/

#include<iostream>
using namespace std;

void print(int* a,int n,int*output,int m,int s){
    if(n == 0){
        if(s ==0){
            for(int i=0;i<m;i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
            return;
        }else{
            return;
        }
    }

    print(a+1,n-1,output,m,s);
    int* newout = new int[m+1];
    for(int i=0;i<m;i++){
        newout[i] = output[i];
    }
    newout[m] = a[0];
    print(a+1,n-1,newout,m+1,s-a[0]);
    return;
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s ;
    cin>>s;
    int* output = new int[0];
    int m=0;
    print(a,n,output,m,s);
    return 0;
}