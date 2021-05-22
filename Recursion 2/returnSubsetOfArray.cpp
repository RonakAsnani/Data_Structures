/*Chapter Assignment
Problem Statement: Return subset of an array
Problem Level: HARD
Problem Description:
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Size of array
Line 2 : Array elements (separated by space)

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

///////////////////////   MINOR ERROR ////////////////////////////////

#include<iostream>
#include<cmath>
using namespace std;

int subset(int* a,int n,int** output){
    if(n ==0){
        output[0][0] = 0;
        return 1;
    }
    int small = subset(a+1,n-1,output);
    for(int i=0;i<small;i++){
        int size =output[i][0] +1;
        output[i+ small][0] = size;
        output[i+small][1] = a[0];
        for(int j=2;j<size+1;j++){
            output[i+small][j] = output[i][j-1];
        }
    }

    return small*2;
}

int main(){
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int size = pow(2,n);
    int** output = new int*[size];
    for(int i=0;i<n;i++){
        output[i] = new int[size];
    }
    int count = subset(a,n,output);
    for(int i=0;i<count;i++){
        for(int j=1;j<output[i][0];j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}