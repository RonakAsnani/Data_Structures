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

Node *eveodd(Node *head)
{
    Node *even = NULL, *odd = NULL, *et = NULL, *ot = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 != 0)
        {
            if (odd == NULL)
            {
                odd = curr;
                ot = curr;
            }
            else
            {
                ot->next = curr;
                ot = curr;
            }
        }
        else
        {
            if (even == NULL)
            {
                even = curr;
                et = curr;
            }
            else
            {
                et->next = curr;
                et = curr;
            }
        }
        curr = curr->next;
    }
    if (odd == NULL)
    {
        return even;
    }
    else
    {
        if (even != NULL)
        {
            ot->next = even;
            et->next = NULL;
            return odd;
        }
        else
        {
            return odd;
        }
    }
    return odd;
}

int main()
{
    Node *head = takeinput();
    head = eveodd(head);
    print(head);
    return 0;
}