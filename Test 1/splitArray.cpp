/*Problem Statement: Split Array
Problem Level: MEDIUM
Problem Description:
Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.

Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.
Note : You will get marks only if all the test cases are passed.
Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)

Output Format :
true or false

Constraints :
1 <= N <= 50

Sample Input 1 :
2
1 2

Sample Output 1 :
false

Sample Input 2 :
3
1 4 3

Sample Output 2 :
true*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void split(int *a,int n){
    int sum1 = 0,sum2 =0;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(a[i]%3 == 0 && a[i]%5 != 5){
            sum1 += a[i];
        }else if(a[i]%5 == 0){
            sum2 += a[i];
        }else{
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        if(sum1 > sum2){
            sum2 += v[i];
        }else{
            sum1 += v[i];
        }
    }
    if(sum1 == sum2){
        cout<<"true"<<endl;
        return;
    }else{
        cout<<"false"<<endl;
        return;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    int* a =new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    split(a,n);
    return 0;
}