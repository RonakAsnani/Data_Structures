#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

Node* kreverse(Node*head,int n){
    int curr =0;
    Node*temp = head;
    Node*tail = head;
    while(temp != NULL){
        if(curr%n == 0){
            int pos =1;
            while(pos<n){
                tail =tail->next;
                n++;
            }
            reverse(temp,)
        }
    }
}

int main(){
    Node*head = takeinput();
    int k;
    cin>>k;
    head = kreverse(head,k);
    return 0;
}