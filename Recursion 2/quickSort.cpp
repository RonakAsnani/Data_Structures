/*Problem Statement: Quick Sort
Problem Level: MEDIUM
Problem Description:
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.
<br>
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
1 5 2 7 3

Sample Output 2 :
1 2 3 5 7*/

#include<iostream>
using namespace std;

int partition(int* a,int st,int en){
    int pivot = a[st];
    int pivot_index = st;
    for(int i=st;i<=en;i++){
        if(a[i] < pivot){
            pivot_index++;
        }
    }
    // swapping

    a[st] = a[pivot_index];
    a[pivot_index] = pivot;

    int i = st, j = pivot_index+1;
    while(i<pivot_index && j<= en){
        if(a[j] <= pivot && a[i] > pivot ){
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i++;
            j++;
        }else if(a[j] <= pivot && a[i] < pivot ){
            i++;
        }else if(a[j] >= pivot && a[i] > pivot ){
            j++;
        }else {
            i++;
            j++;
        }
    }
    return pivot_index;
}

void quicksort(int* a,int n,int st,int en){
    if(st>=en){
        return;
    }
    int pivot = partition(a,st,en);
    quicksort(a,n,st,pivot-1);
    quicksort(a,n,pivot+1,en);
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,n,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}