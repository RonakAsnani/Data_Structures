#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    
    T data;
    Node<T>* next;
    Node(T d){
        data = d;
        next = NULL;
    }
};
template <typename T>
class StackUsingLL{
    Node<T>* head;
    int total;
    public:
    StackUsingLL(){
        head = NULL;
        total = 0;
    }

    int size(){
        return total;
    }
    bool isEmpty(){
        return total == 0;
    }
    void push(T data){
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        total++;
    }
    T top(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
    T pop(){
        if(isEmpty()){
            return 0;
        }
        T ans = head->data;
        Node<T>* temp = head;
        head= head->next;
        total--;
        delete temp;
        return ans;
    }

}; 