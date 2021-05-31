/*Problem Level: EASY
Problem Description:
Given a linked list, find and return the length of input LL recursively.
Input format :
Linked list elements (separated by space and terminated by -1)

Output format :
Length of LL

Sample Input :
3 4 5 2 6 1 9 -1

Sample Output :
7*/

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
        }
        prev->next = n;
        prev = prev->next;
        

        cin>>data;
    }
    return head;
}

int print(Node* head,int l){
    if(head == NULL){
        return l;
    }
    head = head->next;
    l++;
    return print(head,l);
}

int main(){
    Node* head = takeInput();
    cout<<print(head,0);
    return 0;
}