#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
    int* data;
    int nextIndex;
    int total;
    public: 
    StackUsingArray(){
        data = new int[4];
        nextIndex =0;
        total = 4;
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(int element){ 
        if(nextIndex == total){
            int *nedata = new int[2*total];
            for(int i=0;i<total;i++){
                nedata[i] = data[i];
            }
            total = 2*total;
            delete [] data;
            data = nedata;
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