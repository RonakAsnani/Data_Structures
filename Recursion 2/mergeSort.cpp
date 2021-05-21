/*Coding Problem
Problem Statement: Merge Sort
Problem Level: MEDIUM
Problem Description:
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3

Sample Output 2 :
1 2 2 3 5*/


#include<iostream>
using namespace std;

void merge(int*a ,int n,int st,int en,int mid){
    
    int *b = new int[en - st +1];
    int i =st,j=mid+1;
    int k =0;
    while(i< mid +1 && j< en +1){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
            k++;
        }else {
            b[k] = a[j];
            k++;
            j++;
        }
        
    }
    while(i < mid+1){
        b[k] = a[i];
        k++;
        i++;
    }
    while(j < en +1){
        b[k] = a[j];
        k++;
        j++;
    }
    k =0;
    for(int q = st;q<=en;q++){
        a[q] = b[k];
        k++;
    }
    return;
    
}

void mergesort(int* a,int n,int st,int en){
    if(st >= en){
        return;
    }
    int mid = (st +en)/2;
    mergesort(a,n,st,mid);
    mergesort(a,n,mid+1,en);
    merge(a,n,st,en,mid);
   


}

int main(){
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,n,0,n-1);
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}