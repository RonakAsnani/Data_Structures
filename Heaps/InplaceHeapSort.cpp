#include<bits/stdc++.h>
using namespace std;

void heapsort(int *a,int n){
    for(int i=1;i<n;i++){
        int index = i;
        while((index-1)/2 >=0 && a[index] < a[(index-1)/2]){
            swap(a[index],a[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    int size =n;
    while(size > 1){
    swap(a[0],a[size-1]);
    size--;

    int index = 0;
        int left = 2*index +1;
        int right = 2*index +2;
        while(left < size){
            int minIndex = index;
            if(a[minIndex] >  a[left]){
                minIndex = left;
            }
            if(right < size && a[right] < a[minIndex]){
                minIndex = right;
            }
            if(index == minIndex){
                break;
            }
            swap(a[minIndex],a[index]);

            index = minIndex;
             left = 2*index +1;
            right = 2*index +2;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    heapsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}