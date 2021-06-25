#include<iostream>
using namespace std;

template <typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    QueueUsingArray(int s) {
        data = new T[s];
        nextIndex = 0;
        firstIndex  = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T element){
        if(size == capacity){
            T *newData = new T[2*capacity];
            int j =0;
            for(int i=firstIndex;i<capacity;i++){
                newData[j] = data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++){
                newData[j] = data[i];
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;

    }
     T front(){
         if(firstIndex == -1){
             cout<<"Queue is empty"<<endl; 
             return 0;
         }
         return data[firstIndex];
     }
     T dequeue(){
         if(size == 0){
             cout<<"queue is empty"<<endl;
         }
         T ans = data[firstIndex];
         firstIndex = (firstIndex+1)%capacity;
         
         size--;
         if(size == 0){
             firstIndex == -1;
             nextIndex =0;
         }
         return ans;
     }
};