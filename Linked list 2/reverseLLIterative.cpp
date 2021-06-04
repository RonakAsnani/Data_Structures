/*Problem Statement: Reverse LL (Iterative) 
Problem Level: EASY
Problem Description:
Given a linked list, reverse it iteratively.
You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.
`Input format : Linked list elements (separated by space and terminated by -1)``

Sample Input 1 :
1 2 3 4 5 -1

Sample Output 1 :
5 4 3 2 1*/

#include<iostream>
using namespace std;
#include "Node.cpp"

Node* takeInput()
{
    int data;
    cin>>data;
    Node* head = NULL;
    Node* prev =NULL;
    while(data != -1){
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            prev =n;
        }else{
        prev->next = n;
        prev = prev->next;
        }

        cin>>data;
    }
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}

Node* rever(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = curr->next;
    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr != NULL){
            next = next->next;
        }
    
    }
    return prev;
}

int main(){
    Node* head = takeInput();
    print(rever(head));
    return 0;
}