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

int length(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return 0;
    }
    int small = length((head->next));
    return 1 + small;
}

int main()
{
    Node *head = takeinput();
    int h = length(head);
    cout << h;
    return 0;
}