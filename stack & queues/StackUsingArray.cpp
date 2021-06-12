#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
    int* data;
    int nextIndex;
    int total;
    public: 
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex =0;
        total = totalSize;
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(int element){
        if(nextIndex == total){
            cout<<"Stack full"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int pop(){
        if(nextIndex == 0){
            cout<<"stack empty"<<endl;
            return INT_MAX;
        }
        nextIndex--;
        return  data[nextIndex];

    }
    int top(){
        if(nextIndex == 0){
            cout<<"stack empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex -1];
    }
};