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

Node *deleteNode(Node *head, int i)
{
    int c = 0;
    Node *temp = head;
    if (i == 0)
    {

        head = temp->next;
        delete[] temp;
    }
    while (temp != NULL && c < i - 1)
    {
        temp = temp->next;
        c++;
    }
    if (temp != NULL)
    {
        Node *dem = temp->next;
        temp->next = (dem)->next;
        delete[] dem;
    }
    return head;
}

int main()
{
    Node *head = takeinput();
    print(head);
    head = deleteNode(head, 2);
    print(head);
    return 0;
}