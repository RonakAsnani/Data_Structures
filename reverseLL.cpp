#include <bits/stdc++.h>
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

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *small = reverseLL(head->next);

    Node *temp = small;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    return small;
}

int main()
{
    Node *head = takeinput();
    head = reverseLL(head);
    print(head);
    return 0;
}