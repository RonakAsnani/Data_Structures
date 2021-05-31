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
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp  = temp->next;
    }
}
Node* del(Node* head,int pos){
    if(pos == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp = head;
    while(count<pos -1 && temp != NULL){
        temp = temp->next;
        count++;
    }
    Node* x = temp->next;
    temp->next= x->next;
    delete x;
    return head;
}

int main(){
    Node* head = takeInput();
    int pos;
    cin>>pos;
    print(head);
    cout<<endl;
    head = del(head,pos);
    print(head);
}