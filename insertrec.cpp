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

Node *insert(Node *head, int i, int data)
{
    //Node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    if (i == 0)
    {
        Node *ne = new Node(data);
        ne->next = head;
        return ne;
    }
    if (i == 1)
    {
        Node *ne = new Node(data);
        ne->next = head->next;
        head->next = ne;
        return ne;
    }
    Node *curr = insert(head->next, i - 1, data);

    return head;
}

int main()
{
    Node *head = takeinput();
    head = insert(head, 2, 99);
    print(head);
    return 0;
}