/*Problem Statement: Return subsets sum to K
Problem Level: HARD
Problem Description:
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Constraints :
1 <= n <= 20

Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output :
3 3
5 1*/


#include<iostream>
using namespace std;

int sumSubset(int* a,int n,int** output,int s){
    if(n ==0){
        if(s ==0){
            output[0][0]  = 0;
            return 1;
        }else{
            return 0;
        }
    }
    int** out1 = new int*[100];
    int** out2 = new int*[100];
    for(int i=0;i<n;i++){
        out1[i] = new int[100];
        out2[i] = new int[100];
    }
    int s1 = sumSubset(a+1,n-1,out1,s-a[0]);
    int s2 = sumSubset(a+1,n-1,out2,s);
    int k =0;
    for(int i=0;i<s2;i++){
        for(int j=0;j<=out2[i][0];j++){
            output[k][j] = out2[i][j];
           
        }
         k++;
    }
    for(int i=0;i<s1;i++){
        output[k][0] = out1[i][0] +1;
            output[k][1] = a[0];
        for(int j=2;j<=out1[i][0]+1;j++){
            
    output[k][j] = out1[i][j-1];
        }
        k++;
    }
    return k;

}
 
int main(){
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int** output = new int*[100];
    for(int i=0;i<10;i++){
        output[i] = new int[100];
    }
    int count = sumSubset(a,n,output,k);
    for(int i=0;i<count;i++){
        for(int j=1;j<=output[i][0];j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    

    
    
    return 0;
}