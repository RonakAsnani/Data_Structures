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

Node *swapLL(Node *head, int i, int j)
{

    Node *temp = head;
    Node *prev = NULL,
         *node1 = NULL,
         *node1prev = NULL,
         *node2 = NULL,
         *node2prev = NULL;
    int pos = 0;
    while (temp != NULL)
    {
        if (pos == i)
        {
            node1 = temp;
            node1prev = prev;
        }
        else if (pos == j)
        {
            node2 = temp;
            node2prev = prev;
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }
    if (node1prev != NULL)
    {
        node1prev->next = node2;
    }
    else
    {
        head = node2;
    }
    if (node2prev != NULL)
    {
        node2prev->next = node1;
    }
    else
    {
        head = node1;
    }
    Node *temp1 = node2->next;
    node2->next = node1->next;
    node1->next = temp1;

    return head;
}

int main()
{
    Node *head = takeinput();
    int i, j;
    cin >> i >> j;
    head = swapLL(head, i, j);
    print(head);
    return 0;
}