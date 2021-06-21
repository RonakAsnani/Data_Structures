#include<iostream>
#include<climits>
using namespace std;
template <typename T>
class StackUsingArray{
    T* data;
    int nextIndex;
    int total;
    public: 
    StackUsingArray(){
        data = new T[4];
        nextIndex =0;
        total = 4;
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(T element){ 
        if(nextIndex == total){
            T *nedata = new T[2*total];
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
    T pop(){
        if(nextIndex == 0){
            cout<<"stack empty"<<endl;
            return 0;
        } 
        nextIndex--;
        return  data[nextIndex];

    }
    T top(){
        if(nextIndex == 0){
            cout<<"stack empty"<<endl;
            return 0;
        }
        return data[nextIndex -1];
    }
};