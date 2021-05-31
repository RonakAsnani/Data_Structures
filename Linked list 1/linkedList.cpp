#include<iostream>
using namespace std;
#include "Node.cpp"



void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}

int main(){
    // static
    
    Node n1(3);
    Node* head = &n1;
    Node n2(4);
    n1.next = &n2;
    Node n3(6);
    Node n4(7);
    Node n5(8);
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);
    // cout<<head->data<<" "<<head->next->data<<endl;  

    // dynamic
    // Node* n3 = new Node(10);
    // Node* n4 = new Node(12);
    // Node* head = n3;
    // n3->next = n4;        
    return 0;
}