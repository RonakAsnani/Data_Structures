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

Node *eliminate(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        //Node*temp = head->next;
        if (temp->data == (temp->next)->data)
        {
            Node *dem = temp->next;
            temp->next = (temp->next)->next;
            delete[] dem;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    Node *head = takeinput();
    head = eliminate(head);
    print(head);
    return 0;
}